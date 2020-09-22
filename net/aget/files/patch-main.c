--- main.c.orig	2009-05-12 05:41:23 UTC
+++ main.c
@@ -15,6 +15,9 @@
 #include "main.h"
 #include <errno.h>
 
+sigset_t signal_set;
+time_t  t_start, t_finish;
+
 int main(int argc, char **argv)
 {
 	extern char *optarg;
