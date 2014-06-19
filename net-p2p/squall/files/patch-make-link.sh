--- make-link.sh.orig	2014-06-11 23:44:37.727462291 +0900
+++ make-link.sh	2014-06-11 23:47:07.004461915 +0900
@@ -6,7 +6,7 @@
 	LDFLAGS=-lpthread
 ;;
 FreeBSD|OpenBSD|NetBSD)
-	LD=gcc
+	LD=${CC}
 	LDFLAGS=-pthread
 ;;	
 SunOS)
