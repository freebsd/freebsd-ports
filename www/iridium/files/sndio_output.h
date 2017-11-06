// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_AUDIO_SNDIO_SNDIO_OUTPUT_H_
#define MEDIA_AUDIO_SNDIO_SNDIO_OUTPUT_H_

#include <pthread.h>
#include <sndio.h>

#include "base/time/tick_clock.h"
#include "base/time/time.h"
#include "media/audio/audio_io.h"


namespace media {

class AudioParameters;
class AudioManagerBase;

// call-backs invoked from C libraries, thus requiring C linkage
extern "C" {
  // Invoked (on the real-time thread) at each sound card clock tick
  void sndio_onmove(void *arg, int delta);
  // Invoked (on the real-time thread) whenever the volume changes
  void sndio_onvol(void *arg, unsigned int vol);
  // Real-time thread entry point
  void *sndio_threadstart(void *arg);
}

// Implementation of AudioOutputStream using sndio(7)
class SndioAudioOutputStream : public AudioOutputStream {
 public:
  // The manager is creating this object
  SndioAudioOutputStream(const AudioParameters& params,
                         AudioManagerBase* manager);
  virtual ~SndioAudioOutputStream();

  // Implementation of AudioOutputStream.
  virtual bool Open() override;
  virtual void Close() override;
  virtual void Start(AudioSourceCallback* callback) override;
  virtual void Stop() override;
  virtual void SetVolume(double volume) override;
  virtual void GetVolume(double* volume) override;

  // C-linkage call-backs are friends to access private data
  friend void sndio_onmove(void *arg, int delta);
  friend void sndio_onvol(void *arg, unsigned int vol);
  friend void *sndio_threadstart(void *arg);

 private:
  enum StreamState {
    kClosed,            // Not opened yet
    kStopped,           // Device opened, but not started yet
    kRunning,           // Started, device playing
    kStopWait           // Stopping, waiting for the real-time thread to exit
  };
  // Continuously moves data from the audio bus to the device
  void RealTimeThread(void);
  // Our creator, the audio manager needs to be notified when we close.
  AudioManagerBase* manager;
  // Parameters of the source
  AudioParameters params;
  // Source stores data here
  std::unique_ptr<AudioBus> audio_bus;
  int bytes_per_frame;
  // Call-back that produces data to play
  AudioSourceCallback* source;
  // Handle of the audio device
  struct sio_hdl* hdl;
  // Current state of the stream
  enum StreamState state;
  // High priority thread running RealTimeThread()
  pthread_t thread;
  // Protects vol, volpending and hw_delay
  pthread_mutex_t mutex;
  // Current volume in the 0..SIO_MAXVOL range
  int vol;
  // Set to 1 if volumes must be refreshed in the realtime thread
  int volpending;
  // Number of bytes buffered in the hardware
  int hw_delay;
  // Temporary buffer where data is stored sndio-compatible format
  char* buffer;

  DISALLOW_COPY_AND_ASSIGN(SndioAudioOutputStream);
};

}  // namespace media

#endif  // MEDIA_AUDIO_SNDIO_SNDIO_OUTPUT_H_
