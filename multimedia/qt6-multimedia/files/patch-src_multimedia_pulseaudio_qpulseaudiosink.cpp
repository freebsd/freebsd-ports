Fix 32-bit builds with PULSEAUDIO option.

--- src/multimedia/pulseaudio/qpulseaudiosink.cpp.orig	2025-05-04 13:16:35 UTC
+++ src/multimedia/pulseaudio/qpulseaudiosink.cpp
@@ -491,8 +491,8 @@ qint64 QPulseAudioSink::write(const char *data, qint64
     // or even affect the system volume if flat volumes are enabled
 
     QAudioHelperInternal::applyVolume(volume(), m_format,
-                                      QSpan{ reinterpret_cast<const std::byte *>(data), len },
-                                      QSpan{ reinterpret_cast<std::byte *>(dest), len });
+                                      QSpan{ reinterpret_cast<const std::byte *>(data), static_cast<qsizetype>(len) },
+                                      QSpan{ reinterpret_cast<std::byte *>(dest), static_cast<qsizetype>(len) });
 
     if ((pa_stream_write(m_stream.get(), dest, len, nullptr, 0, PA_SEEK_RELATIVE)) < 0) {
         engineLock.unlock();
