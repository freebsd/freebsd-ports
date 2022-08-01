--- osp/osp.c	2022-07-18 03:40:56.000000000 -0500
+++ osp/osp.c	2022-07-31 18:21:56.704338000 -0500
@@ -141,7 +141,9 @@
   if (host && *host == '/')
     {
       struct sockaddr_un addr;
+#if !defined(__FreeBSD__)
       int len;
+#endif
 
       connection = g_malloc0 (sizeof (*connection));
       connection->socket = socket (AF_UNIX, SOCK_STREAM, 0);
@@ -152,10 +154,15 @@
         }
 
       addr.sun_family = AF_UNIX;
+#if defined (__FreeBSD__)
+      strcpy (addr.sun_path, host);
+      if (connect (connection->socket, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1)
+#else
       memset (addr.sun_path, 0, sizeof (addr.sun_path));
       memcpy (addr.sun_path, host, sizeof (addr.sun_path) - 1);
       len = strlen (addr.sun_path) + sizeof (addr.sun_family);
       if (connect (connection->socket, (struct sockaddr *) &addr, len) == -1)
+#endif
         {
           close (connection->socket);
           g_free (connection);
