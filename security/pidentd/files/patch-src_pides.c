--- src/pdes.c.orig	2015-02-28 20:14:56.633084000 +0100
+++ src/pdes.c	2015-02-28 20:17:14.869504878 +0100
@@ -46,7 +46,7 @@
 
 
 
-static des_key_schedule sched;
+static DES_key_schedule sched;
 
 
 
@@ -55,7 +55,7 @@
 {
     char keybuf[1024+1];
     int fd, res;
-    des_cblock key_bin;
+    DES_cblock key_bin;
 
 
     if (keyfile == NULL)
@@ -100,8 +100,8 @@
     }
 
     keybuf[sizeof(keybuf)-1] = '\0';
-    des_string_to_key(keybuf, &key_bin);
-    des_set_key(&key_bin, sched);
+    DES_string_to_key(keybuf, &key_bin);
+    DES_set_key(&key_bin, &sched);
 
     return 0;
 }
@@ -162,16 +162,16 @@
     for (i = 1; i < count; i++)
 	r.longs[0] ^= r.longs[i];
 
-    des_ecb_encrypt((des_cblock *)&(r.longs[0]), (des_cblock *)&(r.longs[0]),
-		    sched, DES_ENCRYPT);
+    DES_ecb_encrypt((DES_cblock *)&(r.longs[0]), (DES_cblock *)&(r.longs[0]),
+		    &sched, DES_ENCRYPT);
 
     count = (family == AF_INET) ? 4 : 10;
     for (i = 0; i < count; i += 2) {
 	r.longs[i+2] ^= r.longs[i  ];
 	r.longs[i+3] ^= r.longs[i+1];
 
-	des_ecb_encrypt((des_cblock *)&(r.longs[i+2]),
-			(des_cblock *)&(r.longs[i+2]), sched, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock *)&(r.longs[i+2]),
+			(DES_cblock *)&(r.longs[i+2]), &sched, DES_ENCRYPT);
     }
 
     count = (family == AF_INET) ? 24 : 48;
