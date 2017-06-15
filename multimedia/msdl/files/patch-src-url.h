--- src/url.h.orig	2008-08-29 15:51:58 UTC
+++ src/url.h
@@ -60,7 +60,7 @@
 struct url_t *new_url_t(const char *url);
 void free_url_t(struct url_t *u);
 void copy_url_t(struct url_t *url,struct url_t *srcurl);
-inline int is_url_valid_char(int c);
+int is_url_valid_char(int c);
 void url_unescape_string(char *dst,char *src);
 
 
