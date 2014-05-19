--- ./src/os_crypto/sha1/md32_common.h.orig	2013-10-29 12:13:44.000000000 -0600
+++ ./src/os_crypto/sha1/md32_common.h	2014-04-21 19:52:35.000000000 -0600
@@ -607,7 +607,7 @@
 	}
 
 #ifndef MD32_REG_T
-#define MD32_REG_T long
+#define MD32_REG_T int
 /*
  * This comment was originaly written for MD5, which is why it
  * discusses A-D. But it basically applies to all 32-bit digests,
