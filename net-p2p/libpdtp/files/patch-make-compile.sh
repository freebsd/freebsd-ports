--- ./make-compile.sh.orig	2014-06-11 23:56:44.234462034 +0900
+++ ./make-compile.sh	2014-06-11 23:56:59.164462439 +0900
@@ -11,7 +11,7 @@
 	CFLAGS="-ansi -pedantic -fpic -g -Wall -D_GNU_SOURCE"
 ;;
 FreeBSD|OpenBSD|NetBSD)
-	CC=gcc
+	CC=${CC}
 	CFLAGS="-ansi -pedantic -fpic -g -Wall"
 ;;
 SunOS)
