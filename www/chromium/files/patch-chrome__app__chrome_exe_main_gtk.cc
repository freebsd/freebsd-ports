--- ./chrome/app/chrome_exe_main_gtk.cc.orig	2010-12-16 02:11:51.000000000 +0100
+++ ./chrome/app/chrome_exe_main_gtk.cc	2010-12-20 20:15:08.000000000 +0100
@@ -3,7 +3,7 @@
 // found in the LICENSE file.
 
 #include "base/process_util.h"
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/first_run.h"
 #endif
 
@@ -19,11 +19,11 @@
 extern "C" {
 int ChromeMain(int argc, const char** argv);
 
-#if defined(OS_LINUX) && defined(USE_TCMALLOC)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(USE_TCMALLOC)
 
 int tc_set_new_mode(int mode);
 
-#endif  // defined(OS_LINUX) && defined(USE_TCMALLOC)
+#endif  // (defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(USE_TCMALLOC)
 }
 
 int main(int argc, const char** argv) {
@@ -36,7 +36,7 @@
   // dependency on TCMalloc.  Really, we ought to have our allocator shim code
   // implement this EnableTerminationOnOutOfMemory() function.  Whateverz.  This
   // works for now.
-#if defined(OS_LINUX) && defined(USE_TCMALLOC)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(USE_TCMALLOC)
   // For tcmalloc, we need to tell it to behave like new.
   tc_set_new_mode(1);
 #endif
