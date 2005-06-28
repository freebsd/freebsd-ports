--- dictfmt.c.orig	Sun Jun 26 23:20:02 2005
+++ dictfmt.c	Sun Jun 26 23:20:37 2005
@@ -356,7 +356,7 @@
 	 len = mbtowc__ (&mbc, s, MB_CUR_MAX__);
 	 assert (len >= 0);
 
-	 if (len == 0 || !iswspace (mbc))
+	 if (len == 0 || !iswspace__ (mbc))
 	    break;
 
 	 s += len;
@@ -393,7 +393,7 @@
 	 len = mbtowc__ (&mbc, s, MB_CUR_MAX__);
 	 assert (len >= 0);
 
-	 if (len == 0 || !iswspace (mbc))
+	 if (len == 0 || !iswspace__ (mbc))
 	    break;
 
 	 s += len;
