--- osp/osp.c	2023-04-26 03:20:28.000000000 -0500
+++ osp/osp.c	2023-05-15 22:35:12.914724000 -0500
@@ -141,7 +141,9 @@
   if (host && *host == '/')
     {
       struct sockaddr_un addr;
+#if !defined(__FreeBSD__)
       int len;
+#endif
 
       if (strlen (host) >= sizeof (addr.sun_path))
         {
@@ -159,10 +161,15 @@
         }
 
       addr.sun_family = AF_UNIX;
+#if defined (__FreeBSD__)
+      strcpy (addr.sun_path, host);
+      if (connect (connection->socket, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1)
+#else
       memset (addr.sun_path, 0, sizeof (addr.sun_path));
       memcpy (addr.sun_path, host, strlen (host));
       len = strlen (addr.sun_path) + sizeof (addr.sun_family);
       if (connect (connection->socket, (struct sockaddr *) &addr, len) == -1)
+#endif
         {
           close (connection->socket);
           g_free (connection);
