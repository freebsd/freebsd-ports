// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/audio/sndio/sndio_input.h"

#include <stddef.h>

#include "base/bind.h"
#include "base/logging.h"
#include "base/macros.h"
#include "base/message_loop/message_loop.h"
#include "media/audio/openbsd/audio_manager_openbsd.h"
#include "media/audio/audio_manager.h"

namespace media {

static const SampleFormat kSampleFormat = kSampleFormatS16;

void sndio_in_onmove(void *arg, int delta) {
  NOTIMPLEMENTED();
  SndioAudioInputStream* self = static_cast<SndioAudioInputStream*>(arg);

  self->hw_delay_ = delta - self->params_.GetBytesPerFrame(kSampleFormat);
}

void *sndio_in_threadstart(void *arg) {
  NOTIMPLEMENTED();
  SndioAudioInputStream* self = static_cast<SndioAudioInputStream*>(arg);

  self->ReadAudio();
  return NULL;
}

SndioAudioInputStream::SndioAudioInputStream(AudioManagerBase* audio_manager,
                                       const std::string& device_name,
                                       const AudioParameters& params)
    : audio_manager_(audio_manager),
      device_name_(device_name),
      params_(params),
      bytes_per_buffer_(params.GetBytesPerBuffer(kSampleFormat)),
      buffer_duration_(base::TimeDelta::FromMicroseconds(
          params.frames_per_buffer() * base::Time::kMicrosecondsPerSecond /
          static_cast<float>(params.sample_rate()))),
      callback_(NULL),
      device_handle_(NULL),
      read_callback_behind_schedule_(false),
      audio_bus_(AudioBus::Create(params)) {
}

SndioAudioInputStream::~SndioAudioInputStream() {}

bool SndioAudioInputStream::Open() {
  struct sio_par par;
  int sig;

  if (device_handle_)
    return false;  // Already open.

  if (params_.format() != AudioParameters::AUDIO_PCM_LINEAR &&
      params_.format() != AudioParameters::AUDIO_PCM_LOW_LATENCY) {
    LOG(WARNING) << "Unsupported audio format.";
    return false;
  }

  sio_initpar(&par);
  par.rate = params_.sample_rate();
  par.pchan = params_.channels();
  par.bits = SampleFormatToBytesPerChannel(kSampleFormat);
  par.bps = par.bits / 8;
  par.sig = sig = par.bits != 8 ? 1 : 0;
  par.le = SIO_LE_NATIVE;
  par.appbufsz = params_.frames_per_buffer();
  sndio_rec_bufsz_ = par.bufsz;
  sndio_rec_bufsize_ = par.round * par.bps * par.rchan;

  device_handle_ = sio_open(SIO_DEVANY, SIO_REC, 0);

  if (device_handle_ == NULL) {
    LOG(ERROR) << "Couldn't open audio device.";
    return false;
  }

  if (!sio_setpar(device_handle_, &par) || !sio_getpar(device_handle_, &par)) {
    LOG(ERROR) << "Couldn't set audio parameters.";
    goto bad_close;
  }

  if (par.rate  != (unsigned int)params_.sample_rate() ||
      par.pchan != (unsigned int)params_.channels() ||
      par.bits  != (unsigned int)SampleFormatToBytesPerChannel(kSampleFormat) ||
      par.sig   != (unsigned int)sig ||
      (par.bps > 1 && par.le != SIO_LE_NATIVE) ||
      (par.bits != par.bps * 8)) {
    LOG(ERROR) << "Unsupported audio parameters.";
    goto bad_close;
  }
  sio_onmove(device_handle_, sndio_in_onmove, this);

  audio_buffer_.reset(new uint8_t[bytes_per_buffer_]);

  return true;
bad_close:
  sio_close(device_handle_);
  return false;
}

void SndioAudioInputStream::Start(AudioInputCallback* callback) {
  DCHECK(!callback_ && callback);
  callback_ = callback;
  StartAgc();

  // We start reading data half |buffer_duration_| later than when the
  // buffer might have got filled, to accommodate some delays in the audio
  // driver. This could also give us a smooth read sequence going forward.
  base::TimeDelta delay = buffer_duration_ + buffer_duration_ / 2;
  next_read_time_ = base::TimeTicks::Now() + delay;
  if (pthread_create(&thread_, NULL, sndio_in_threadstart, this) != 0)
    LOG(ERROR) << "Failed to create real-time thread.";
}

void SndioAudioInputStream::ReadAudio() {
  NOTIMPLEMENTED();
}

void SndioAudioInputStream::Stop() {
  if (!device_handle_ || !callback_)
    return;

  StopAgc();

  pthread_join(thread_, NULL);
  sio_stop(device_handle_);

  callback_ = NULL;
}

void SndioAudioInputStream::Close() {
  if (device_handle_) {
    sio_close(device_handle_);
    audio_buffer_.reset();
    device_handle_ = NULL;
  }

  audio_manager_->ReleaseInputStream(this);
}

double SndioAudioInputStream::GetMaxVolume() {
  return static_cast<double>(SIO_MAXVOL);
}

void SndioAudioInputStream::SetVolume(double volume) {
  NOTIMPLEMENTED();
}

double SndioAudioInputStream::GetVolume() {
  long current_volume = 0;
  return static_cast<double>(current_volume);
}

bool SndioAudioInputStream::IsMuted() {
  return false;
}

void SndioAudioInputStream::SetOutputDeviceForAec(
    const std::string& output_device_id) {
// Not supported. Do nothing.
}

}  // namespace media
