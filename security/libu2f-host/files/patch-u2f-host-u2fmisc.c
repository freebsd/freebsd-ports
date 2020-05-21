--- u2f-host/u2fmisc.c.orig	2019-05-15 11:54:11 UTC
+++ u2f-host/u2fmisc.c
@@ -30,7 +30,7 @@
 #define u2fh_json_object_object_get(obj, key, value) json_object_object_get_ex(obj, key, &value)
 #else
 typedef int json_bool;
-#define u2fh_json_object_object_get(obj, key, value) (value = json_object_object_get(obj, key)) == NULL ? (json_bool)FALSE : (json_bool)TRUE
+#define u2fh_json_object_object_get(obj, key, value) (value = json_object_object_get(obj, key)) == NULL ? 0 : 1
 #endif
 
 static void
@@ -114,7 +114,7 @@ prepare_origin (const char *jsonstr, unsigned char *p)
   if (debug)
     fprintf (stderr, "JSON: %s\n", json_object_to_json_string (jo));
 
-  if (u2fh_json_object_object_get (jo, "appId", k) == FALSE)
+  if (u2fh_json_object_object_get (jo, "appId", k) == 0)
     return U2FH_JSON_ERROR;
 
   app_id = json_object_get_string (k);
@@ -390,7 +390,7 @@ get_fixed_json_data (const char *jsonstr, const char *
   if (debug)
     fprintf (stderr, "JSON: %s\n", json_object_to_json_string (jo));
 
-  if (u2fh_json_object_object_get (jo, key, k) == FALSE)
+  if (u2fh_json_object_object_get (jo, key, k) == 0)
     return U2FH_JSON_ERROR;
 
   urlb64 = json_object_get_string (k);
