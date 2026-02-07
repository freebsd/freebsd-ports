Patch from Stephen Hurd. PR208570. Allow ALSA aliases.

When using ALSA with FreeBSD, the direct snd_device instances are not
available, only plugin devices and "default".  For programs which use
QAudio, this means there are *no* devices enumerated using
QAudio::availableDevices().

The attached patch adds the aliases to the available device list.

--- src/plugins/alsa/qalsaaudiodeviceinfo.cpp.orig	2017-11-08 14:04:46 UTC
+++ src/plugins/alsa/qalsaaudiodeviceinfo.cpp
@@ -353,6 +353,58 @@ QList<QByteArray> QAlsaAudioDeviceInfo::
         ++n;
     }
     snd_device_name_free_hint(hints);
+
+#ifdef Q_OS_FREEBSD
+    // Now find aliases...
+    snd_config_iterator_t pos, next;
+    snd_config_t *top, *node, *type;
+    snd_pcm_t *pcm;
+    snd_pcm_stream_t streamType;
+    const char *idString;
+    const char **ignoreId;
+    static const char *ignore[] = {"hw", "plughw", "plug", "dsnoop", "tee",
+                                   "file", "null", "shm", "cards", "rate_convert", NULL};
+
+    // Populate snd_config...
+    if (snd_config == NULL)
+        snd_config_update();
+    if (snd_config != NULL) {
+        switch (mode) {
+        case QAudio::AudioInput:
+            streamType = SND_PCM_STREAM_CAPTURE;
+            break;
+        case QAudio::AudioOutput:
+            streamType = SND_PCM_STREAM_PLAYBACK;
+            break;
+        default:
+            goto bad_mode;
+        }
+        // Find "pcm" nodes...
+        if (snd_config_search(snd_config, "pcm", &top) >= 0) {
+            for (pos = snd_config_iterator_first(top), next = snd_config_iterator_next(pos);
+                    pos != snd_config_iterator_end(top);
+                    pos = next, next = snd_config_iterator_next(pos)) {
+                node = snd_config_iterator_entry(pos);
+                if (snd_config_search(node, "type", &type) < 0)
+                    continue;
+                snd_config_get_id(node, &idString);
+                for (ignoreId = ignore; *ignoreId; ignoreId++) {
+                    if (strcmp(*ignoreId, idString) == 0)
+                        break;
+                }
+                if (*ignoreId)
+                    continue;
+                // Ensure it's available...
+                if (snd_pcm_open(&pcm, idString, streamType, 0))
+                    continue;
+                snd_pcm_close(pcm);
+                const QString deviceName = QLatin1String(idString);
+                devices.append(deviceName.toLocal8Bit().constData());
+            }
+        }
+    }
+bad_mode:
+#endif
 #else
     int idx = 0;
     char* name;
