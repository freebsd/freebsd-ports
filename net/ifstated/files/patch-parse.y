--- parse.y	18 Nov 2004 21:43:12 -0000	1.1.1.1
+++ parse.y	18 Nov 2004 21:48:39 -0000	1.2
@@ -1,4 +1,5 @@
 /*	$OpenBSD: parse.y,v 1.7 2004/04/28 01:00:50 deraadt Exp $	*/
+/*	$Id: parse.y,v 1.2 2004/11/18 21:48:39 mdg Exp $	*/

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

