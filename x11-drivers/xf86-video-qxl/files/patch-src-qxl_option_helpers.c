--- src/qxl_option_helpers.c.orig	2015-10-12 16:31:14 UTC
+++ src/qxl_option_helpers.c
@@ -10,31 +10,32 @@
 
 #include "qxl_option_helpers.h"
 
-int get_int_option(OptionInfoPtr options, int option_index,
+int get_int_option(OptionInfoPtr options, int token,
                    const char *env_name)
 {
+    int value;
     if (env_name && getenv(env_name)) {
         return atoi(getenv(env_name));
     }
-    return options[option_index].value.num;
+    return xf86GetOptValInteger(options, token, &value) ? value : 0;
 }
 
-const char *get_str_option(OptionInfoPtr options, int option_index,
+const char *get_str_option(OptionInfoPtr options, int token,
                            const char *env_name)
 {
     if (getenv(env_name)) {
         return getenv(env_name);
     }
-    return options[option_index].value.str;
+    return xf86GetOptValString(options, token);
 }
 
-int get_bool_option(OptionInfoPtr options, int option_index,
+int get_bool_option(OptionInfoPtr options, int token,
                      const char *env_name)
 {
     const char* value = getenv(env_name);
 
     if (!value) {
-        return options[option_index].value.bool;
+        return xf86ReturnOptValBool(options, token, FALSE);
     }
     if (strcmp(value, "0") == 0 ||
         strcasecmp(value, "off") == 0 ||
