--- src/url.h.orig	2008-08-29 15:51:58.000000000 +0400
+++ src/url.h	2009-03-23 03:49:40.000000000 +0300
@@ -60,7 +60,7 @@
 struct url_t *new_url_t(const char *url);
 void free_url_t(struct url_t *u);
 void copy_url_t(struct url_t *url,struct url_t *srcurl);
-inline int is_url_valid_char(int c);
+int is_url_valid_char(int c);
 void url_unescape_string(char *dst,char *src);
 
 
