--- chrome/common/render_messages_internal.h.orig	2011-01-06 10:02:01.000000000 +0100
+++ chrome/common/render_messages_internal.h	2011-01-09 20:47:08.000000000 +0100
@@ -2117,7 +2117,7 @@
                      std::string /* extension_id */,
                      std::string /* name */)
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 // On OSX, we cannot allocated shared memory from within the sandbox, so
 // this call exists for the renderer to ask the browser to allocate memory
 // on its behalf. We return a file descriptor to the POSIX shared memory.
