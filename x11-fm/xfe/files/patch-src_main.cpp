--- src/main.cpp.orig	2025-01-24 08:42:30 UTC
+++ src/main.cpp
@@ -389,6 +389,11 @@ int main(int argc, char* argv[])
     textdomain(PACKAGE);
 #endif
 
+#if defined(__FreeBSD__)
+    FXuint pkg_format;
+    pkg_format = OTHER_PKG;
+#endif
+
 #if defined(linux)
     // For package query on Linux systems, try to guess if the default package format is deb or rpm:
     //   - if dpkg exists then the system uses deb packages
