--- src/iparam.c.orig	2013-04-30 11:12:36.000000000 +0900
+++ src/iparam.c	2013-04-30 11:13:07.000000000 +0900
@@ -67,7 +67,7 @@
 	int len;
 	byte *buf;
 
-	sprintf(istr, "%ld", pref->value.intval);
+	sprintf(istr, "%d", pref->value.intval);
 	len = strlen(istr);
 	/* GC will take care of freeing this: */
 	buf = gs_alloc_string(plist->memory, len, "ref_to_key");
@@ -394,7 +394,7 @@
 {
     int code;
     stack_param_list *const splist = (stack_param_list *) plist;
-    long index = penum->intval;
+    int index = penum->intval;
     ref *stack_element;
 
     do {
@@ -563,12 +563,6 @@
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
