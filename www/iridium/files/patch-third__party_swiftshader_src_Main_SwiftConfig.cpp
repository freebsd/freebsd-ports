--- third_party/swiftshader/src/Main/SwiftConfig.cpp.orig	2018-07-19 21:23:23.845651000 +0200
+++ third_party/swiftshader/src/Main/SwiftConfig.cpp	2018-07-19 21:24:08.531304000 +0200
@@ -762,7 +762,11 @@
 		struct stat status;
 		int lastModified = ini.getInteger("LastModified", "Time", 0);
 
+#if !defined(__FreeBSD__)
 		bool noConfig = stat("SwiftShader.ini", &status) != 0;
+#else
+                bool noConfig = false;
+#endif
 		newConfig = !noConfig && abs((int)status.st_mtime - lastModified) > 1;
 
 		if(disableServerOverride)
