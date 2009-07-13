--- common/misc.c.orig	2009-07-07 18:15:41.000000000 +0100
+++ common/misc.c	2009-07-07 18:17:20.000000000 +0100
@@ -43,7 +43,7 @@
  */
 
 
-char *memrchr(char *s, int c, ssize_t len)
+char *memrchr9(char *s, int c, ssize_t len)
 {
 	char *ret;
 
