--- tools/libxc/xc_dom_bzimageloader.c.orig	2015-11-03 09:11:18 UTC
+++ tools/libxc/xc_dom_bzimageloader.c
@@ -469,7 +469,7 @@ static int xc_try_lzo1x_decode(
 
     for ( *size = 0; ; )
     {
-        lzo_uint src_len, dst_len, out_len;
+        lzo_uint src_len, dst_len, out_len = 0;
         unsigned char *tmp_buf;
 
         msg = "Short input";
