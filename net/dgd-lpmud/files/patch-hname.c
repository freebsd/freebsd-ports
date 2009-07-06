$FreeBSD$

--- hname.c.orig	2009-07-03 21:47:49.000000000 -0700
+++ hname.c	2009-07-03 21:48:39.000000000 -0700
@@ -5,6 +5,8 @@
 # include <arpa/inet.h>
 # include <netdb.h>
 # include <stdio.h>
+# include <stdlib.h>
+# include <string.h>
 
 int main(argc, argv)
 int argc;
