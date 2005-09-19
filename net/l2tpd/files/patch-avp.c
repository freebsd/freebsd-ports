--- avp.c.orig	Mon Aug 19 19:39:27 2002
+++ avp.c	Tue Aug  9 12:29:34 2005
@@ -15,7 +15,6 @@
 #include <string.h>
 #include <stdio.h>
 #include <errno.h>
-#include <netinet/in.h>
 #include "l2tp.h"
 
 #define AVP_MAX 39
@@ -1608,7 +1607,7 @@
             if (AMBIT (avp->length))
             {
                 log (LOG_WARN,
-                     "%s:  dont know how to handle mandatory attribute %d.  Closing %s.\n"
+                     "%s:  dont know how to handle mandatory attribute %d.  Closing %s.\n",
                      __FUNCTION__, avp->attr,
                      (c != t->self) ? "call" : "tunnel");
                 set_error (c, VENDOR_ERROR,
