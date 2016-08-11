--- src/main.cpp.orig	2016-04-24 12:44:18 UTC
+++ src/main.cpp
@@ -303,3 +303,10 @@ int main(int argc, char *argv[])
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
