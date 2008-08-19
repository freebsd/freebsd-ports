--- src/cmdline.c.orig	2008-08-19 15:33:35.000000000 +0800
+++ src/cmdline.c	2008-08-19 15:35:06.000000000 +0800
@@ -194,7 +194,7 @@
   args_info->gen_references_orig = NULL;
   args_info->ctags_file_arg = gengetopt_strdup ("tags");
   args_info->ctags_file_orig = NULL;
-  args_info->ctags_arg = gengetopt_strdup ("ctags --excmd=n --tag-relative=yes");
+  args_info->ctags_arg = gengetopt_strdup ("exctags --excmd=n --tag-relative=yes");
   args_info->ctags_orig = NULL;
   args_info->gen_version_flag = 1;
   args_info->check_lang_arg = NULL;
