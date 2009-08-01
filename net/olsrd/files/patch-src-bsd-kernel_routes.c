--- src/bsd/kernel_routes.c.orig	2009-02-01 19:57:23.000000000 +0000
+++ src/bsd/kernel_routes.c	2009-06-17 15:57:01.000000000 +0000
@@ -95,8 +95,8 @@
   sin4.sin_len = sizeof(sin4);
   sin4.sin_family = AF_INET;
 
-  sin_size = 1 + ((sizeof(struct sockaddr_in) - 1) | 3);
-  sdl_size = 1 + ((sizeof(struct sockaddr_dl) - 1) | 3);
+  sin_size = 1 + ((sizeof(struct sockaddr_in) - 1) | (sizeof(long) - 1));
+  sdl_size = 1 + ((sizeof(struct sockaddr_dl) - 1) | (sizeof(long) - 1));
 
   /**********************************************************************
    *                  FILL THE ROUTING MESSAGE HEADER
@@ -250,8 +252,8 @@
   sdl.sdl_len = sizeof(sdl);
   sdl.sdl_family = AF_LINK;
 
-  sin_size = 1 + ((sizeof(struct sockaddr_in6) - 1) | 3);
-  sdl_size = 1 + ((sizeof(struct sockaddr_dl) - 1) | 3);
+  sin_size = 1 + ((sizeof(struct sockaddr_in6) - 1) | (sizeof(long) - 1));
+  sdl_size = 1 + ((sizeof(struct sockaddr_dl) - 1) | (sizeof(long) - 1));
 
   /**********************************************************************
    *                  FILL THE ROUTING MESSAGE HEADER
