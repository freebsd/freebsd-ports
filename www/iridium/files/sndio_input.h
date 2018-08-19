// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_AUDIO_SNDIO_SNDIO_INPUT_H_
#define MEDIA_AUDIO_SNDIO_SNDIO_INPUT_H_

#include <stdint.h>
#include <string>
#include <sndio.h>

#include "base/compiler_specific.h"
#include "base/macros.h"
#include "base/memory/weak_ptr.h"
#include "base/time/time.h"
#include "media/audio/agc_audio_stream.h"
#include "media/audio/audio_io.h"
#include "media/audio/audio_device_description.h"
#include "media/base/audio_parameters.h"

namespace media {

class AudioManagerBase;

// call-backs invoked from C libraries, thus requiring C linkage
extern "C" {
  // Invoked (on the real-time thread) at each sound card clock tick
  void sndio_in_onmove(void *arg, int delta);
  // Invoked (on the real-time thread) whenever the volume changes
  void sndio_in_onvol(void *arg, unsigned int vol);
  // Real-time thread entry point
  void *sndio_in_threadstart(void *arg);
}

// Provides an input stream for audio capture based on the SNDIO PCM interface.
// This object is not thread safe and all methods should be invoked in the
// thread that created the object.
class SndioAudioInputStream : public AgcAudioStream<AudioInputStream> {
 public:
  // Pass this to the constructor if you want to attempt auto-selection
  // of the audio recording device.
  static const char kAutoSelectDevice[];

  // Create a PCM Output stream for the SNDIO device identified by
  // |device_name|. If unsure of what to use for |device_name|, use
  // |kAutoSelectDevice|.
  SndioAudioInputStream(AudioManagerBase* audio_manager,
                     const std::string& device_name,
                     const AudioParameters& params);

  ~SndioAudioInputStream() override;

  // Implementation of AudioInputStream.
  bool Open() override;
  void Start(AudioInputCallback* callback) override;
  void Stop() override;
  void Close() override;
  double GetMaxVolume() override;
  void SetVolume(double volume) override;
  double GetVolume() override;
  bool IsMuted() override;

  // C-linkage call-backs are friends to access private data
  friend void sndio_in_onmove(void *arg, int delta);
  friend void sndio_in_onvol(void *arg, unsigned int vol);
  friend void *sndio_in_threadstart(void *arg);

 private:
  // Logs the error and invokes any registered callbacks.
  void HandleError(const char* method, int error);

  // Reads one or more buffers of audio from the device, passes on to the
  // registered callback and schedules the next read.
  void ReadAudio();

  // Recovers from any device errors if possible.
  bool Recover(int error);

  // Non-refcounted pointer back to the audio manager.
  // The AudioManager indirectly holds on to stream objects, so we don't
  // want circular references.  Additionally, stream objects live on the audio
  // thread, which is owned by the audio manager and we don't want to addref
  // the manager from that thread.
  AudioManagerBase* audio_manager_;
  std::string device_name_;
  AudioParameters params_;
  int bytes_per_buffer_;
  base::TimeDelta buffer_duration_;  // Length of each recorded buffer.
  AudioInputCallback* callback_;  // Valid during a recording session.
  base::TimeTicks next_read_time_;  // Scheduled time for next read callback.
  struct sio_hdl* device_handle_;  // Handle to the SNDIO PCM recording device.
  std::unique_ptr<uint8_t[]> audio_buffer_;  // Buffer used for reading audio data.
  bool read_callback_behind_schedule_;
  std::unique_ptr<AudioBus> audio_bus_;

  int hw_delay_;
  int sndio_rec_bufsize_;
  int sndio_rec_bufsz_;

  // High priority thread running RealTimeThread()
  pthread_t thread_;

  DISALLOW_COPY_AND_ASSIGN(SndioAudioInputStream);
};

}  // namespace media

#endif  // MEDIA_AUDIO_SNDIO_SNDIO_INPUT_H_
