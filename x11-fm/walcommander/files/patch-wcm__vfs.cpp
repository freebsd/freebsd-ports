--- wcm/vfs.cpp.orig	2014-08-29 02:25:10.000000000 +0400
+++ wcm/vfs.cpp	2014-08-29 19:14:40.984519553 +0400
@@ -988,7 +988,14 @@
 #include <sys/types.h>
 #include <dirent.h>
 #include <sys/time.h>
-#include <sys/statfs.h>
+
+// for statfs()
+#ifdef __linux__
+#  include <sys/statfs.h>
+#elif defined __FreeBSD__
+#  include <sys/param.h>
+#  include <sys/mount.h>
+#endif
 
 #ifdef __linux__
 #  define OPENFLAG_LARGEFILE (O_LARGEFILE)
@@ -1211,6 +1218,7 @@
 
 int64 FSSys::GetFileSystemFreeSpace( FSPath& path, int* err )
 {
+#ifdef __linux__
 	struct statfs64 s;
 
 	if ( statfs64( path.GetUtf8(), &s ) == -1 )
@@ -1218,6 +1226,16 @@
 		SetError( err, errno );
 		return -1;
 	}
+#else
+	// FreeBSD and probably other systems have 64 bit support in regular statfs
+	struct statfs s;
+
+	if ( statfs( path.GetUtf8(), &s ) == -1 )
+	{
+		SetError( err, errno );
+		return -1;
+	}
+#endif
 
 	return ( int64 )( s.f_bfree ) * ( int64 )( s.f_bsize );
 }
