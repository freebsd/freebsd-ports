--- ea_restore.c.orig	Sun Mar 19 18:42:48 2006
+++ ea_restore.c	Sun Mar 19 18:45:26 2006
@@ -718,12 +718,13 @@
 void restore_class_parent(char *parent, int len,
 						  zend_class_entry * to TSRMLS_DC)
 {
-	DBG(ea_debug_printf, (EA_DEBUG, "restore_class_parent: restoring parent class %s of class %s\n", (char *) parent, to->name));
 #ifdef ZEND_ENGINE_2
 	zend_class_entry** parent_ptr = NULL;
+	DBG(ea_debug_printf, (EA_DEBUG, "restore_class_parent: restoring parent class %s of class %s\n", (char *) parent, to->name));
 	if (zend_lookup_class(parent, len, &parent_ptr TSRMLS_CC) != SUCCESS)
 #else
 	char *name_lc = estrndup(parent, len);
+	DBG(ea_debug_printf, (EA_DEBUG, "restore_class_parent: restoring parent class %s of class %s\n", (char *) parent, to->name));
 	zend_str_tolower(name_lc, len);
 	if (zend_hash_find(CG(class_table), (void *) name_lc, len + 1, (void **) &to->parent) != SUCCESS)
 #endif
