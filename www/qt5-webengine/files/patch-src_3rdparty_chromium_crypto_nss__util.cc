--- src/3rdparty/chromium/crypto/nss_util.cc.orig	2017-04-23 10:32:17 UTC
+++ src/3rdparty/chromium/crypto/nss_util.cc
@@ -15,7 +15,7 @@
 
 #include "crypto/nss_util_internal.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_BSD)
 #include <sys/mount.h>
 #include <sys/param.h>
 #endif
@@ -158,10 +158,10 @@ void UseLocalCacheOfNSSDatabaseIfNFS(con
   base::FileSystemType fs_type = base::FILE_SYSTEM_UNKNOWN;
   if (base::GetFileSystemType(database_dir, &fs_type))
     db_on_nfs = (fs_type == base::FILE_SYSTEM_NFS);
-#elif defined(OS_OPENBSD)
+#elif defined(OS_BSD)
   struct statfs buf;
   if (statfs(database_dir.value().c_str(), &buf) == 0)
-    db_on_nfs = (strcmp(buf.f_fstypename, MOUNT_NFS) == 0);
+    db_on_nfs = (strcmp(buf.f_fstypename, "nfs") == 0);
 #else
   NOTIMPLEMENTED();
 #endif
