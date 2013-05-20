g_thread_init has been deprecated since version 2.32.

https://developer.gnome.org/glib/2.34/glib-Deprecated-Thread-APIs.html#g-thread-init

--- ./panel-plugin/xfce4-dict-plugin.c.orig	2012-05-04 22:41:55.000000000 +0000
+++ ./panel-plugin/xfce4-dict-plugin.c	2013-05-20 20:12:34.000000000 +0000
@@ -417,7 +417,9 @@
 
 	xfce_textdomain(GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR, "UTF-8");
 
+	#if !GLIB_CHECK_VERSION(2, 32, 0)
 	g_thread_init(NULL);
+	#endif
 
 	dpd->dd = dict_create_dictdata();
 	dpd->dd->is_plugin = TRUE;
