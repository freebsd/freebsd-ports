--- ./src/api/auditimpl.h.orig	2014-09-01 14:22:29.528842989 -0400
+++ ./src/api/auditimpl.h	2014-09-01 14:22:55.741771989 -0400
@@ -18,6 +18,7 @@
 #ifndef ZORBA_API_AUDIT_IMPL_H
 #define ZORBA_API_AUDIT_IMPL_H
 
+#include <sys/types.h>
 #include <zorba/audit.h>
 #include <zorba/audit_scoped.h>
 #include <map>
