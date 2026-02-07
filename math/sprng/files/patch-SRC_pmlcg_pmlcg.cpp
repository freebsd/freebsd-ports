--- SRC/pmlcg/pmlcg.cpp.orig	2018-10-22 19:39:18 UTC
+++ SRC/pmlcg/pmlcg.cpp
@@ -853,14 +853,14 @@ int PMLCG::unpack_rng(char *packed)
   p += load_long64(p,8,&mult);
   p += load_long64(p,8,&x);
 #else  /* No 64 bit type available */
-  p += load_int(p,4,&a_size);
+  p += load_int(p,4,(unsigned int *)&a_size);
 
-  p += load_intarray(p,2,4,&m);
-  r[1] = m[1]&0xffffff; 
+  p += load_intarray(p,2,4,(unsigned int *)&m);
+  r[1] = m[1]&0xffffff;
   r[0] = m[1]>>24 | m[0]<<8;
-  
-  p += load_intarray(p,2,4,&m);  
-  a[1] = m[1]&0xffffff; 
+
+  p += load_intarray(p,2,4,(unsigned int *)&m);
+  a[1] = m[1]&0xffffff;
   a[0] = m[1]>>24 | m[0]<<8;
 #endif
 
