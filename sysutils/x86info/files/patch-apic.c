--- apic.c.orig	2011-09-15 15:38:59.000000000 -0700
+++ apic.c	2011-09-15 15:39:09.000000000 -0700
@@ -8,6 +8,7 @@
  */
 
 #include <stdio.h>
+#include <unistd.h>
 #include "apic.h"
 #include "x86info.h"
 
