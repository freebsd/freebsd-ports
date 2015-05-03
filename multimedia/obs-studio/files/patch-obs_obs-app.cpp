--- obs/obs-app.cpp.orig	2015-03-27 21:29:37 UTC
+++ obs/obs-app.cpp
@@ -353,6 +353,8 @@ string OBSApp::GetVersionString() const
 	ver << "windows)";
 #elif __APPLE__
 	ver << "mac)";
+#elif __FreeBSD__
+	ver << "FreeBSD)";
 #else /* assume linux for the time being */
 	ver << "linux)";
 #endif
