--- src/nettle/des-compat.c.orig	Tue Sep 25 19:22:10 2001
+++ src/nettle/des-compat.c	Wed Dec 18 05:27:13 2002
@@ -61,7 +61,14 @@
 		 des_key_schedule k1, des_key_schedule k2,
 		 des_key_schedule k3, int enc)
 {
+#ifndef __FreeBSD__
   struct des_compat_des3 keys = { { k1, k2, k3 } };
+#else
+  struct des_compat_des3 keys;
+  keys.keys[1] = k1;
+  keys.keys[2] = k1;
+  keys.keys[3] = k3;
+#endif
 
   ((enc == DES_ENCRYPT) ? des_compat_des3_encrypt : des_compat_des3_decrypt)
     (&keys, DES_BLOCK_SIZE, *dst, *src);
@@ -142,7 +149,14 @@
 		     des_cblock *iv,
 		     int enc)
 {
+#ifndef __FreeBSD__
   struct des_compat_des3 keys = { { k1, k2, k3 } };
+#else
+  struct des_compat_des3 keys;
+  keys.keys[1] = k1;
+  keys.keys[2] = k1;
+  keys.keys[3] = k3;
+#endif
 
   switch (enc)
     {
