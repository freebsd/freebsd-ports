--- lfd_lzo.c-	2008-01-07 23:35:35.000000000 +0100
+++ lfd_lzo.c	2008-12-19 17:58:55.293292741 +0100
@@ -103,7 +103,7 @@
  */  
 int comp_lzo(int len, char *in, char **out)
 { 
-     unsigned int zlen = 0;    
+     lzo_uint zlen = 0;    
      int err;
      
      if( (err=lzo1x_compress((void *)in,len,zbuf,&zlen,wmem)) != LZO_E_OK ){
@@ -117,7 +117,7 @@
 
 int decomp_lzo(int len, char *in, char **out)
 {
-     unsigned int zlen = 0;
+     lzo_uint zlen = 0;    
      int err;
 
      if( (err=lzo1x_decompress((void *)in,len,zbuf,&zlen,wmem)) != LZO_E_OK ){
