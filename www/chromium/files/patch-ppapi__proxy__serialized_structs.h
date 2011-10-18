--- ppapi/proxy/serialized_structs.h.orig	2011-06-27 23:46:48.860441060 +0300
+++ ppapi/proxy/serialized_structs.h	2011-06-27 23:46:52.210441968 +0300
@@ -115,7 +115,7 @@
 
 #if defined(OS_WIN)
 typedef HANDLE ImageHandle;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
 typedef base::SharedMemoryHandle ImageHandle;
 #else
 // On X Windows this is a SysV shared memory key.
