--- src/main.cpp.orig	2025-04-04 21:41:40 UTC
+++ src/main.cpp
@@ -21,6 +21,13 @@ int main(int argc, char* argv[])
     return errorcode;
 }
 
+// Missing in libxccrt.so function __cxa_deleted_virtual, see FreeBSD Bug#200863
+extern "C" void __cxa_deleted_virtual()
+{
+  abort();
+}
+
+
 #ifdef QT_STATIC
 #if defined(Q_OS_LINUX)
 Q_IMPORT_PLUGIN(QLinuxFbIntegrationPlugin)
