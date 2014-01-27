--- ./index/region.c.orig	1999-03-02 07:38:34.000000000 +0000
+++ ./index/region.c	2014-01-27 21:40:18.000000000 +0000
@@ -168,7 +168,7 @@
 }
 
 /* Looks for embedded attributes and copies the real attribute into dest */
-attr_extract(dest, src)
+void attr_extract(dest, src)
 	char	*dest, *src;
 {
 	char	*oldsrc = src;
