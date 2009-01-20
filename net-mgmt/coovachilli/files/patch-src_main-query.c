diff -urN src/main-query.c.orig src/main-query.c
--- src/main-query.c.orig	2008-06-28 17:38:35.000000000 +0100
+++ src/main-query.c	2008-06-29 16:17:48.000000000 +0100
@@ -304,7 +304,13 @@
 
   remote.sun_family = AF_UNIX;
   strcpy(remote.sun_path, cmdsock);
-  len = strlen(remote.sun_path) + sizeof(remote.sun_family);
+
+#if defined (__FreeBSD__)  || defined (__APPLE__) || defined (__OpenBSD__)
+  remote.sun_len = strlen(remote.sun_path) + 1;
+#endif
+
+  len = offsetof(struct sockaddr_un, sun_path) + strlen(remote.sun_path);
+
   if (connect(s, (struct sockaddr *)&remote, len) == -1) {
     perror("connect");
     exit(1);

