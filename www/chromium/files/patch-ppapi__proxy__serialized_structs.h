--- ppapi/proxy/serialized_structs.h.orig	2012-02-21 10:34:02.000000000 +0200
+++ ppapi/proxy/serialized_structs.h	2012-02-27 18:19:15.000000000 +0200
@@ -111,7 +111,7 @@
 
 #if defined(OS_WIN)
 typedef HANDLE ImageHandle;
-#elif defined(OS_MACOSX) || defined(OS_ANDROID)
+#elif defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
 typedef base::SharedMemoryHandle ImageHandle;
 #else
 // On X Windows this is a SysV shared memory key.
