--- Intel/cachesize.c.orig	2008-08-09 22:04:12.000000000 +0400
+++ Intel/cachesize.c	2008-08-09 22:04:24.000000000 +0400
@@ -147,6 +147,7 @@
 {
 	{0xf0, 64, "64 byte prefetching."},
 	{0xf1, 64, "128 byte prefetching."},
+	{ 0, 0, NULL }
 };
 
 static unsigned char found_unknown=0;
