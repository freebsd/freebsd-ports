--- webkit/plugins/ppapi/ppapi_plugin_instance.cc.orig	2011-07-28 11:01:06.000000000 +0300
+++ webkit/plugins/ppapi/ppapi_plugin_instance.cc	2011-09-07 01:45:08.000000000 +0300
@@ -1035,7 +1035,7 @@
 #endif  // defined(OS_WIN)
 
   bool ret = false;
-#if defined(OS_LINUX) || (defined(OS_MACOSX) && defined(USE_SKIA))
+#if defined(OS_LINUX) || (defined(OS_MACOSX) && defined(USE_SKIA)) || defined(OS_FREEBSD)
   // On Linux we just set the final bits in the native metafile
   // (NativeMetafile and PreviewMetafile must have compatible formats,
   // i.e. both PDF for this to work).
