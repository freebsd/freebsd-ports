--- xio-tcpwrap.c.orig	2017-01-06 20:58:40 UTC
+++ xio-tcpwrap.c
@@ -27,7 +27,7 @@ const struct optdesc opt_tcpwrap_hosts_deny_table  = {
 
 /* they are declared only externally with libwrap and would be unresolved
    without these definitions */
-int allow_severity=10, deny_severity=10;
+//int allow_severity=10, deny_severity=10;
 
 /* returns 0 if option was found and could be applied
    returns 1 if option was not found
