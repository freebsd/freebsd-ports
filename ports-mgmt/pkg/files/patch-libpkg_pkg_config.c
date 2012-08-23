--- libpkg/pkg_config.c
+++ libpkg/pkg_config.c
@@ -268,7 +268,7 @@ subst_packagesite(void)
 
 	oldval = c[PKG_CONFIG_REPO].val;
 
-	if ((variable_string = strstr(oldval, ABI_VAR_STRING)) == NULL)
+	if (oldval == NULL || (variable_string = strstr(oldval, ABI_VAR_STRING)) == NULL)
 		return;
 
 	newval = sbuf_new_auto();
