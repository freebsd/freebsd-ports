--- mod_wsgi.c.orig	2008-06-18 16:35:40.000000000 +0200
+++ mod_wsgi.c	2008-07-19 19:41:18.000000000 +0200
@@ -7771,6 +7771,9 @@
      * is restricted, need to truncate display name if too long.
      */
 
+#ifdef __FreeBSD__
+    setproctitle(display_name);
+#else
     argv0 = (char*)wsgi_server->process->argv[0];
 
     dlen = strlen(argv0);
@@ -7782,6 +7785,7 @@
         memcpy(argv0, display_name, slen);
     else
         memcpy(argv0, display_name, dlen);
+#endif
 }
 
 static void wsgi_setup_access(WSGIDaemonProcess *daemon)
