--- kpackage/rpmMessages.c.orig	Wed Mar 28 18:43:45 2001
+++ kpackage/rpmMessages.c	Wed Mar 28 18:43:55 2001
@@ -7,7 +7,6 @@
 #include <stdio.h>
 #include <string.h>
 /* stupid RPM headers! */
-typedef __off64_t off64_t;
 #include <rpm/rpmlib.h>
 #include "rpmMessages.h"
 
