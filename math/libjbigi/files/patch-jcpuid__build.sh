--- jcpuid/build.sh.orig	Fri Dec 23 09:42:02 2005
+++ jcpuid/build.sh	Fri Dec 23 09:43:45 2005
@@ -20,7 +20,6 @@
 mkdir lib/freenet/support
 mkdir lib/freenet/support/CPUInformation
 
-CC="gcc"
 
 case `uname -sr` in
 MINGW*)
@@ -30,9 +29,9 @@
 	LINKFLAGS="-shared -static -static-libgcc -Wl,--kill-at"
 	LIBFILE="lib/freenet/support/CPUInformation/jcpuid-x86-windows.dll";;
 FreeBSD*)
-	COMPILEFLAGS="-Wall"
+	COMPILEFLAGS="-Wall ${CFLAGS}"
 	INCLUDES="-I. -Iinclude -I$JAVA_HOME/include/ -I$JAVA_HOME/include/freebsd/"
-	LINKFLAGS="-shared -static -Wl,-soname,libjcpuid-x86-freebsd.so"
+	LINKFLAGS="-shared -Wl,-soname,libjcpuid-x86-freebsd.so ${LDFLAGS}"
 	LIBFILE="lib/freenet/support/CPUInformation/libjcpuid-x86-freebsd.so";;
 Linux*)
 	COMPILEFLAGS="-fPIC -Wall"
