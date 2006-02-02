--- ea_store.c.orig	Mon Jul 11 19:25:38 2005
+++ ea_store.c	Thu Feb  2 09:40:00 2006
@@ -82,6 +82,11 @@ static void calc_property_info(zend_prop
 	EACCELERATOR_ALIGN(EAG(mem));
 	EAG(mem) += sizeof(zend_property_info);
 	calc_string(from->name, from->name_length + 1 TSRMLS_CC);
+#ifdef ZEND_ENGINE_2_1
+	if (from->doc_comment != NULL) {
+		calc_string(from->doc_comment, from->doc_comment_len + 1 TSRMLS_CC);
+	}
+#endif
 }
 
 /* Calculate the size of a point to a class entry */
@@ -246,6 +251,16 @@ void calc_op_array(zend_op_array * from 
 		EAG(mem) += sizeof(HashTable);
 		calc_zval_hash(from->static_variables);
 	}
+#ifdef ZEND_ENGINE_2_1
+	if (from->vars != NULL) {
+		zend_uint i;
+		EACCELERATOR_ALIGN(EAG(mem));
+		EAG(mem) += sizeof(zend_compiled_variable) * from->last_var;
+		for (i = 0; i < from->last_var; i ++) {
+			calc_string(from->vars[i].name, from->vars[i].name_len+1 TSRMLS_CC);
+		}
+	}
+#endif
 	if (from->filename != NULL)
 		calc_string(from->filename, strlen(from->filename) + 1 TSRMLS_CC);
 #ifdef ZEND_ENGINE_2
@@ -285,6 +300,11 @@ void calc_class_entry(zend_class_entry *
 
 	calc_zval_hash(&from->constants_table);
 	calc_zval_hash(&from->default_properties);
+
+#ifdef ZEND_ENGINE_2_1
+	calc_zval_hash(&from->default_static_members);
+#endif
+	
 	calc_hash(&from->properties_info, (calc_bucket_t) calc_property_info);
 	if (from->static_members != NULL) {
 		EACCELERATOR_ALIGN(EAG(mem));
@@ -610,6 +630,10 @@ eaccelerator_op_array *store_op_array(ze
 	to->uses_globals = from->uses_globals;
 #endif
 	to->static_variables = from->static_variables;
+#ifdef ZEND_ENGINE_2_1
+	to->vars             = from->vars;
+	to->last_var         = from->last_var;
+#endif
 	to->return_reference = from->return_reference;
 	to->filename = from->filename;
 
@@ -671,8 +695,24 @@ eaccelerator_op_array *store_op_array(ze
 		EAG(mem) += sizeof(HashTable);
 		store_zval_hash(to->static_variables, from->static_variables);
 	}
+#ifdef ZEND_ENGINE_2_1
+	if (from->vars != NULL) {
+        	zend_uint i;
+	        EACCELERATOR_ALIGN(EAG(mem));
+	        to->last_var = from->last_var;
+	        to->vars = (zend_compiled_variable*)EAG(mem);
+	        EAG(mem) += sizeof(zend_compiled_variable) * from->last_var;
+			memcpy(to->vars, from->vars, sizeof(zend_compiled_variable) * from->last_var);
+	        for (i = 0; i < from->last_var; i ++) {
+	        	to->vars[i].name = store_string(from->vars[i].name, from->vars[i].name_len+1 TSRMLS_CC);
+		}
+	} else {
+		to->last_var = 0;
+	        to->vars = NULL;
+	}
+#endif
 	if (from->filename != NULL) {
-		to->filename = store_string(to->filename, strlen(from->filename) + 1 TSRMLS_CC);
+		to->filename = store_string(from->filename, strlen(from->filename) + 1 TSRMLS_CC);
 	}
 #ifdef ZEND_ENGINE_2
 	to->line_start = from->line_start;
@@ -693,6 +733,12 @@ static zend_property_info *store_propert
 	EAG(mem) += sizeof(zend_property_info);
 	memcpy(to, from, sizeof(zend_property_info));
 	to->name = store_string(from->name, from->name_length + 1 TSRMLS_CC);
+#ifdef ZEND_ENGINE_2_1
+	to->doc_comment_len = from->doc_comment_len;
+	if (from->doc_comment != NULL) {
+		to->doc_comment = store_string(from->doc_comment, from->doc_comment_len + 1 TSRMLS_CC);
+	}
+#endif
 	return to;
 }
 #endif
@@ -770,6 +816,10 @@ eaccelerator_class_entry *store_class_en
 	}
 #else
 	store_zval_hash(&to->default_properties, &from->default_properties);
+#endif
+
+#ifdef ZEND_ENGINE_2_1
+	store_zval_hash(&to->default_static_members, &from->default_static_members);
 #endif
 	store_hash(&to->function_table, &from->function_table, (store_bucket_t) store_op_array);
 
