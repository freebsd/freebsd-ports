--- user_share.c.orig	Fri Nov 26 04:33:51 2004
+++ user_share.c	Fri Nov 26 17:24:31 2004
@@ -59,6 +59,14 @@
 	return -1;
     }
     
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)
+    /* XXX This exposes a potential race condition, but without this,
+     * httpd will not start on the above listed platforms due to the fact
+     * that SO_REUSEADDR is also needed when Apache binds to the listening
+     * socket.  At this time, Apache does not support that socket option.
+     */
+    close (sock);
+#endif
     return ntohs (addr.sin_port);
 }
 
@@ -171,7 +179,7 @@
     char *free1, *free2;
     gboolean res;
     char *argv[10];
-    char *env[10];;
+    char *env[10];
     int i;
     gint status;
     char *pid_filename;
@@ -195,9 +203,9 @@
     str = gconf_client_get_string (client,
 				   FILE_SHARING_REQUIRE_PASSWORD, NULL);
 
-    if (strcmp (str, "never") == 0) {
+    if (str && strcmp (str, "never") == 0) {
 	/* Do nothing */
-    } else if (strcmp (str, "on_write") == 0){
+    } else if (str && strcmp (str, "on_write") == 0){
 	argv[i++] = "-D";
 	argv[i++] = "RequirePasswordOnWrite";
     } else {
