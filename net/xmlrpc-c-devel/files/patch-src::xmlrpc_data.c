--- src/xmlrpc_data.c.orig	Wed Apr 25 04:20:20 2001
+++ src/xmlrpc_data.c	Tue Mar  2 23:39:39 2004
@@ -182,10 +182,11 @@
 **  (in theory) also be portable.
 */
 
-static xmlrpc_value* mkvalue(xmlrpc_env* env, char** format, va_list* args);
+static xmlrpc_value* mkvalue(xmlrpc_env* env,
+			     const char** format, va_list* args);
 
 static xmlrpc_value* mkarray(xmlrpc_env* env,
-			     char** format,
+			     const char** format,
 			     char delimiter,
 			     va_list* args)
 {
@@ -236,7 +237,7 @@
 }
 
 static xmlrpc_value* mkstruct(xmlrpc_env* env,
-			      char** format,
+			      const char** format,
 			      char delimiter,
 			      va_list* args)
 {
@@ -357,7 +358,8 @@
 }
 #endif /* HAVE_UNICODE_WCHAR */
 
-static xmlrpc_value* mkvalue(xmlrpc_env* env, char** format, va_list* args)
+static xmlrpc_value* mkvalue(xmlrpc_env* env,
+			     const char** format, va_list* args)
 {
     xmlrpc_value* val;
     char *str, *contents;
@@ -497,10 +499,10 @@
 }
 
 xmlrpc_value* xmlrpc_build_value_va (xmlrpc_env* env,
-				     char* format,
+				     const char* format,
 				     va_list args)
 {
-    char *format_copy;
+    const char *format_copy;
     va_list args_copy;
     xmlrpc_value* retval;
 
@@ -520,7 +522,7 @@
 }
 
 xmlrpc_value* xmlrpc_build_value (xmlrpc_env* env,
-				  char* format, ...)
+				  const char* format, ...)
 {
     va_list args;
     xmlrpc_value* retval;
@@ -542,12 +544,12 @@
 
 static void parsevalue (xmlrpc_env* env,
 			xmlrpc_value* val,
-			char** format,
+			const char** format,
 			va_list* args);
 
 static void parsearray (xmlrpc_env* env,
 			xmlrpc_value* array,
-			char** format,
+			const char** format,
 			char delimiter,
 			va_list* args)
 {
@@ -584,7 +586,7 @@
 
 static void parsestruct(xmlrpc_env* env,
 			xmlrpc_value* strct,
-			char** format,
+			const char** format,
 			char delimiter,
 			va_list* args)
 {
@@ -633,7 +635,7 @@
 
 static void parsevalue (xmlrpc_env* env,
 			xmlrpc_value* val,
-			char** format,
+			const char** format,
 			va_list* args)
 {
     xmlrpc_int32 *int32ptr;
@@ -783,12 +785,12 @@
 	return;
 }
 
-static void xmlrpc_parse_value_va (xmlrpc_env* env,
-				   xmlrpc_value* value,
-				   char* format,
-				   va_list args)
+void xmlrpc_parse_value_va (xmlrpc_env* env,
+			    xmlrpc_value* value,
+			    const char* format,
+			    va_list args)
 {
-    char *format_copy;
+    const char *format_copy;
     va_list args_copy;
 
     XMLRPC_ASSERT_ENV_OK(env);
@@ -808,7 +810,7 @@
 
 void xmlrpc_parse_value (xmlrpc_env* env,
 			 xmlrpc_value* value,
-			 char* format, ...)
+			 const char* format, ...)
 {
     va_list args;
 
