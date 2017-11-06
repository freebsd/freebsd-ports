// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/logging.h"
#include "base/time/time.h"
#include "base/time/default_tick_clock.h"
#include "media/audio/audio_manager_base.h"
#include "media/base/audio_timestamp_helper.h"
#include "media/audio/sndio/sndio_output.h"

namespace media {

void sndio_onmove(void *arg, int delta) {
  SndioAudioOutputStream* self = static_cast<SndioAudioOutputStream*>(arg);

  self->hw_delay = delta;
}

void sndio_onvol(void *arg, unsigned int vol) {
  SndioAudioOutputStream* self = static_cast<SndioAudioOutputStream*>(arg);

  self->vol = vol;
}

void *sndio_threadstart(void *arg) {
  SndioAudioOutputStream* self = static_cast<SndioAudioOutputStream*>(arg);

  self->RealTimeThread();
  return NULL;
}

SndioAudioOutputStream::SndioAudioOutputStream(const AudioParameters& params,
                                               AudioManagerBase* manager)
    : manager(manager),
      params(params),
      audio_bus(AudioBus::Create(params)),
      bytes_per_frame(params.GetBytesPerFrame()),
      state(kClosed),
      mutex(PTHREAD_MUTEX_INITIALIZER) {
}

SndioAudioOutputStream::~SndioAudioOutputStream() {
  if (state != kClosed)
    Close();
}

bool SndioAudioOutputStream::Open() {
  struct sio_par par;
  int sig;

  if (params.format() != AudioParameters::AUDIO_PCM_LINEAR &&
      params.format() != AudioParameters::AUDIO_PCM_LOW_LATENCY) {
    LOG(WARNING) << "Unsupported audio format.";
    return false;
  }
  sio_initpar(&par);
  par.rate = params.sample_rate();
  par.pchan = params.channels();
  par.bits = params.bits_per_sample();
  par.bps = par.bits / 8;
  par.sig = sig = par.bits != 8 ? 1 : 0;
  par.le = SIO_LE_NATIVE;
  par.appbufsz = params.frames_per_buffer();

  hdl = sio_open(SIO_DEVANY, SIO_PLAY, 0);
  if (hdl == NULL) {
    LOG(ERROR) << "Couldn't open audio device.";
    return false;
  }
  if (!sio_setpar(hdl, &par) || !sio_getpar(hdl, &par)) {
    LOG(ERROR) << "Couldn't set audio parameters.";
    goto bad_close;
  }
  if (par.rate  != (unsigned int)params.sample_rate() ||
      par.pchan != (unsigned int)params.channels() ||
      par.bits  != (unsigned int)params.bits_per_sample() ||
      par.sig   != (unsigned int)sig ||
      (par.bps > 1 && par.le != SIO_LE_NATIVE) ||
      (par.bits != par.bps * 8)) {
    LOG(ERROR) << "Unsupported audio parameters.";
    goto bad_close;
  }
  state = kStopped;
  volpending = 0;
  vol = 0;
  buffer = new char[audio_bus->frames() * params.GetBytesPerFrame()];
  sio_onmove(hdl, sndio_onmove, this);
  sio_onvol(hdl, sndio_onvol, this);
  return true;
 bad_close:
  sio_close(hdl);
  return false;
}

void SndioAudioOutputStream::Close() {
  if (state == kClosed)
    return;
  if (state == kRunning)
    Stop();
  state = kClosed;
  delete [] buffer;
  sio_close(hdl);
  manager->ReleaseOutputStream(this);  // Calls the destructor
}

void SndioAudioOutputStream::Start(AudioSourceCallback* callback) {
  state = kRunning;
  hw_delay = 0;
  source = callback;
  sio_start(hdl);
  if (pthread_create(&thread, NULL, sndio_threadstart, this) != 0) {
    LOG(ERROR) << "Failed to create real-time thread.";
    sio_stop(hdl);
    state = kStopped;
  }
}

void SndioAudioOutputStream::Stop() {
  if (state == kStopped)
    return;
  state = kStopWait;
  pthread_join(thread, NULL);
  sio_stop(hdl);
  state = kStopped;
}

void SndioAudioOutputStream::SetVolume(double v) {
  pthread_mutex_lock(&mutex);
  vol = v * SIO_MAXVOL;
  volpending = 1;
  pthread_mutex_unlock(&mutex);
}

void SndioAudioOutputStream::GetVolume(double* v) {
  pthread_mutex_lock(&mutex);
  *v = vol * (1. / SIO_MAXVOL);
  pthread_mutex_unlock(&mutex);
}

void SndioAudioOutputStream::RealTimeThread(void) {
  int avail, count;

  while (state == kRunning) {
    // Update volume if needed
    pthread_mutex_lock(&mutex);
    if (volpending) {
      volpending = 0;
      sio_setvol(hdl, vol);
    }
    pthread_mutex_unlock(&mutex);

    // Get data to play
    const base::TimeDelta delay = AudioTimestampHelper::FramesToTime(hw_delay, params.sample_rate() * 1000);
    count = source->OnMoreData(delay, base::TimeTicks::Now(), 0, audio_bus.get());
    audio_bus->ToInterleaved(count, params.bits_per_sample() / 8, buffer);
    if (count == 0) {
      // We have to submit something to the device
      count = audio_bus->frames();
      memset(buffer, 0, count * params.GetBytesPerFrame());
      LOG(WARNING) << "No data to play, running empty cycle.";
    }

    // Submit data to the device
    avail = count * params.GetBytesPerFrame();
    count = sio_write(hdl, buffer, avail);
    if (count == 0) {
      LOG(WARNING) << "Audio device disconnected.";
      break;
    }

    // Update hardware pointer
    hw_delay += count;
  }
}

}  // namespace media
