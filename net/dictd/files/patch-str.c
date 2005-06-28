--- str.c.orig	Sun Jun 26 23:19:54 2005
+++ str.c	Sun Jun 26 23:20:19 2005
@@ -74,7 +74,7 @@
       if ((int) len < 0)
 	 return errno;
 
-      if (iswspace (ucs4_char)){
+      if (iswspace__ (ucs4_char)){
 	 *dest++ = ' ';
       }else if (allchars_mode || iswalnum__ (ucs4_char)){
 	 len2 = wcrtomb__ (dest, towlower__ (ucs4_char), &ps2);
