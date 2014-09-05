--- ./librhash/rhash_torrent.h.orig	2014-08-22 08:37:39.000000000 -0400
+++ ./librhash/rhash_torrent.h	2014-08-22 08:37:46.000000000 -0400
@@ -11,8 +11,6 @@
 # define RHASH_API
 #endif
 
-typedef struct rhash_context* rhash;
-
 /* a binary string with length */
 typedef struct rhash_str
 {
