--- src/krb5/_principal.pyi.orig	2025-09-01 04:40:28 UTC
+++ src/krb5/_principal.pyi
@@ -13,7 +13,6 @@ class PrincipalParseFlags(enum.IntEnum):
     no_realm = ...  #: Error if realm is present
     require_realm = ...  #: Error if realm is not present
     enterprise = ...  #: Create single-component enterprise principal
-    ignore_realm = ...  #: Ignore realm if present
 
 class PrincipalUnparseFlags(enum.IntEnum):
     """Flags used to control :meth:`unparse_name_flags`."""
