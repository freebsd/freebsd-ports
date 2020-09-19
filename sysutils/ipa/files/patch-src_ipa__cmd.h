--- src/ipa_cmd.h.orig	2011-01-23 18:42:34 UTC
+++ src/ipa_cmd.h
@@ -165,7 +165,7 @@ extern char	*shell_path_default;
 extern char	*shell_arg1;
 extern char	*shell_arg1_default;
 
-const char *const rc_sect_name[2];
+extern const char *const rc_sect_name[2];
 
 extern ipa_mzone *cmd_mzone;
 
