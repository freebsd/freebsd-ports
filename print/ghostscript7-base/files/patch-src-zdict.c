--- src/zdict.c.orig	2013-04-30 11:04:05.000000000 +0900
+++ src/zdict.c	2013-04-30 11:04:34.000000000 +0900
@@ -35,12 +35,9 @@
     os_ptr op = osp;
 
     check_type(*op, t_integer);
-#if arch_sizeof_int < arch_sizeof_long
-    check_int_leu(*op, max_uint);
-#else
     if (op->value.intval < 0)
 	return_error(e_rangecheck);
-#endif
+
     return dict_create((uint) op->value.intval, op);
 }
 
@@ -458,12 +455,8 @@
     check_type(*op1, t_dictionary);
     check_dict_write(*op1);
     check_type(*op, t_integer);
-#if arch_sizeof_int < arch_sizeof_long
-    check_int_leu(*op, max_uint);
-#else
     if (op->value.intval < 0)
 	return_error(e_rangecheck);
-#endif
     new_size = (uint) op->value.intval;
     if (dict_length(op - 1) > new_size)
 	return_error(e_dictfull);
