--- cyberflex.c.orig	2003-06-20 00:37:35.000000000 +0200
+++ cyberflex.c	2015-02-28 15:57:55.093727371 +0100
@@ -48,7 +48,13 @@
 #define SHA1Init SHA1_Init
 #define SHA1Update SHA1_Update
 #define SHA1Final SHA1_Final
-#else /* __linux */
+#elif defined(__FreeBSD__)
+#define SHA1_CTX SHA_CTX
+#define SHA1Init SHA1_Init
+#define SHA1Update SHA1_Update
+#define SHA1Final SHA1_Final
+#include <openssl/sha.h>
+#else
 #include <sha1.h>
 #endif
 #else
@@ -69,7 +75,7 @@
 #include "sc.h"
 
 #ifdef __sun
-#define des_set_key(key, schedule) des_key_sched(key, schedule)
+#define DES_set_key(key, &schedule) DES_key_sched(key, &schedule)
 #endif
 
 #define JDIRSIZE 40
@@ -91,7 +97,7 @@
 
 #ifndef __palmos__
 /* default signed applet key of Cyberflex Access */
-static des_cblock app_key = {0x6A, 0x21, 0x36, 0xF5, 0xD8, 0x0C, 0x47, 0x83};
+static DES_cblock app_key = {0x6A, 0x21, 0x36, 0xF5, 0xD8, 0x0C, 0x47, 0x83};
 #endif
 
 static int
@@ -663,8 +669,8 @@
     unsigned char aid[16], app_data[MAX_APP_SIZE], data[MAX_BUF_SIZE];
     int i, j, vflag = 0, gotprog = 0, gotcont = 0, fd_app, size, aidlen = 0, sw;
     int cont_size = 1152, inst_size = 1024;
-    des_cblock tmp;
-    des_key_schedule schedule;
+    DES_cblock tmp;
+    DES_key_schedule schedule;
     static unsigned char acl[] = {0x81, 0, 0, 0xff, 0, 0, 0, 0};
 
     optind = optreset = 1;
@@ -777,12 +783,12 @@
     /* chain.  DES encrypt one block, XOR the cyphertext with the next block,
        ... continues until the end of the buffer */
 
-    des_set_key (&app_key, schedule);
+    DES_set_key (&app_key, &schedule);
 
     for (i = 0; i < size/BLOCK_SIZE; i++) {
 	for (j = 0; j < BLOCK_SIZE; j++)
 	    tmp[j] = tmp[j] ^ app_data[i*BLOCK_SIZE + j];
-	des_ecb_encrypt (&tmp, &tmp, schedule, DES_ENCRYPT);
+	DES_ecb_encrypt (&tmp, &tmp, &schedule, DES_ENCRYPT);
     }
 
     if (vflag) {
