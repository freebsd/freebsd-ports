--- src/iparam.c.orig	2003-01-17 00:49:04 UTC
+++ src/iparam.c
@@ -67,7 +67,7 @@ ref_to_key(const ref * pref, gs_param_ke
 	int len;
 	byte *buf;
 
-	sprintf(istr, "%ld", pref->value.intval);
+	sprintf(istr, "%d", pref->value.intval);
 	len = strlen(istr);
 	/* GC will take care of freeing this: */
 	buf = gs_alloc_string(plist->memory, len, "ref_to_key");
@@ -394,7 +394,7 @@ stack_param_enumerate(iparam_list * plis
 {
     int code;
     stack_param_list *const splist = (stack_param_list *) plist;
-    long index = penum->intval;
+    int index = penum->intval;
     ref *stack_element;
 
     do {
@@ -563,12 +563,6 @@ ref_param_read_int_array(gs_param_list *
 	    code = gs_note_error(e_typecheck);
 	    break;
 	}
-#if arch_sizeof_int < arch_sizeof_long
-	if (elt.value.intval != (int)elt.value.intval) {
-	    code = gs_note_error(e_rangecheck);
-	    break;
-	}
-#endif
 	piv[i] = (int)elt.value.intval;
     }
     if (code < 0) {
