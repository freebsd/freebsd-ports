--- etc/afpd/afp_asp.c.orig	2011-07-30 23:13:47.000000000 -0400
+++ etc/afpd/afp_asp.c	2011-07-30 23:14:22.000000000 -0400
@@ -31,9 +31,9 @@
 #include <atalk/atp.h>
 #include <atalk/asp.h>
 #include <atalk/compat.h>
+#include <atalk/globals.h>
 #include <atalk/util.h>
 
-#include "globals.h"
 #include "switch.h"
 #include "auth.h"
 #include "fork.h"
