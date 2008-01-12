--- src/YSM_Charset.c.orig	2008-01-12 22:33:08.000000000 +0300
+++ src/YSM_Charset.c	2008-01-12 22:33:31.000000000 +0300
@@ -75,9 +75,9 @@
 		}
 	}
 	
-	ASCII_2_ucs4 = iconv_open("UCS4","ASCII");
-	input_2_ucs4 = iconv_open("UCS4",charset_from);
-	ucs4_2_output = iconv_open(charset_to,"UCS4");
+	ASCII_2_ucs4 = iconv_open("UCS-4","ASCII");
+	input_2_ucs4 = iconv_open("UCS-4",charset_from);
+	ucs4_2_output = iconv_open(charset_to,"UCS-4");
 	
 	if ((ASCII_2_ucs4 == (iconv_t)(-1))
 	|| (input_2_ucs4 == (iconv_t)(-1))
