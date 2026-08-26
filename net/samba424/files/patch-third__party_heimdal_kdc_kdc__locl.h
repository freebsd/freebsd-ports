--- third_party/heimdal/kdc/kdc_locl.h.orig	2026-01-20 15:42:56 UTC
+++ third_party/heimdal/kdc/kdc_locl.h
@@ -38,6 +38,10 @@
 #ifndef __KDC_LOCL_H__
 #define __KDC_LOCL_H__
 
+#include "gssapi/gssapi.h"
+#include "gssapi/gssapi_krb5.h"
+#include "gssapi/gssapi_spnego.h"
+
 #include "headers.h"
 
 typedef struct pk_client_params pk_client_params;
