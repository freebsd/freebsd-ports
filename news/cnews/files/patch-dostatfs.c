--- util/dostatfs.c.orig	1995-04-28 02:51:39.000000000 +0200
+++ util/dostatfs.c	2015-06-10 06:28:42.000000000 +0200
@@ -77,7 +77,7 @@
 long bperi;
 {
 	struct statfs info;
-	register long n;
+	register long long n;
 #	define	LOTS	10000
 	register long iperfile = filesize/bperi + 1;
 
