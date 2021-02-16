--- ansi.c.orig	2020-02-05 12:09:38.000000000 -0800
+++ ansi.c	2021-02-14 11:10:31.759160000 -0800
@@ -692,10 +692,6 @@
 		    }
 		  curr->w_rend.font = 0;
 		}
-#  ifdef DW_CHARS
-	      if (curr->w_encoding == UTF8 && utf8_isdouble(c))
-		curr->w_mbcs = 0xff;
-#  endif
 	      if (curr->w_encoding == UTF8 && c >= 0x0300 && utf8_iscomb(c))
 		{
 		  int ox, oy;
@@ -730,6 +726,10 @@
 		    }
 		  break;
 		}
+#  ifdef DW_CHARS
+	      if (curr->w_encoding == UTF8 && utf8_isdouble(c))
+		curr->w_mbcs = 0xff;
+#  endif
 	      font = curr->w_rend.font;
 # endif
 # ifdef DW_CHARS
