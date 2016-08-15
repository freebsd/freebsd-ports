--- src/main.cpp.orig	2016-08-09 23:12:33 UTC
+++ src/main.cpp
@@ -306,3 +306,10 @@ int main(int argc, char *argv[])
 #endif
     return errorcode;
 }
+
+// Missing in libxccrt.so function __cxa_deleted_virtual, see FreeBSD Bug#200863
+extern "C" void __cxa_deleted_virtual()
+{
+  abort();
+}
+
