--- src/port_audio.cpp.orig	2026-08-26 23:51:36 UTC
+++ src/port_audio.cpp
@@ -26,7 +26,7 @@
 #include <windows.h>
 #endif
 
-#if !defined(__APPLE__) && !defined(WIN32)
+#if !defined(__APPLE__) && !defined(WIN32) && defined(HAVE_JACK)
 #include <pa_jack.h>
 #endif
 
@@ -130,7 +130,7 @@ int snd_init(void)
 {
     char info_buf[256];
 
-#if !defined(__APPLE__) && !defined(WIN32) // JACK: Set client name before Pa_Initialize
+#if !defined(__APPLE__) && !defined(WIN32) && defined(HAVE_JACK) // JACK: Set client name before Pa_Initialize
     if (jack_client_name != NULL && strlen(jack_client_name) > 0) {
         PaJack_SetClientName(jack_client_name);
     }
