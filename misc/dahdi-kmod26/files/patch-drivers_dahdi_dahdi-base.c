--- drivers/dahdi/dahdi-base.c.orig	2014-05-10 07:54:19 UTC
+++ drivers/dahdi/dahdi-base.c
@@ -106,6 +106,7 @@
 #if defined(__FreeBSD__)
 #include <sys/filio.h>
 #include <sys/proc.h>
+#include <sys/eventhandler.h>
 
 #include "ng_dahdi_iface.h"
 
