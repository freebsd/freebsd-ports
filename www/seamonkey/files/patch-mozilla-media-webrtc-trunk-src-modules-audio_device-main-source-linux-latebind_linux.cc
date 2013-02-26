--- mozilla/media/webrtc/trunk/src/modules/audio_device/main/source/linux/latebindingsymboltable_linux.cc~
+++ mozilla/media/webrtc/trunk/src/modules/audio_device/main/source/linux/latebindingsymboltable_linux.cc
@@ -31,6 +31,10 @@
 #include <dlfcn.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
+
 // TODO(grunell): Either put inside webrtc namespace or use webrtc:: instead.
 using namespace webrtc;
 
@@ -38,7 +42,11 @@ namespace webrtc_adm_linux {
 
 inline static const char *GetDllError() {
 #ifdef WEBRTC_LINUX
+#if __FreeBSD_version < 800505
+  const char *err = dlerror();
+#else
   char *err = dlerror();
+#endif
   if (err) {
     return err;
   } else {
@@ -78,7 +86,11 @@ static bool LoadSymbol(DllHandle handle,
                        void **symbol) {
 #ifdef WEBRTC_LINUX
   *symbol = dlsym(handle, symbol_name);
+#if __FreeBSD_version < 800505
+  const char *err = dlerror();
+#else
   char *err = dlerror();
+#endif
   if (err) {
     WEBRTC_TRACE(kTraceError, kTraceAudioDevice, -1,
                "Error loading symbol %s : %d", symbol_name, err);
