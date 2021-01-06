--- osp/osp.c	2021-01-03 15:42:39.761321000 -0500
+++ osp/osp.c	2021-01-03 15:48:50.962832000 -0500
@@ -134,7 +134,6 @@
   if (host && *host == '/')
     {
       struct sockaddr_un addr;
-      int len;
 
       connection = g_malloc0 (sizeof (*connection));
       connection->socket = socket (AF_UNIX, SOCK_STREAM, 0);
@@ -142,9 +141,8 @@
         return NULL;
 
       addr.sun_family = AF_UNIX;
-      strncpy (addr.sun_path, host, sizeof (addr.sun_path) - 1);
-      len = strlen (addr.sun_path) + sizeof (addr.sun_family);
-      if (connect (connection->socket, (struct sockaddr *) &addr, len) == -1)
+      strcpy (addr.sun_path, host);
+      if (connect (connection->socket, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1)
         {
           close (connection->socket);
           return NULL;
