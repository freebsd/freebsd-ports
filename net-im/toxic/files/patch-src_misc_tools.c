--- src/misc_tools.c.orig	2014-08-15 03:31:28.000000000 +0200
+++ src/misc_tools.c	2014-08-15 16:51:14.000000000 +0200
@@ -38,6 +38,7 @@
 
 static uint64_t current_unix_time;
 
+/* Allready defined in libtoxcore
 void host_to_net(uint8_t *num, uint16_t numbytes)
 {
 #ifndef WORDS_BIGENDIAN
@@ -52,6 +53,7 @@
 #endif
     return;
 }
+*/
 
 void update_unix_time(void)
 {
