--- src/3rdparty/gn/tools/gn/args.cc.orig	2019-10-27 19:20:40.465677000 +0100
+++ src/3rdparty/gn/tools/gn/args.cc	2019-10-27 19:21:07.759511000 +0100
@@ -332,7 +332,7 @@
     arch = kMips64;
   else if (os_arch == "s390x")
     arch = kS390X;
-  else if (os_arch == "ppc64" || os_arch == "ppc64le")
+  else if (os_arch == "ppc64" || os_arch == "ppc64le" || os_arch == "powerpc")
     // We handle the endianness inside //build/config/host_byteorder.gni.
     // This allows us to use the same toolchain as ppc64 BE
     // and specific flags are included using the host_byteorder logic.
