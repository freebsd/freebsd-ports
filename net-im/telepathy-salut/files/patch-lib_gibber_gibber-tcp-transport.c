--- lib/gibber/gibber-tcp-transport.c.orig	2010-05-20 06:10:39.000000000 -0400
+++ lib/gibber/gibber-tcp-transport.c	2010-07-24 20:42:16.000000000 -0400
@@ -20,6 +20,7 @@
 
 #include <config.h>
 
+#include <netinet/in.h>
 #include <stdio.h>
 #include <stdlib.h>
 
