--- ./webkit/glue/webkit_glue.h.orig	2010-12-16 02:11:23.000000000 +0100
+++ ./webkit/glue/webkit_glue.h	2010-12-20 20:15:08.000000000 +0100
@@ -271,7 +271,7 @@
 // Notifies the browser that the given action has been performed.
 void UserMetricsRecordAction(const std::string& action);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Return a read-only file descriptor to the font which best matches the given
 // properties or -1 on failure.
 //   charset: specifies the language(s) that the font must cover. See
