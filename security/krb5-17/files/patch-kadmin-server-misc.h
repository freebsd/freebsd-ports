--- kadmin/server/misc.h.orig	Tue Oct 11 21:09:19 2005
+++ kadmin/server/misc.h	Wed Apr  4 13:53:04 2007
@@ -45,3 +45,5 @@
 #ifdef SVC_GETARGS
 void  kadm_1(struct svc_req *, SVCXPRT *);
 #endif
+
+void trunc_name(size_t *len, char **dots);
