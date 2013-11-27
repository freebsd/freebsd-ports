--- ./inotify.h.orig	2013-11-02 05:06:41.000000000 +0400
+++ ./inotify.h	2013-11-13 17:25:27.000000000 +0400
@@ -4,4 +4,10 @@
 
 void *
 start_inotify();
+#elif defined(HAVE_SYS_EVENT_H)
+int
+inotify_remove_file(const char* path);
+
+void *
+start_kqueue();
 #endif
