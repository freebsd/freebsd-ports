--- tmate-ssh-server.c.orig	2016-04-26 08:05:24 UTC
+++ tmate-ssh-server.c
@@ -7,6 +7,8 @@
 #include <stdio.h>
 #include <event.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/signal.h>
 
 #include "tmate.h"
 
