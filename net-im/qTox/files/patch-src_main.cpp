--- src/main.cpp.orig	2015-11-14 22:51:30 UTC
+++ src/main.cpp
@@ -269,3 +269,10 @@ int main(int argc, char *argv[])
     qDebug() << "Clean exit with status"<<errorcode;
     return errorcode;
 }
+
+// Missing in libxccrt.so function __cxa_deleted_virtual, see FreeBSD Bug#200863
+extern "C" void __cxa_deleted_virtual()
+{
+  abort();
+}
+
