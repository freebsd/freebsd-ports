--- snmplib/oid_stash.c.orig	Mon Jan 24 09:43:04 2005
+++ snmplib/oid_stash.c	Mon Jan 24 09:43:14 2005
@@ -5,10 +5,6 @@
 #include <stdlib.h>
 #include <sys/types.h>
 
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
-
 #include <net-snmp/net-snmp-includes.h>
 
 /** @defgroup oid_stash Store and retrieve data referenced by an OID.
