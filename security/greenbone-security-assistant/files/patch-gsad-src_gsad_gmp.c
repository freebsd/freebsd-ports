--- gsad/src/gsad_gmp.c	2021-01-03 19:47:56.782208000 -0500
+++ gsad/src/gsad_gmp.c	2021-01-03 19:49:29.616531000 -0500
@@ -16573,8 +16573,8 @@
   /* Connect to server. */
 
   address.sun_family = AF_UNIX;
-  strncpy (address.sun_path, path, sizeof (address.sun_path) - 1);
-  if (connect (sock, (struct sockaddr *) &address, sizeof (address)) == -1)
+  strcpy (address.sun_path, path);
+  if (connect (sock, (struct sockaddr *) &address, sizeof (struct sockaddr_un)) == -1)
     {
       g_warning ("Failed to connect to server at %s: %s", path,
                  strerror (errno));
