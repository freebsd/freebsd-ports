--- common/misc.h.orig	2009-07-07 18:15:47.000000000 +0100
+++ common/misc.h	2009-07-07 18:17:01.000000000 +0100
@@ -90,7 +90,7 @@
  * PROTOTYPES
  */
 
-char *memrchr(char *s, int c, ssize_t len);
+char *memrchr9(char *s, int c, ssize_t len);
 void hex(char *buf, const char *src, ssize_t len);
 void hmac_md5(char *out, char *in, META_ORD inl, char *key, META_ORD keyl);
 void get_random_data(char *p, ssize_t len);
