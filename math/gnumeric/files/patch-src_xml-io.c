--- src/xml-io.c.orig	Mon Jan  6 15:45:21 2003
+++ src/xml-io.c	Mon Jan  6 15:44:40 2003
@@ -67,7 +67,7 @@
 
 /* FIXME - tune the values below */
 /* libxml1 parser bug breaks multibyte characters on buffer margins */
-#define XML_INPUT_BUFFER_SIZE      1024*1024
+#define XML_INPUT_BUFFER_SIZE      1024*768
 #define N_ELEMENTS_BETWEEN_UPDATES 20
 
 /* ------------------------------------------------------------------------- */
