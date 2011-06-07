--- chrome/app/chrome_exe_main_gtk.cc.orig	2011-05-06 12:03:31.000000000 +0300
+++ chrome/app/chrome_exe_main_gtk.cc	2011-06-03 23:30:58.238403064 +0300
@@ -18,14 +18,16 @@
 extern "C" {
 int ChromeMain(int argc, const char** argv);
 
-#if defined(OS_LINUX) && defined(USE_TCMALLOC)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(USE_TCMALLOC)
 int tc_set_new_mode(int mode);
 #endif
 }
 
 int main(int argc, const char** argv) {
   base::EnableTerminationOnHeapCorruption();
+#if !defined(OS_FREEBSD)
   base::EnableTerminationOnOutOfMemory();
+#endif
 
   // NOTE(willchan): One might ask why this call is done here rather than in
   // process_util_linux.cc with the definition of
@@ -33,7 +35,7 @@
   // dependency on TCMalloc.  Really, we ought to have our allocator shim code
   // implement this EnableTerminationOnOutOfMemory() function.  Whateverz.  This
   // works for now.
-#if defined(OS_LINUX) && defined(USE_TCMALLOC)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(USE_TCMALLOC)
   // For tcmalloc, we need to tell it to behave like new.
   tc_set_new_mode(1);
 #endif
