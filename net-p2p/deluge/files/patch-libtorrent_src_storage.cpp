--- libtorrent/src/storage.cpp.orig	2007-08-06 17:01:24.000000000 -0500
+++ libtorrent/src/storage.cpp	2007-08-06 17:05:26.000000000 -0500
@@ -981,7 +981,7 @@
 			return true;
 #endif
 
-#if defined(__APPLE__) || defined(__linux__)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
 		// find the last existing directory of the save path
 		fs::path query_path = p;
 		while (!query_path.empty() && !exists(query_path))
@@ -1058,7 +1058,11 @@
 #endif
 
 		// TODO: POSIX implementation
+#if defined(__FreeBSD__)
+		return true;
+#else
 		return false;
+#endif
 	}
 
 	// -- piece_manager -----------------------------------------------------
