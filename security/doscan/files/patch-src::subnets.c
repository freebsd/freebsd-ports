--- src/subnets.c.orig	Wed Sep 24 13:28:27 2003
+++ src/subnets.c	Wed Sep 24 13:29:59 2003
@@ -37,7 +37,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 
 static ipv4_prefix_t *subnets = 0;
 /* list of subnets, terminated by the 0/0 prefix */
