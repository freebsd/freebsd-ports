--- rtjpeg/RTjpeg.c.orig	2001-06-21 23:26:50.000000000 +0200
+++ rtjpeg/RTjpeg.c	2007-11-15 22:52:31.000000000 +0100
@@ -153,7 +153,7 @@
 // return 2;
 
  // first byte allways written
- (__u8)strm[0]=
+ strm[0]=
       (__u8)(data[RTjpeg_ZZ[0]]>254) ? 254:((data[RTjpeg_ZZ[0]]<0)?0:data[RTjpeg_ZZ[0]]);
 
 
@@ -163,7 +163,7 @@
  bitten = ((unsigned char)ci) << 2;
 
  if (ci==0) {
-   (__u8)strm[1]= bitten; 
+   strm[1]= bitten; 
    co = 2;
    return (int)co;
  }
@@ -192,7 +192,7 @@
    }
 
    if( bitoff == 0 ) {
-      (__u8)strm[co]= bitten; 
+      strm[co]= bitten; 
       bitten = 0;
       bitoff = 8; 
       co++;
@@ -204,7 +204,7 @@
  /* ci must be 0 */
  if(bitoff != 6) {
 
-      (__u8)strm[co]= bitten; 
+      strm[co]= bitten; 
       co++;
      
  }
@@ -221,7 +221,7 @@
    break;
  case 2:
  case 0:
-   (__u8)strm[co]= bitten; 
+   strm[co]= bitten; 
    bitoff = 4;
    co++;
    bitten = 0; // clear half nibble values in bitten
@@ -242,7 +242,7 @@
    bitten |= (ZZvalue&0xf)<<bitoff;
 
    if( bitoff == 0 ) {
-      (__u8)strm[co]= bitten; 
+      strm[co]= bitten; 
       bitten = 0;
       bitoff = 8;
       co++;
@@ -252,14 +252,14 @@
  
  /* ci must be 0 */
  if( bitoff == 0 ) {
-    (__u8)strm[co]= bitten; 
+    strm[co]= bitten; 
     co++;
  }  
  goto BAUCHWEH;
 
 HIRNWEH:
 
- (__u8)strm[co]= bitten; 
+ strm[co]= bitten; 
  co++;
   
 
@@ -352,7 +352,7 @@
     data[i]= 0;
     break;
   default: 
-	
+    break;
   } 
 
   if( bitoff == 0 ) {
