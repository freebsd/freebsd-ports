--- lib/gibber/gibber-tcp-transport.c.orig	2010-10-22 15:15:56 UTC
+++ lib/gibber/gibber-tcp-transport.c
@@ -20,6 +20,7 @@
 
 #include <config.h>
 
+#include <netinet/in.h>
 #include <stdio.h>
 #include <stdlib.h>
 
