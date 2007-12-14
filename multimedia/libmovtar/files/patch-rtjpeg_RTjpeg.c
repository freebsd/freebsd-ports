--- rtjpeg/RTjpeg.c.orig	2007-12-12 22:20:39.000000000 +0100
+++ rtjpeg/RTjpeg.c	2007-12-12 22:21:15.000000000 +0100
@@ -129,7 +129,7 @@
  register int ci, co=1, tmp;
  register __s16 ZZvalue;
 
- (__u8)strm[0]=(__u8)(data[RTjpeg_ZZ[0]]>254) ? 254:((data[RTjpeg_ZZ[0]]<0)?0:data[RTjpeg_ZZ[0]]);
+ strm[0]=(__u8)(data[RTjpeg_ZZ[0]]>254) ? 254:((data[RTjpeg_ZZ[0]]<0)?0:data[RTjpeg_ZZ[0]]);
  
  for(ci=1; ci<=bt8; ci++) 
  {
