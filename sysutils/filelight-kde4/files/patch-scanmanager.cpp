--- src/scanmanager.cpp.orig	Wed Jan 14 01:58:11 2004
+++ src/scanmanager.cpp	Wed Jan 14 02:03:36 2004
@@ -29,7 +29,11 @@
 //readMounts()
 #include <fstab.h>
 #include <mntent.h>
+#ifdef __FreeBSD__
+#include "mntent_compat.cpp"
+#else
 #include <sys/statfs.h>
+#endif
 
 #include "scanmanager.h"
 #include "filetree.h"
@@ -359,7 +363,7 @@
 
 
 
-static int selector( struct DIRENT const *ent )
+static int selector( struct DIRENT *ent )
 {
   if( strcmp( ent->d_name, "." ) == 0 || strcmp( ent->d_name, ".." ) == 0 )
     return 0;
