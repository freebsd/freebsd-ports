
$FreeBSD$

--- cfs.h.orig
+++ cfs.h
@@ -23,6 +23,8 @@
 #include "safer.h"
 #include "cfs_bf.h"
 
+#include <inttypes.h>
+
 #define H_REG 0
 #define H_ATTACH 0	/* same as regular */
 #define H_ROOT 1
@@ -57,10 +59,10 @@
 	u_char magic[8];/* 0x0123456789abcdef */
 	u_short htype;	/* 0=reg, 1=attachpt, 2=root(but notused) */
 	u_short instance;	/* which attach */
-	u_long fileid;	/* inode # */
+	uint32_t fileid;	/* inode # */
 	u_char check[8];/* we just encrypt the date and copy it here */
 #ifdef SHORTLINKS
-	u_long linkid;	/* To uniquify short links */
+	uint32_t linkid;	/* To uniquify short links */
 	u_char pad[4];	/* empty */
 #else
 	u_char pad[8];	/* empty */
