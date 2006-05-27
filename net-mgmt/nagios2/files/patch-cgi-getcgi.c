--- cgi/getcgi.c.orig	Thu Apr 13 04:47:23 2006
+++ cgi/getcgi.c	Sun May 21 01:14:04 2006
@@ -10,6 +10,7 @@
 #include "../include/getcgi.h"
 #include <stdio.h>
 #include <stdlib.h>
+#include <limits.h>
 
 
 #undef PARANOID_CGI_INPUT
