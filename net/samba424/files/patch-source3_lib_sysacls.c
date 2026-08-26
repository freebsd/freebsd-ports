--- source3/lib/sysacls.c.orig	2025-02-06 10:31:54 UTC
+++ source3/lib/sysacls.c
@@ -38,6 +38,16 @@
 #include "modules/vfs_aixacl.h"
 #endif
 
+/*
+ * NFSv4 ACL's should be understood and a first class citizen. Work
+ * needs to be done in librpc/idl/smb_acl.idl for this to occur.
+ */
+#if defined(HAVE_LIBSUNACL) && defined(FREEBSD)
+#if 0
+#include "modules/nfs4_acls.h"
+#endif
+#endif
+
 #undef  DBGC_CLASS
 #define DBGC_CLASS DBGC_ACLS
 
