--- sort.c.orig	2012-07-04 20:25:12.000000000 +0400
+++ sort.c	2014-01-21 07:18:36.832891740 +0400
@@ -146,7 +146,7 @@
 #define	NUMBER_OF_MUTUALLY_EXCLUSIVE_FLAGS 6
 static const char mutually_exclusive_flags[NUMBER_OF_MUTUALLY_EXCLUSIVE_FLAGS] = { 'M', 'n', 'g', 'R', 'h', 'V' };
 
-struct option long_options[] = {
+static struct option long_options[] = {
 				{ "batch-size", required_argument, NULL, BS_OPT },
 				{ "buffer-size", required_argument, NULL, 'S' },
 				{ "check", optional_argument, NULL, 'c' },
