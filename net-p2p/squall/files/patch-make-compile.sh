--- make-compile.sh.orig	2014-06-11 23:42:34.333462233 +0900
+++ make-compile.sh	2014-06-11 23:42:45.001462051 +0900
@@ -8,7 +8,7 @@
 	CFLAGS="-D_REENTRANT -D_THREAD_SAFE -g -O3 -Wall"
 ;;
 FreeBSD|OpenBSD|NetBSD)
-        CC=gcc
+        CC=${CC}
         CFLAGS="-D_REENTRANT -D_THREAD_SAFE -ansi -pedantic -g -O3 -Wall"
 ;;
 Linux)
