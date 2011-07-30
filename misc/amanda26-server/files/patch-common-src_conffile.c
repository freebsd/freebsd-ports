--- common-src/conffile.c.orig	2011-06-25 22:48:30.000000000 +0200
+++ common-src/conffile.c	2011-06-25 22:58:42.000000000 +0200
@@ -4151,7 +4151,7 @@
     amfree(config_name);
     amfree(config_dir);
 
-    g_slist_free_full(seen_filenames);
+    _slist_free_full(seen_filenames, g_free);
     seen_filenames = NULL;
 
     config_client = FALSE;
@@ -5655,7 +5655,7 @@
             break;
 
 	case CONFTYPE_PP_SCRIPTLIST:
-	    g_slist_free_full(val->v.pp_scriptlist);
+	    _slist_free_full(val->v.pp_scriptlist, g_free);
 	    break;
 
 	case CONFTYPE_APPLICATION:
@@ -6771,7 +6771,7 @@
 void
 config_clear_errors(void)
 {
-    g_slist_free_full(cfgerr_errors);
+    _slist_free_full(cfgerr_errors, g_free);
 
     cfgerr_errors = NULL;
     cfgerr_level = CFGERR_OK;
