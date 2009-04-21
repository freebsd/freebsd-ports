--- trafd/traffic.c.orig	2009-04-21 09:32:49.000000000 +0100
+++ trafd/traffic.c	2009-04-21 09:41:46.000000000 +0100
@@ -32,6 +32,7 @@
 
 /*	traffic.c - collect network traffic	*/
 
+#include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
@@ -72,7 +73,7 @@
 static int dlen;
 typedef struct t_entry *p_entry;
 static struct t_entry t;
-static struct timeval begin_time;
+struct timeval begin_time;
 static u_char s_port_big[IPPORT_RESERVED];
 
 /*
