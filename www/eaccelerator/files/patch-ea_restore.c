--- ea_restore.c.orig	Wed Aug  3 20:54:32 2005
+++ ea_restore.c	Thu Feb  2 09:40:00 2006
@@ -39,6 +39,9 @@
 #include "zend.h"
 #include "zend_API.h"
 #include "zend_extensions.h"
+#ifdef ZEND_ENGINE_2_1
+#include "zend_vm.h"
+#endif
 
 #ifndef INCOMPLETE_CLASS
 #  define INCOMPLETE_CLASS "__PHP_Incomplete_Class"
@@ -69,12 +72,16 @@ dtor_func_t get_zend_destroy_property_in
 	property_dtor = dummy_class_entry.properties_info.pDestructor;
 
 	zend_hash_destroy(&dummy_class_entry.default_properties);
-	zend_hash_destroy(&dummy_class_entry.properties_info);
-	zend_hash_destroy(dummy_class_entry.static_members);
 	zend_hash_destroy(&dummy_class_entry.function_table);
-	FREE_HASHTABLE(dummy_class_entry.static_members);
 	zend_hash_destroy(&dummy_class_entry.constants_table);
-
+	zend_hash_destroy(&dummy_class_entry.properties_info);
+#  ifdef ZEND_ENGINE_2_1
+	zend_hash_destroy(&dummy_class_entry.default_static_members);
+#  endif
+#  if defined(ZEND_ENGINE_2) && !defined(ZEND_ENGINE_2_1)
+	zend_hash_destroy(dummy_class_entry.static_members);
+        FREE_HASHTABLE(dummy_class_entry.static_members);
+#  endif
 	return property_dtor;
 }
 #endif
@@ -92,6 +99,9 @@ typedef void (*fixup_bucket_t) (void *TS
 static void fixup_property_info(zend_property_info * from TSRMLS_DC)
 {
 	FIXUP(from->name);
+#ifdef ZEND_ENGINE_2_1
+	FIXUP(from->doc_comment);
+#endif
 }
 #endif
 
@@ -221,7 +231,12 @@ void fixup_op_array(eaccelerator_op_arra
 				FIXUP(opline->op2.u.jmp_addr);
 				break;
 			}
+#  ifdef ZEND_ENGINE_2_1
+			ZEND_VM_SET_OPCODE_HANDLER(opline);
+#  else
 			opline->handler = get_opcode_handler(opline->opcode TSRMLS_CC);
+#  endif
+
 #endif
 		}
 		EAG(compress) = 1;
@@ -234,6 +249,15 @@ void fixup_op_array(eaccelerator_op_arra
 		FIXUP(from->static_variables);
 		fixup_zval_hash(from->static_variables);
 	}
+#ifdef ZEND_ENGINE_2_1
+	if (from->vars != NULL) {
+		zend_uint i;
+		FIXUP(from->vars);
+		for (i = 0; i < from->last_var; i++) {
+			FIXUP(from->vars[i].name);
+		}
+	}
+#endif
 	FIXUP(from->filename);
 #ifdef ZEND_ENGINE_2
 	FIXUP(from->doc_comment);
@@ -255,6 +279,9 @@ void fixup_class_entry(eaccelerator_clas
 		FIXUP(from->static_members);
 		fixup_zval_hash(from->static_members);
 	}
+#  ifdef ZEND_ENGINE_2_1
+	fixup_zval_hash(&from->default_static_members);
+#  endif
 #else
 	fixup_zval_hash(&from->default_properties);
 #endif
@@ -570,12 +597,12 @@ zend_op_array *restore_op_array(zend_op_
 	to->T = from->T;
 	to->brk_cont_array = from->brk_cont_array;
 	to->last_brk_cont = from->last_brk_cont;
-	/*
+	
 	   to->current_brk_cont = -1;
 	   to->static_variables = from->static_variables;
-	   to->start_op         = to->opcodes;
+/*	   to->start_op         = to->opcodes; */
 	   to->backpatch_count  = 0;
-	 */
+	
 	to->return_reference = from->return_reference;
 	to->done_pass_two = 1;
 	to->filename = from->filename;
@@ -612,6 +639,20 @@ zend_op_array *restore_op_array(zend_op_
 #endif
 	}
 
+#ifdef ZEND_ENGINE_2_1
+	to->vars             = from->vars;
+	to->last_var         = from->last_var;
+	to->size_var         = 0;
+	if (to->vars) {		
+		zend_uint i;
+		to->vars = (zend_compiled_variable*)emalloc(from->last_var*sizeof(zend_compiled_variable));		
+		memcpy(to->vars, from->vars, sizeof(zend_compiled_variable) * from->last_var);
+		for (i = 0; i < from->last_var; i ++) {
+			to->vars[i].name = estrndup(from->vars[i].name, from->vars[i].name_len);
+		}
+	}
+#endif
+
 	/* disable deletion in destroy_op_array */
 	++EAG(refcount_helper);
 	to->refcount = &EAG(refcount_helper);
@@ -633,6 +674,12 @@ static zend_property_info *restore_prope
 	memcpy(to, from, sizeof(zend_property_info));
 	to->name = emalloc(from->name_length + 1);
 	memcpy(to->name, from->name, from->name_length + 1);
+#ifdef ZEND_ENGINE_2_1
+	if (from->doc_comment != NULL) {
+		to->doc_comment = emalloc(from->doc_comment_len+1);
+		memcpy(to->doc_comment, from->doc_comment, from->doc_comment_len+1);
+	}
+#endif
 	return to;
 }
 #endif
@@ -660,6 +707,12 @@ void restore_class_parent(char *parent, 
 		to->clone = to->parent->clone;
 		to->__get = to->parent->__get;
 		to->__set = to->parent->__set;
+#  ifdef ZEND_ENGINE_2_1
+		to->__unset = to->parent->__unset;
+		to->__isset = to->parent->__isset;
+		to->serialize_func = to->parent->serialize_func;
+		to->unserialize_func = to->parent->unserialize_func;
+#  endif
 		to->__call = to->parent->__call;
 		to->create_object = to->parent->create_object;
 #else
@@ -708,6 +761,14 @@ void restore_class_methods(zend_class_en
 			else if (fname_len == sizeof(ZEND_SET_FUNC_NAME) - 1 &&
 					 memcmp(fname_lc, ZEND_SET_FUNC_NAME, sizeof(ZEND_SET_FUNC_NAME)) == 0)
 				to->__set = f;
+#  ifdef ZEND_ENGINE_2_1
+			else if (fname_len == sizeof(ZEND_UNSET_FUNC_NAME) - 1 &&
+					memcmp(fname_lc, ZEND_UNSET_FUNC_NAME, sizeof(ZEND_UNSET_FUNC_NAME)) == 0)
+				to->__unset = f;
+			else if (fname_len == sizeof(ZEND_ISSET_FUNC_NAME) - 1 &&
+					memcmp(fname_lc, ZEND_ISSET_FUNC_NAME, sizeof(ZEND_ISSET_FUNC_NAME)) == 0)
+				to->__isset = f;
+#  endif
 			else if (fname_len == sizeof(ZEND_CALL_FUNC_NAME) - 1 &&
 					 memcmp(fname_lc, ZEND_CALL_FUNC_NAME, sizeof(ZEND_CALL_FUNC_NAME)) == 0)
 				to->__call = f;
@@ -734,11 +795,10 @@ zend_class_entry *restore_class_entry(ze
 #endif
 
 	ea_debug_pad(EA_DEBUG TSRMLS_CC);
-	ea_debug_printf(EA_DEBUG, "[%d] retore_class_entry: %s\n", getpid(), from->name ? from->name : "(top)");
+	ea_debug_printf(EA_DEBUG, "[%d] restore_class_entry: %s\n", getpid(), from->name ? from->name : "(top)");
 #ifdef DEBUG
 	EAG(xpad)++;
 #endif
-
 	if (to == NULL) {
 		to = emalloc(sizeof(zend_class_entry));
 	}
@@ -752,9 +812,6 @@ zend_class_entry *restore_class_entry(ze
 	 */
 #ifdef ZEND_ENGINE_2
 	to->ce_flags = from->ce_flags;
-	/*
-	   to->static_members = NULL;
-	 */
 	to->num_interfaces = from->num_interfaces;
 	if (to->num_interfaces > 0) {
 		to->interfaces = (zend_class_entry **) emalloc(sizeof(zend_class_entry *) * to->num_interfaces);
@@ -765,6 +822,7 @@ zend_class_entry *restore_class_entry(ze
 	}
 
 	to->iterator_funcs = from->iterator_funcs;
+	to->create_object = from->create_object;
 	to->get_iterator = from->get_iterator;
 	to->interface_gets_implemented = from->interface_gets_implemented;
 #endif
@@ -813,16 +871,19 @@ zend_class_entry *restore_class_entry(ze
             (restore_bucket_t) restore_property_info TSRMLS_CC);
 	to->properties_info.pDestructor = properties_info_dtor;
 
+#  ifdef ZEND_ENGINE_2_1
+	/* restore default_static_members */
+	restore_zval_hash(&to->default_static_members, &from->default_static_members);
+	to->default_static_members.pDestructor = ZVAL_PTR_DTOR;
+	
+	to->static_members = (from->type == ZEND_INTERNAL_CLASS) ? NULL : &to->default_static_members;
+#  else
 	if (from->static_members != NULL) {
 		ALLOC_HASHTABLE(to->static_members);
 		restore_zval_hash(to->static_members, from->static_members);
 		to->static_members->pDestructor = ZVAL_PTR_DTOR;
-		/*
-		   } else {
-		   ALLOC_HASHTABLE(to->static_members);
-		   zend_hash_init_ex(to->static_members, 0, NULL, ZVAL_PTR_DTOR, 0, 0);
-		 */
 	}
+#  endif
 #else
 	to->refcount = emalloc(sizeof(*to->refcount));
 	*to->refcount = 1;
