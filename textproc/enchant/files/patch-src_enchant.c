--- src/enchant.c-	Thu Mar 16 14:48:20 2006
+++ src/enchant.c	Thu Mar 16 14:50:03 2006
@@ -125,6 +125,7 @@
 enchant_get_module_dir (void)
 {
 	char * module_dir = NULL;
+	char * prefix = NULL;
 
 #ifdef XP_TARGET_COCOA
 	return g_strdup ([[EnchantResourceProvider instance] moduleFolder]);
@@ -136,7 +137,6 @@
 		return module_dir;
 
 	/* Dynamically locate library and search for modules relative to it. */
-	char * prefix = NULL;
 	prefix = enchant_get_prefix_dir();
 	if(prefix)
 		{
