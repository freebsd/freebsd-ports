--- src/krb5/_principal.pyi.orig	2022-08-08 21:14:44 UTC
+++ src/krb5/_principal.pyi
@@ -13,7 +13,6 @@ class PrincipalParseFlags(enum.IntEnum):
     no_realm: PrincipalParseFlags = ...  #: Error if realm is present
     require_realm: PrincipalParseFlags = ...  #: Error if realm is not present
     enterprise: PrincipalParseFlags = ...  #: Create single-component enterprise principal
-    ignore_realm: PrincipalParseFlags = ...  #: Ignore realm if present
 
 class PrincipalUnparseFlags(enum.IntEnum):
     """Flags used to control :meth:`unparse_name_flags`."""
