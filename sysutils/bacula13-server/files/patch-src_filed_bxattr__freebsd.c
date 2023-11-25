--- src/filed/bxattr_freebsd.c.orig	2023-10-18 20:41:39 UTC
+++ src/filed/bxattr_freebsd.c
@@ -103,7 +103,7 @@ bRC_BXATTR BXATTR_FreeBSD::os_backup_xattr (JCR *jcr, 
          case bRC_BXATTR_skip:
          case bRC_BXATTR_cont:
             /* no xattr available, so skip rest of it */
-            rc = bRC_XACL_ok;
+            rc = bRC_BXATTR_ok;
             continue;
          default:
             goto bail_out;
