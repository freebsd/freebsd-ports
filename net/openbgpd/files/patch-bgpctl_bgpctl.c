--- bgpctl/bgpctl.c	28 Aug 2006 05:28:49 -0000	1.110
+++ bgpctl/bgpctl.c	8 Feb 2007 10:32:19 -0000
@@ -29,13 +29,13 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
-#include <util.h>
 
 #include "bgpd.h"
 #include "session.h"
 #include "rde.h"
 #include "log.h"
 #include "parser.h"
+#include "util.h"
 
 enum neighbor_views {
 	NV_DEFAULT,
Index: fmt_scaled.c
===================================================================
RCS file: fmt_scaled.c
diff -N fmt_scaled.c
