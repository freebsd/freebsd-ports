--- webkit/plugins/ppapi/ppapi_plugin_instance.cc.orig	2013-04-30 10:22:18.000000000 +0300
+++ webkit/plugins/ppapi/ppapi_plugin_instance.cc	2013-05-07 21:26:49.000000000 +0300
@@ -1627,7 +1627,7 @@
 #endif  // defined(OS_WIN)
 
   bool ret = false;
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On Linux we just set the final bits in the native metafile
   // (NativeMetafile and PreviewMetafile must have compatible formats,
   // i.e. both PDF for this to work).
