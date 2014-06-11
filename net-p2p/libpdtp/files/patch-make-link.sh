--- ./make-link.sh.orig	2014-06-11 23:57:05.342462423 +0900
+++ ./make-link.sh	2014-06-11 23:57:14.220461623 +0900
@@ -6,7 +6,7 @@
 	LDFLAGS="-lpthread"
 ;;
 FreeBSD|OpenBSD|NetBSD)
-	LD=gcc
+	LD=${CC}
 	LDFLAGS="-pthread"
 ;;	
 SunOS)
