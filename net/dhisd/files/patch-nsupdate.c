--- nsupdate.c.orig	Mon Mar 19 22:23:40 2001
+++ nsupdate.c	Mon Mar 19 22:55:46 2001
@@ -28,8 +28,17 @@
 
 
 #include"dhisd.h"
-#ifndef	BIND821
-#include <res_update.h>
+
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
+#if (defined(BSD) && (BSD >= 199306))
+#  include <arpa/nameser.h>
+#else
+#  if !defined BIND821
+#    include <res_update.h>
+#  endif
 #endif
 
 int dns_update(unsigned char *r_dname,int r_opcode,short int r_type,
@@ -53,7 +62,7 @@
 	rrecp->r_size=r_size;
 	if(r_size>0) strcpy(rrecp->r_data,r_data);
 
-#ifndef	BIND821
+#if !defined(BIND821) && !defined(BSD)
 	rrecp->r_link.prev=NULL;
 	rrecp->r_link.next=NULL;
 #else
