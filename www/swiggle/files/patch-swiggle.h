--- swiggle.h.orig	Sat Oct 23 22:58:37 2004
+++ swiggle.h	Wed Nov  1 15:43:27 2006
@@ -72,7 +72,7 @@
 };
 
 void	create_html(char *, struct imginfo *, int);
-int	create_thumbindex(char *, struct imginfo *, int);
+int	create_thumbindex(char *, struct imginfo *, int, int);
 
 int resize_bicubic(struct jpeg_decompress_struct *,
     struct jpeg_compress_struct *, const unsigned char *, unsigned char **);
