--- src/zdict.c.orig	2003-01-17 00:49:05 UTC
+++ src/zdict.c
@@ -35,12 +35,9 @@ zdict(i_ctx_t *i_ctx_p)
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
 
@@ -458,12 +455,8 @@ zsetmaxlength(i_ctx_t *i_ctx_p)
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
