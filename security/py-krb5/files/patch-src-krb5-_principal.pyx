--- src/krb5/_principal.pyx.orig	2022-02-16 07:12:32 UTC
+++ src/krb5/_principal.pyx
@@ -59,7 +59,11 @@ cdef extern from "python_krb5.h":
     int32_t KRB5_PRINCIPAL_PARSE_NO_REALM
     int32_t KRB5_PRINCIPAL_PARSE_REQUIRE_REALM
     int32_t KRB5_PRINCIPAL_PARSE_ENTERPRISE
+#if defined(KRB5_PRINCIPAL_PARSE_IGNORE_REALM)
     int32_t KRB5_PRINCIPAL_PARSE_IGNORE_REALM
+#elif defined(KRB5_PRINCIPAL_PARSE_NO_REALM)
+    int32_t KRB5_PRINCIPAL_PARSE_NO_REALM
+#endif
 
     int32_t KRB5_PRINCIPAL_UNPARSE_SHORT
     int32_t KRB5_PRINCIPAL_UNPARSE_NO_REALM
@@ -71,7 +75,11 @@ class PrincipalParseFlags(enum.IntEnum):
     no_realm = KRB5_PRINCIPAL_PARSE_NO_REALM
     require_realm = KRB5_PRINCIPAL_PARSE_REQUIRE_REALM
     enterprise = KRB5_PRINCIPAL_PARSE_ENTERPRISE
+#if defined(KRB5_PRINCIPAL_PARSE_IGNORE_REALM)
     ignore_realm = KRB5_PRINCIPAL_PARSE_IGNORE_REALM
+#elif defined(KRB5_PRINCIPAL_PARSE_NO_REALM)
+    ignore_realm = KRB5_PRINCIPAL_PARSE_NO_REALM
+#endif
 
 
 class PrincipalUnparseFlags(enum.IntEnum):
