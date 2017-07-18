--- src/main.cpp.orig	2017-07-16 12:33:33 UTC
+++ src/main.cpp
@@ -322,3 +322,10 @@ int main(int argc, char* argv[])
     delete a;
     return errorcode;
 }
+
+// Missing in libxccrt.so function __cxa_deleted_virtual, see FreeBSD Bug#200863
+extern "C" void __cxa_deleted_virtual()
+{
+  abort();
+}
+
