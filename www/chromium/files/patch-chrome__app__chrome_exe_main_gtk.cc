--- chrome/app/chrome_exe_main_gtk.cc.orig	2011-04-16 11:01:37.000000000 +0300
+++ chrome/app/chrome_exe_main_gtk.cc	2011-04-25 20:11:07.659145645 +0300
@@ -3,7 +3,7 @@
 // found in the LICENSE file.
 
 #include "base/process_util.h"
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/first_run.h"
 #endif
 
@@ -19,16 +19,18 @@
 extern "C" {
 int ChromeMain(int argc, const char** argv);
 
-#if defined(OS_LINUX) && defined(USE_TCMALLOC)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(USE_TCMALLOC)
 
 int tc_set_new_mode(int mode);
 
-#endif  // defined(OS_LINUX) && defined(USE_TCMALLOC)
+#endif  // (defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(USE_TCMALLOC)
 }
 
 int main(int argc, const char** argv) {
   base::EnableTerminationOnHeapCorruption();
+#if !defined(OS_FREEBSD)
   base::EnableTerminationOnOutOfMemory();
+#endif
 
   // NOTE(willchan): One might ask why this call is done here rather than in
   // process_util_linux.cc with the definition of
@@ -36,7 +38,7 @@
   // dependency on TCMalloc.  Really, we ought to have our allocator shim code
   // implement this EnableTerminationOnOutOfMemory() function.  Whateverz.  This
   // works for now.
-#if defined(OS_LINUX) && defined(USE_TCMALLOC)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(USE_TCMALLOC)
   // For tcmalloc, we need to tell it to behave like new.
   tc_set_new_mode(1);
 #endif
