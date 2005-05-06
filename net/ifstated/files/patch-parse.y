--- ../ifstated-20050505.orig/parse.y	Thu May  5 11:51:24 2005
+++ parse.y	Thu May  5 12:06:07 2005
@@ -1,4 +1,5 @@
 /*	$OpenBSD: parse.y,v 1.9 2005/02/07 12:41:53 mcbride Exp $	*/
+/*	$Id: parse.y,v 1.3 2005/05/05 16:06:07 mdg Exp $	*/

 /*
  * Copyright (c) 2004 Ryan McBride <mcbride@openbsd.org>
@@ -24,6 +25,7 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/socket.h>
+#include <sys/limits.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <net/if.h>
@@ -35,7 +37,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <syslog.h>
-#include <event.h>
+#include <sys/event.h>

 #include "ifstated.h"

