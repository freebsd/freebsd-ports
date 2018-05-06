--- grammar.y.orig	1998-09-30 01:29:13 UTC
+++ grammar.y
@@ -14,7 +14,7 @@
 %token T_INLINE
 
 /* type specifiers */
-%token T_CHAR T_DOUBLE T_FLOAT T_INT T_VOID
+%token T_CHAR T_DOUBLE T_FLOAT T_INT T_VOID T_VALIST
 %token T_LONG T_SHORT T_SIGNED T_UNSIGNED
 %token T_ENUM T_STRUCT T_UNION
 
@@ -374,6 +374,10 @@ type_specifier
 	{
 	    new_decl_spec(&$$, "void", DS_NONE);
 	}
+	| T_VALIST
+	{
+	    new_decl_spec(&$$, "va_list", DS_NONE);
+	}
 	| struct_or_union_specifier
 	| enum_specifier
 	| T_TYPEDEF_NAME
