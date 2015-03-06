--- src/idecrypt.c.orig	2015-02-28 20:14:56.633084000 +0100
+++ src/idecrypt.c	2015-02-28 20:19:20.661476344 +0100
@@ -100,8 +100,8 @@
     char buf1[40], buf2[40];
     struct sockaddr_gen ip_local, ip_remote;
     int keyfile_fd;
-    des_cblock key_bin;
-    des_key_schedule sched;
+    DES_cblock key_bin;
+    DES_key_schedule sched;
     static char readable[256];
     
 
@@ -118,8 +118,8 @@
     while (read(keyfile_fd, keybuf, sizeof(keybuf)-1) == sizeof(keybuf)-1)
     {
 	keybuf[sizeof(keybuf)-1] = '\0';
-	des_string_to_key(keybuf, &key_bin);
-	des_set_key(&key_bin, sched);
+	DES_string_to_key(keybuf, &key_bin);
+	DES_set_key(&key_bin, &sched);
 
 	count = (len == 32) ? 24 : 48;
 	for (i = 0, j = 0; i < count; i += 3, j += 4)
@@ -131,15 +131,15 @@
 
 	count = (len == 32) ? 2 : 8;
 	for (i = count; i >= 0; i -= 2) {
-	    des_ecb_encrypt((des_cblock *)&(r.longs[i+2]),
-			    (des_cblock *)&(r.longs[i+2]),
-			    sched, DES_DECRYPT);
+	    DES_ecb_encrypt((DES_cblock *)&(r.longs[i+2]),
+			    (DES_cblock *)&(r.longs[i+2]),
+			    &sched, DES_DECRYPT);
 	    r.longs[i+2] ^= r.longs[i  ];
 	    r.longs[i+3] ^= r.longs[i+1];
 	}
-	des_ecb_encrypt((des_cblock *)&(r.longs[0]),
-			(des_cblock *)&(r.longs[0]),
-			sched, DES_DECRYPT);
+	DES_ecb_encrypt((DES_cblock *)&(r.longs[0]),
+			(DES_cblock *)&(r.longs[0]),
+			&sched, DES_DECRYPT);
 
 	count = (len == 32) ? 6 : 12;
 	for (i = 1; i < count; i++)
