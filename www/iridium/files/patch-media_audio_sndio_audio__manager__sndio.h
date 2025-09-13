--- media/audio/sndio/audio_manager_sndio.h.orig	2025-09-11 13:19:19 UTC
+++ media/audio/sndio/audio_manager_sndio.h
@@ -0,0 +1,66 @@
+// Copyright (c) 2012 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef MEDIA_AUDIO_SNDIO_AUDIO_MANAGER_SNDIO_H_
+#define MEDIA_AUDIO_SNDIO_AUDIO_MANAGER_SNDIO_H_
+
+#include <set>
+
+#include "base/compiler_specific.h"
+#include "base/memory/ref_counted.h"
+#include "base/threading/thread.h"
+#include "media/audio/audio_manager_base.h"
+
+namespace media {
+
+class MEDIA_EXPORT AudioManagerSndio : public AudioManagerBase {
+ public:
+  AudioManagerSndio(std::unique_ptr<AudioThread> audio_thread,
+                   AudioLogFactory* audio_log_factory);
+
+  AudioManagerSndio(const AudioManagerSndio&) = delete;
+  AudioManagerSndio& operator=(const AudioManagerSndio&) = delete;
+
+  ~AudioManagerSndio() override;
+
+  // Implementation of AudioManager.
+  bool HasAudioOutputDevices() override;
+  bool HasAudioInputDevices() override;
+  void GetAudioInputDeviceNames(AudioDeviceNames* device_names) override;
+  void GetAudioOutputDeviceNames(AudioDeviceNames* device_names) override;
+  AudioParameters GetInputStreamParameters(
+      const std::string& device_id) override;
+  const std::string_view GetName() override;
+
+  // Implementation of AudioManagerBase.
+  AudioOutputStream* MakeLinearOutputStream(
+      const AudioParameters& params,
+      const LogCallback& log_callback) override;
+  AudioOutputStream* MakeLowLatencyOutputStream(
+      const AudioParameters& params,
+      const std::string& device_id,
+      const LogCallback& log_callback) override;
+  AudioInputStream* MakeLinearInputStream(
+      const AudioParameters& params,
+      const std::string& device_id,
+      const LogCallback& log_callback) override;
+  AudioInputStream* MakeLowLatencyInputStream(
+      const AudioParameters& params,
+      const std::string& device_id,
+      const LogCallback& log_callback) override;
+
+ protected:
+  AudioParameters GetPreferredOutputStreamParameters(
+      const std::string& output_device_id,
+      const AudioParameters& input_params) override;
+
+ private:
+  // Called by MakeLinearOutputStream and MakeLowLatencyOutputStream.
+  AudioOutputStream* MakeOutputStream(const AudioParameters& params);
+  AudioInputStream* MakeInputStream(const AudioParameters& params);
+};
+
+}  // namespace media
+
+#endif  // MEDIA_AUDIO_SNDIO_AUDIO_MANAGER_SNDIO_H_
