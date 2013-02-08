--- index/region.c.orig	2012-09-02 23:55:48.000000000 +0000
+++ index/region.c	2012-09-02 23:56:40.000000000 +0000
@@ -168,7 +168,7 @@
 }
 
 /* Looks for embedded attributes and copies the real attribute into dest */
-attr_extract(dest, src)
+void attr_extract(dest, src)
 	char	*dest, *src;
 {
 	char	*oldsrc = src;
