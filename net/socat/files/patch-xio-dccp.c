--- xio-dccp.c.orig	2023-11-13 19:31:08 UTC
+++ xio-dccp.c
@@ -5,6 +5,9 @@
 /* this file contains the source for DCCP related functions and options */
 
 #include "xiosysincludes.h"
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #if WITH_DCCP
 
@@ -13,6 +16,10 @@
 #include "xio-ip4.h"
 #include "xio-ipapp.h"
 #include "xio-dccp.h"
+
+#ifndef SOCK_DCCP
+#define SOCK_DCCP 6
+#endif
 
 /****** DCCP addresses ******/
 
