--- servers/slapd/slap.h	Mon Oct  6 16:57:29 2003
+++ servers/slapd/slap.h	Sun Oct 19 15:33:56 2003
@@ -451,11 +451,18 @@
  */
 #define SLAP_MR_VALUE_OF_ASSERTION_SYNTAX	0x0001U
 #define SLAP_MR_VALUE_OF_ATTRIBUTE_SYNTAX	0x0002U
+#define SLAP_MR_VALUE_OF_SYNTAX				0x0003U
 
 #define SLAP_MR_IS_VALUE_OF_ATTRIBUTE_SYNTAX( usage ) \
 	((usage) & SLAP_MR_VALUE_OF_ATTRIBUTE_SYNTAX )
 #define SLAP_MR_IS_VALUE_OF_ASSERTION_SYNTAX( usage ) \
 	((usage) & SLAP_MR_VALUE_OF_ASSERTION_SYNTAX )
+#ifdef LDAP_DEBUG
+#define SLAP_MR_IS_VALUE_OF_SYNTAX( usage ) \
+	((usage) & SLAP_MR_VALUE_OF_SYNTAX)
+#else
+#define SLAP_MR_IS_VALUE_OF_SYNTAX( usage )	(1)
+#endif
 
 /* either or both the asserted value or attribute value
  * may be provided in normalized form
@@ -1311,8 +1318,8 @@
         char			*srvtab;
 		int				schemachecking;
         Filter			*filter;
-        char			*filterstr;
-        char			*base;
+        struct berval		filterstr;
+        struct berval		base;
         int				scope;
         int				attrsonly;
         char			**attrs;
@@ -1980,7 +1987,6 @@
 
 	ValuesReturnFilter *o_vrFilter; /* ValuesReturnFilter */
 
-	syncinfo_t*	o_si;
 	int o_nocaching;
 
 #ifdef LDAP_SLAPI
