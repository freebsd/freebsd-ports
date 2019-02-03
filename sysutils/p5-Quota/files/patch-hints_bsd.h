--- hints/bsd.h.orig	2013-08-15 04:56:14 UTC
+++ hints/bsd.h
@@ -71,8 +71,9 @@
 
 #define NO_MNTENT
 
-#define GQA_TYPE_USR RQUOTA_USRQUOTA
-#define GQA_TYPE_GRP RQUOTA_GRPQUOTA
+/* from https://opensource.apple.com/source/NFS/NFS-63/rpc.rquotad/rquota.h.auto.html */
+#define GQA_TYPE_USR 0x00
+#define GQA_TYPE_GRP 0x01
 #define GQR_STATUS status
 #define GQR_RQUOTA getquota_rslt_u.gqr_rquota
 
