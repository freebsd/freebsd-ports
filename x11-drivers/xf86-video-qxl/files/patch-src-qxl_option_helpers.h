--- src/qxl_option_helpers.h.orig	2023-01-07 19:55:44 UTC
+++ src/qxl_option_helpers.h
@@ -6,13 +6,13 @@
 #include <xf86Crtc.h>
 #include <xf86Opt.h>
 
-int get_int_option(OptionInfoPtr options, int option_index,
+int get_int_option(OptionInfoPtr options, int token,
                    const char *env_name);
 
-const char *get_str_option(OptionInfoPtr options, int option_index,
+const char *get_str_option(OptionInfoPtr options, int token,
                            const char *env_name);
 
-int get_bool_option(OptionInfoPtr options, int option_index,
+int get_bool_option(OptionInfoPtr options, int token,
                      const char *env_name);
 
 #endif // OPTION_HELPERS_H
