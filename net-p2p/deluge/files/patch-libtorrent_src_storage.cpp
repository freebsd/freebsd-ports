--- libtorrent/src/storage.cpp.orig	2007-08-11 01:51:04.000000000 -0500
+++ libtorrent/src/storage.cpp	2007-08-11 01:52:15.000000000 -0500
@@ -1027,7 +1027,7 @@
 		return false;
 #endif
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__)
 		struct statfs buf;
 		int err = statfs(query_path.native_directory_string().c_str(), &buf);
 		if (err == 0)
@@ -1060,7 +1060,11 @@
 #endif
 
 		// TODO: POSIX implementation
+#if defined(__FreeBSD__)
+		return true;
+#else
 		return false;
+#endif
 	}
 
 	// -- piece_manager -----------------------------------------------------
