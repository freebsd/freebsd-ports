--- ./src/broker/log.h.orig	Fri Mar 21 17:20:01 1997
+++ ./src/broker/log.h	Fri Aug  1 13:24:58 2003
@@ -147,8 +147,9 @@
 #define L_CONNECT_S    	"CONNECTION"
 
 /* ========== Logging Macros ========= */
-
+#ifndef __STRICT_ANSI__
 int LOG_statlog();
+#endif
 
 #define LOGUPDATE(X) \
 	{LOG_statlog(L_UPDATE,L_UPDATE_S,(X)->url,(X)->FD,(X)->GID);}
