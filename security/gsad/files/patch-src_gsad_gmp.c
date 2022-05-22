--- src/gsad_gmp.c	2022-04-20 16:25:17.556260000 -0500
+++ src/gsad_gmp.c	2022-04-20 16:27:20.232932000 -0500
@@ -16645,8 +16645,13 @@
   /* Connect to server. */
 
   address.sun_family = AF_UNIX;
+#if defined(__FreeBSD__)
+  strcpy (address.sun_path, path);
+  if (connect (sock, (struct sockaddr *) &address, sizeof (struct sockaddr_un)) == -1)
+#else
   strncpy (address.sun_path, path, sizeof (address.sun_path) - 1);
   if (connect (sock, (struct sockaddr *) &address, sizeof (address)) == -1)
+#endif
     {
       g_warning ("Failed to connect to server at %s: %s", path,
                  strerror (errno));
