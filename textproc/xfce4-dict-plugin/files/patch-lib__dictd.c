g_thread_create has been deprecated since version 2.32.

https://developer.gnome.org/glib/2.34/glib-Deprecated-Thread-APIs.html#g-thread-create

--- ./lib/dictd.c.orig	2013-05-20 12:27:17.000000000 +0000
+++ ./lib/dictd.c	2013-05-20 21:15:01.000000000 +0000
@@ -678,7 +678,11 @@
 		dictd_init();
 
 		/* start the thread to query the server */
-		g_thread_create((GThreadFunc) ask_server, dd, FALSE, NULL);
+		#if GLIB_CHECK_VERSION(2, 32, 0)
+			g_thread_new("ask_server", (GThreadFunc) ask_server, dd);
+		#else
+			g_thread_create((GThreadFunc) ask_server, dd, FALSE, NULL);
+		#endif
 	}
 }
 
