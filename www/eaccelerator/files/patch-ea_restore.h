--- ea_restore.h.orig	Mon Jul 11 19:25:38 2005
+++ ea_restore.h	Thu Feb  2 09:40:00 2006
@@ -34,6 +34,7 @@
 void fixup_op_array (eaccelerator_op_array * from TSRMLS_DC);
 void fixup_class_entry (eaccelerator_class_entry * from TSRMLS_DC);
 
+void restore_zval(zval * zv TSRMLS_DC);
 void restore_class(mm_fc_entry *p TSRMLS_DC);
 void restore_function(mm_fc_entry *p TSRMLS_DC);
 zend_op_array* restore_op_array(zend_op_array *to, eaccelerator_op_array *from TSRMLS_DC);
