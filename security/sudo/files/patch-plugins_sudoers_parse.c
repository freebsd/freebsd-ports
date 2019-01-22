--- plugins/sudoers/parse.c.orig	2019-01-22 13:45:48 UTC
+++ plugins/sudoers/parse.c
@@ -60,7 +60,7 @@ sudoers_lookup_pseudo(struct sudo_nss_list *snl, struc
     debug_decl(sudoers_lookup_pseudo, SUDOERS_DEBUG_PARSER)
 
     pwcheck = (pwflag == -1) ? never : sudo_defs_table[pwflag].sd_un.tuple;
-    nopass = (pwcheck == all) ? true : false;
+    nopass = (pwcheck == never) ? true : false;
 
     if (list_pw == NULL)
 	SET(validated, FLAG_NO_CHECK);
