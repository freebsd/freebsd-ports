--- src/xmlrpc.h.orig	Thu Jun 28 01:35:01 2001
+++ src/xmlrpc.h	Tue Mar  2 23:39:39 2004
@@ -152,7 +152,7 @@
 
 /* The same as the above, but using a printf-style format string. */
 void xmlrpc_env_set_fault_formatted (xmlrpc_env* env, int code,
-				     char *format, ...);
+				     const char *format, ...);
 
 /* A simple debugging assertion. */
 #define XMLRPC_ASSERT_ENV_OK(env) \
@@ -362,17 +362,23 @@
 ** Increments the reference counts of input arguments if necessary.
 ** See the xmlrpc-c documentation for more information. */
 extern xmlrpc_value *
-xmlrpc_build_value (xmlrpc_env* env, char* format, ...);
+xmlrpc_build_value (xmlrpc_env* env, const char* format, ...);
 
 /* The same as the above, but using a va_list. */
 extern xmlrpc_value *
-xmlrpc_build_value_va (xmlrpc_env* env, char* format, va_list args);
+xmlrpc_build_value_va (xmlrpc_env* env, const char* format, va_list args);
 
 /* Extract values from an xmlrpc_value and store them into C variables.
 ** Does not increment the reference counts of output values.
 ** See the xmlrpc-c documentation for more information. */
 extern void
-xmlrpc_parse_value (xmlrpc_env* env, xmlrpc_value* value, char* format, ...);
+xmlrpc_parse_value (xmlrpc_env* env, xmlrpc_value* value,
+                    const char* format, ...);
+
+/* The same as the above, but using a va_list. */
+extern void
+xmlrpc_parse_value_va (xmlrpc_env* env, xmlrpc_value* value,
+                       const char* format, va_list args);
 
 /* Return the number of elements in an XML-RPC array.
 ** Sets XMLRPC_TYPE_ERROR if 'array' is not an array. */
