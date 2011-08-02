--- chrome/app/chrome_exe_main_gtk.cc.orig	2011-06-24 11:31:08.000000000 +0300
+++ chrome/app/chrome_exe_main_gtk.cc	2011-06-26 17:42:52.610782235 +0300
@@ -25,7 +25,9 @@
 
 int main(int argc, const char** argv) {
   base::EnableTerminationOnHeapCorruption();
+#if !defined(OS_FREEBSD)
   base::EnableTerminationOnOutOfMemory();
+#endif
 
   // NOTE(willchan): One might ask why this call is done here rather than in
   // process_util_linux.cc with the definition of
