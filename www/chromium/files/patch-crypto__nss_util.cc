--- crypto/nss_util.cc.orig	2015-07-15 16:30:04.000000000 -0400
+++ crypto/nss_util.cc	2015-07-22 07:15:16.577810000 -0400
@@ -13,7 +13,7 @@
 #include <prtime.h>
 #include <secmod.h>
 
-#if defined(OS_OPENBSD)
+#if defined(OS_BSD)
 #include <sys/mount.h>
 #include <sys/param.h>
 #endif
@@ -146,7 +146,7 @@
 // detection when database_dir is on NFS.  See http://crbug.com/48585.
 //
 // TODO(wtc): port this function to other USE_NSS_CERTS platforms.  It is
-// defined only for OS_LINUX and OS_OPENBSD simply because the statfs structure
+// defined only for OS_LINUX and OS_BSD simply because the statfs structure
 // is OS-specific.
 //
 // Because this function sets an environment variable it must be run before we
@@ -157,10 +157,10 @@
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
