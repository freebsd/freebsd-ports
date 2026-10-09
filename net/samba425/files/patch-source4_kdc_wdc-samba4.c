--- source4/kdc/wdc-samba4.c.orig	2026-01-20 15:42:54 UTC
+++ source4/kdc/wdc-samba4.c
@@ -22,6 +22,10 @@
 */
 
 #include "includes.h"
+
+#include <gssapi/gssapi.h>
+#include <gssapi/gssapi_krb5.h>
+
 #include "kdc/authn_policy_util.h"
 #include "kdc/kdc-glue.h"
 #include "kdc/db-glue.h"
@@ -29,6 +33,11 @@
 #include "sdb.h"
 #include "sdb_hdb.h"
 #include "librpc/gen_ndr/auth.h"
+
+#ifndef PACKAGE_NAME
+#define PACKAGE_NAME "Heimdal"
+#endif
+
 #include <krb5_locl.h>
 #include "lib/replace/system/filesys.h"
 
