--- src/cmdline.c.orig	2011-12-24 10:22:43 UTC
+++ src/cmdline.c
@@ -288,7 +288,7 @@ void clear_args (struct gengetopt_args_i
   args_info->gen_references_orig = NULL;
   args_info->ctags_file_arg = gengetopt_strdup ("tags");
   args_info->ctags_file_orig = NULL;
-  args_info->ctags_arg = gengetopt_strdup ("ctags --excmd=n --tag-relative=yes");
+  args_info->ctags_arg = gengetopt_strdup ("exctags --excmd=n --tag-relative=yes");
   args_info->ctags_orig = NULL;
   args_info->gen_version_flag = 1;
   args_info->check_lang_arg = NULL;
