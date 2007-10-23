--- src/libktorrent/util/fileops.cpp.orig	2007-10-22 18:18:51.000000000 +0200
+++ src/libktorrent/util/fileops.cpp	2007-10-22 18:35:28.000000000 +0200
@@ -425,7 +425,7 @@
 		if (statvfs(path.local8Bit(), &stfs) == 0)
 #endif
 		{
-			bytes_free = ((Uint64)stfs.f_bavail) * ((Uint64)stfs.f_bsize);
+			bytes_free = ((Uint64)stfs.f_bavail) * ((Uint64)stfs.f_frsize);
 			return true;
 		}
 		else
