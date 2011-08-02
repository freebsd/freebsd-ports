--- webkit/plugins/ppapi/ppapi_plugin_instance.cc.orig	2011-06-27 02:14:17.790782765 +0300
+++ webkit/plugins/ppapi/ppapi_plugin_instance.cc	2011-06-27 02:13:53.064781555 +0300
@@ -69,7 +69,7 @@
 #include "printing/metafile_impl.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_WIN)
 #include "printing/metafile.h"
 #include "printing/metafile_skia_wrapper.h"
 #endif
@@ -1297,7 +1297,7 @@
 #endif  // defined(OS_WIN)
 
   bool ret = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // On Linux we just set the final bits in the native metafile
   // (NativeMetafile and PreviewMetafile must have compatible formats,
   // i.e. both PDF for this to work).
