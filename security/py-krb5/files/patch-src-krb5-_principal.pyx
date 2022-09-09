--- src/krb5/_principal.pyx.orig	2022-08-08 21:14:44 UTC
+++ src/krb5/_principal.pyx
@@ -59,7 +59,6 @@ cdef extern from "python_krb5.h":
     int32_t KRB5_PRINCIPAL_PARSE_NO_REALM
     int32_t KRB5_PRINCIPAL_PARSE_REQUIRE_REALM
     int32_t KRB5_PRINCIPAL_PARSE_ENTERPRISE
-    int32_t KRB5_PRINCIPAL_PARSE_IGNORE_REALM
 
     int32_t KRB5_PRINCIPAL_UNPARSE_SHORT
     int32_t KRB5_PRINCIPAL_UNPARSE_NO_REALM
@@ -71,7 +70,6 @@ class PrincipalParseFlags(enum.IntEnum):
     no_realm = KRB5_PRINCIPAL_PARSE_NO_REALM
     require_realm = KRB5_PRINCIPAL_PARSE_REQUIRE_REALM
     enterprise = KRB5_PRINCIPAL_PARSE_ENTERPRISE
-    ignore_realm = KRB5_PRINCIPAL_PARSE_IGNORE_REALM
 
 
 class PrincipalUnparseFlags(enum.IntEnum):
