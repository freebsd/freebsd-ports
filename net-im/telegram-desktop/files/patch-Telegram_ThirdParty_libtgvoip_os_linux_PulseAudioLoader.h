--- Telegram/ThirdParty/libtgvoip/os/linux/PulseAudioLoader.h.orig	2018-07-17 16:48:21 UTC
+++ Telegram/ThirdParty/libtgvoip/os/linux/PulseAudioLoader.h
@@ -9,6 +9,10 @@
 
 #include <pulse/pulseaudio.h>
 
+#ifndef typeof
+#define typeof __typeof__
+#endif
+
 #define DECLARE_DL_FUNCTION(name) static typeof(name)* _import_##name
 
 namespace tgvoip{
@@ -106,4 +110,4 @@ private:
 #define pa_operation_get_state PulseAudioLoader::_import_pa_operation_get_state
 #endif
 
-#endif // LIBTGVOIP_PULSEAUDIOLOADER_H
\ No newline at end of file
+#endif // LIBTGVOIP_PULSEAUDIOLOADER_H
