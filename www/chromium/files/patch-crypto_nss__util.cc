--- crypto/nss_util.cc.orig	2016-05-11 19:02:22 UTC
+++ crypto/nss_util.cc
@@ -15,7 +15,7 @@
 
 #include "crypto/nss_util_internal.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_BSD)
 #include <sys/mount.h>
 #include <sys/param.h>
 #endif
@@ -147,7 +147,7 @@ char* PKCS11PasswordFunc(PK11SlotInfo* s
 // detection when database_dir is on NFS.  See http://crbug.com/48585.
 //
 // TODO(wtc): port this function to other USE_NSS_CERTS platforms.  It is
-// defined only for OS_LINUX and OS_OPENBSD simply because the statfs structure
+// defined only for OS_LINUX and OS_BSD simply because the statfs structure
 // is OS-specific.
 //
 // Because this function sets an environment variable it must be run before we
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
