diff --git a/bacula/src/filed/bxattr_freebsd.c b/bacula/src/filed/bxattr_freebsd.c
index b83331fc578ebc6caf74ff1bf5e67e49329394be..ed2efad02cf2b4f1d1437b25962d28a4d326b873 100644
--- src/filed/bxattr_freebsd.c
+++ src/filed/bxattr_freebsd.c
@@ -103,7 +103,7 @@ bRC_BXATTR BXATTR_FreeBSD::os_backup_xattr (JCR *jcr, FF_PKT *ff_pkt){
          case bRC_BXATTR_skip:
          case bRC_BXATTR_cont:
             /* no xattr available, so skip rest of it */
-            rc = bRC_XACL_ok;
+            rc = bRC_BXATTR_ok;
             continue;
          default:
             goto bail_out;
