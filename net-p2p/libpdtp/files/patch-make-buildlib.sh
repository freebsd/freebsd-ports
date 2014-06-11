--- ./make-buildlib.sh.orig	2014-06-11 23:58:17.022462223 +0900
+++ ./make-buildlib.sh	2014-06-11 23:58:26.037461106 +0900
@@ -10,7 +10,7 @@
 	BUILDLIBFLAGS="-lpthread -shared"
 ;;
 FreeBSD|OpenBSD|NetBSD)
-	BUILDLIB=gcc
+	BUILDLIB=${CC}
 	BUILDLIBFLAGS="-pthread -shared"
 ;;	
 SunOS)
