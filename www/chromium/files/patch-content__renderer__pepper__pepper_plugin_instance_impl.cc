--- content/renderer/pepper/pepper_plugin_instance_impl.cc.orig	2013-09-03 22:52:07.565628190 +0300
+++ content/renderer/pepper/pepper_plugin_instance_impl.cc	2013-09-03 22:52:34.954633148 +0300
@@ -1723,7 +1723,7 @@
 #endif  // defined(OS_WIN)
 
   bool ret = false;
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID)
   // On Linux we just set the final bits in the native metafile
   // (NativeMetafile and PreviewMetafile must have compatible formats,
   // i.e. both PDF for this to work).
