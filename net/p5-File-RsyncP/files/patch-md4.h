--- Digest/md4.h.orig	Mon Jan 12 10:37:04 2004
+++ Digest/md4.h	Mon Jan 12 10:44:59 2004
@@ -38,6 +38,13 @@
   unsigned char rsyncBug;
 } MD4_CTX;
 
+#define MD4Init myMD4Init
+#define MD4Update myMD4Update
+#define MD4Final myMD4Final
+#define MD4Encode myMD4Encode
+#define MD4FinalRsync myMD4FinalRsync
+#define MD4Decode myMD4Decode
+
 void MD4Init PROTO_LIST ((MD4_CTX *));
 void MD4Update PROTO_LIST
   ((MD4_CTX *, unsigned char *, unsigned int));
