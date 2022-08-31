--- build_helpers/heimdal/include/krb5.h.orig	2022-08-08 21:14:44 UTC
+++ build_helpers/heimdal/include/krb5.h
@@ -847,7 +847,6 @@ enum {
     KRB5_PRINCIPAL_PARSE_NO_REALM = 1, /**< Require that there are no realm */
     KRB5_PRINCIPAL_PARSE_REQUIRE_REALM = 2, /**< Require a realm present */
     KRB5_PRINCIPAL_PARSE_ENTERPRISE = 4, /**< Parse as a NT-ENTERPRISE name */
-    KRB5_PRINCIPAL_PARSE_IGNORE_REALM = 8, /**< Ignore realm if present */
     KRB5_PRINCIPAL_PARSE_NO_DEF_REALM = 16 /**< Don't default the realm */
 };
 
