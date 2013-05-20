g_thread_init has been deprecated since version 2.32.

https://developer.gnome.org/glib/2.34/glib-Deprecated-Thread-APIs.html#g-thread-init

--- ./src/xfce4-dict.c.orig	2012-05-04 23:07:31.000000000 +0000
+++ ./src/xfce4-dict.c	2013-05-20 20:14:48.000000000 +0000
@@ -175,7 +175,9 @@
 	dd->is_plugin = FALSE;
 	dd->verbose_mode = verbose_mode;
 
+	#if !GLIB_CHECK_VERSION(2, 32, 0)
 	g_thread_init(NULL);
+	#endif
 
 	dict_read_rc_file(dd);
 
