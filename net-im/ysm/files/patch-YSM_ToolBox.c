--- src/YSM_ToolBox.c.orig	Wed Nov 13 18:26:47 2002
+++ src/YSM_ToolBox.c	Wed Nov 13 18:28:38 2002
@@ -468,7 +468,7 @@
 		return 1;
 	}
 
-	bytes_res = iconv(conv_d, &inptr,
+	bytes_res = iconv(conv_d, (const char **)&inptr,
 					 &bytes_in, &outptr, &bytes_out);
 	iconv_close(conv_d);
 
