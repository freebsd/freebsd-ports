--- cherokee/handler_cgi_base.c.orig	2009-02-26 00:07:37.000000000 -0900
+++ cherokee/handler_cgi_base.c	2009-03-02 15:03:03.000000000 -0900
@@ -22,6 +22,8 @@
  * 02110-1301, USA.
  */ 
 
+#include <stdlib.h>
+#include <limits.h>
 #include "common-internal.h"
 #include "handler_cgi_base.h"
 
