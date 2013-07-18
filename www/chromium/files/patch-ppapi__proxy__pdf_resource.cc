--- ppapi/proxy/pdf_resource.cc.orig	2013-07-04 21:10:17.289142236 +0000
+++ ppapi/proxy/pdf_resource.cc	2013-07-04 21:17:42.456142534 +0000
@@ -189,7 +189,7 @@
   if (!reply_params.TakeSharedMemoryHandleAtIndex(0, &handle))
     return 0;
   return (new ImageData(resource, desc, handle))->GetReference();
-#elif defined(OS_LINUX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX)
   return (new ImageData(resource, desc, fd))->GetReference();
 #else
 #error Not implemented.
