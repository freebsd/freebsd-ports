--- bench.c.orig	2009-04-10 18:15:06.000000000 +0200
+++ bench.c	2009-04-10 18:15:19.000000000 +0200
@@ -13,6 +13,7 @@
 #include <errno.h>
 #include <buffer.h>
 #include <fcntl.h>
+#include <string.h>
 
 void usage() {
   die(0,"usage: bench [-n requests] [-c concurrency] [-t timeout] [-k] [-K count]\n"
