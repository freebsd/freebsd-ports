--- erpcd/env_parser.c.orig	Fri Apr  3 15:36:47 1998
+++ erpcd/env_parser.c	Thu Sep 18 20:10:32 2003
@@ -29,6 +29,8 @@
 #include <netinet/in.h>
 #include <netdb.h>
 #include <net/if.h>
+#include <net/if_var.h>
+#include <netinet/in.h>
 #include <netinet/in_var.h>
 #include <netinet/if_ether.h>
 #include <syslog.h>
