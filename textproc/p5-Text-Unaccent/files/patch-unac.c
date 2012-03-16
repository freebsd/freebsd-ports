--- unac.c.orig	2004-10-17 11:00:36.000000000 -0800
+++ unac.c	2012-03-15 16:55:01.042386000 -0800
@@ -13881,10 +13881,10 @@
     *out_lengthp = 0;
   } else {
     char* utf16 = 0;
-    int utf16_length = 0;
     char* utf16_unaccented = 0;
-    int utf16_unaccented_length = 0;
+    size_t utf16_length, utf16_unaccented_length;
   
+    utf16_length = utf16_unaccented_length = 0;
     if(convert(charset, utf16be(), in, in_length, &utf16, &utf16_length) < 0) {
       return -1;
     }
