--- media/audio/sndio/audio_manager_sndio.cc.orig	2022-02-07 13:39:41 UTC
+++ media/audio/sndio/audio_manager_sndio.cc
@@ -0,0 +1,177 @@
+// Copyright (c) 2012 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/metrics/histogram_macros.h"
+#include "base/memory/ptr_util.h"
+
+#include "media/audio/sndio/audio_manager_sndio.h"
+
+#include "media/audio/audio_device_description.h"
+#include "media/audio/audio_output_dispatcher.h"
+#if defined(USE_SNDIO)
+#include "media/audio/sndio/sndio_input.h"
+#include "media/audio/sndio/sndio_output.h"
+#else
+#include "media/audio/fake_audio_manager.h"
+#endif
+#include "media/base/limits.h"
+#include "media/base/media_switches.h"
+
+namespace media {
+
+enum SndioAudioIO {
+  kPulse,
+  kSndio,
+  kAudioIOMax = kSndio
+};
+
+#if defined(USE_SNDIO)
+// Maximum number of output streams that can be open simultaneously.
+static const int kMaxOutputStreams = 4;
+
+// Default sample rate for input and output streams.
+static const int kDefaultSampleRate = 48000;
+
+void AddDefaultDevice(AudioDeviceNames* device_names) {
+  DCHECK(device_names->empty());
+  device_names->push_front(AudioDeviceName::CreateDefault());
+}
+
+bool AudioManagerSndio::HasAudioOutputDevices() {
+  return true;
+}
+
+bool AudioManagerSndio::HasAudioInputDevices() {
+  return true;
+}
+
+void AudioManagerSndio::GetAudioInputDeviceNames(
+    AudioDeviceNames* device_names) {
+  DCHECK(device_names->empty());
+  AddDefaultDevice(device_names);
+}
+
+void AudioManagerSndio::GetAudioOutputDeviceNames(
+    AudioDeviceNames* device_names) {
+  AddDefaultDevice(device_names);
+}
+
+#if defined(USE_SNDIO)
+const char* AudioManagerSndio::GetName() {
+  return "SNDIO";
+}
+#endif
+
+AudioParameters AudioManagerSndio::GetInputStreamParameters(
+    const std::string& device_id) {
+  static const int kDefaultInputBufferSize = 1024;
+
+  int user_buffer_size = GetUserBufferSize();
+  int buffer_size = user_buffer_size ?
+      user_buffer_size : kDefaultInputBufferSize;
+
+  return AudioParameters(
+      AudioParameters::AUDIO_PCM_LOW_LATENCY, CHANNEL_LAYOUT_STEREO,
+      kDefaultSampleRate, buffer_size);
+}
+
+AudioManagerSndio::AudioManagerSndio(std::unique_ptr<AudioThread> audio_thread,
+                                         AudioLogFactory* audio_log_factory)
+    : AudioManagerBase(std::move(audio_thread),
+                       audio_log_factory) {
+  DLOG(WARNING) << "AudioManagerSndio";
+  SetMaxOutputStreamsAllowed(kMaxOutputStreams);
+}
+
+AudioManagerSndio::~AudioManagerSndio() {
+  Shutdown();
+}
+
+AudioOutputStream* AudioManagerSndio::MakeLinearOutputStream(
+    const AudioParameters& params,
+    const LogCallback& log_callback) {
+  DCHECK_EQ(AudioParameters::AUDIO_PCM_LINEAR, params.format());
+  return MakeOutputStream(params);
+}
+
+AudioOutputStream* AudioManagerSndio::MakeLowLatencyOutputStream(
+    const AudioParameters& params,
+    const std::string& device_id,
+    const LogCallback& log_callback) {
+  DLOG_IF(ERROR, !device_id.empty()) << "Not implemented!";
+  DCHECK_EQ(AudioParameters::AUDIO_PCM_LOW_LATENCY, params.format());
+  return MakeOutputStream(params);
+}
+
+AudioInputStream* AudioManagerSndio::MakeLinearInputStream(
+    const AudioParameters& params,
+    const std::string& device_id,
+    const LogCallback& log_callback) {
+  DCHECK_EQ(AudioParameters::AUDIO_PCM_LINEAR, params.format());
+  return MakeInputStream(params);
+}
+
+AudioInputStream* AudioManagerSndio::MakeLowLatencyInputStream(
+    const AudioParameters& params,
+    const std::string& device_id,
+    const LogCallback& log_callback) {
+  DCHECK_EQ(AudioParameters::AUDIO_PCM_LOW_LATENCY, params.format());
+  return MakeInputStream(params);
+}
+
+AudioParameters AudioManagerSndio::GetPreferredOutputStreamParameters(
+    const std::string& output_device_id,
+    const AudioParameters& input_params) {
+  // TODO(tommi): Support |output_device_id|.
+  DLOG_IF(ERROR, !output_device_id.empty()) << "Not implemented!";
+  static const int kDefaultOutputBufferSize = 2048;
+
+  ChannelLayout channel_layout = CHANNEL_LAYOUT_STEREO;
+  int sample_rate = kDefaultSampleRate;
+  int buffer_size = kDefaultOutputBufferSize;
+  if (input_params.IsValid()) {
+    sample_rate = input_params.sample_rate();
+    channel_layout = input_params.channel_layout();
+    buffer_size = std::min(buffer_size, input_params.frames_per_buffer());
+  }
+
+  int user_buffer_size = GetUserBufferSize();
+  if (user_buffer_size)
+    buffer_size = user_buffer_size;
+
+  return AudioParameters(
+      AudioParameters::AUDIO_PCM_LOW_LATENCY, channel_layout,
+      sample_rate, buffer_size);
+}
+
+AudioInputStream* AudioManagerSndio::MakeInputStream(
+    const AudioParameters& params) {
+  DLOG(WARNING) << "MakeInputStream";
+  return new SndioAudioInputStream(this,
+             AudioDeviceDescription::kDefaultDeviceId, params);
+}
+
+AudioOutputStream* AudioManagerSndio::MakeOutputStream(
+    const AudioParameters& params) {
+  DLOG(WARNING) << "MakeOutputStream";
+  return new SndioAudioOutputStream(params, this);
+}
+#endif
+
+std::unique_ptr<media::AudioManager> CreateAudioManager(
+    std::unique_ptr<AudioThread> audio_thread,
+    AudioLogFactory* audio_log_factory) {
+  DLOG(WARNING) << "CreateAudioManager";
+#if defined(USE_SNDIO)
+  UMA_HISTOGRAM_ENUMERATION("Media.SndioAudioIO", kSndio, kAudioIOMax + 1);
+  return std::make_unique<AudioManagerSndio>(std::move(audio_thread),
+                                            audio_log_factory);
+#else
+  return std::make_unique<FakeAudioManager>(std::move(audio_thread),
+                                            audio_log_factory);
+#endif
+
+}
+
+}  // namespace media
