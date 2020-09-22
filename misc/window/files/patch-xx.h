--- xx.h.orig	2008-07-12 06:05:22 UTC
+++ xx.h
@@ -50,10 +50,10 @@ struct xx {
 
 struct xx *xxalloc();
 
-struct xx *xx_head, *xx_tail;
-struct xx *xx_freelist;
+extern struct xx *xx_head, *xx_tail;
+extern struct xx *xx_freelist;
 
-char *xxbuf, *xxbufp, *xxbufe;
-int xxbufsize;
+extern char *xxbuf, *xxbufp, *xxbufe;
+extern int xxbufsize;
 
 #define char_sep '\0'
