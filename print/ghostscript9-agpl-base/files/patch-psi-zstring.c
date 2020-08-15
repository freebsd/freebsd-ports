--- psi/zstring.c.orig	2020-03-19 08:21:42 UTC
+++ psi/zstring.c
@@ -142,13 +142,18 @@ search_impl(i_ctx_t *i_ctx_p, bool forward)
     return 0;
 found:
     op->tas.type_attrs = op1->tas.type_attrs;
-    op->value.bytes = ptr;
-    r_set_size(op, size);
+    op->value.bytes = ptr;                             /* match */
+    op->tas.rsize = size;                              /* match */
     push(2);
-    op[-1] = *op1;
-    r_set_size(op - 1, ptr - op[-1].value.bytes);
-    op1->value.bytes = ptr + size;
-    r_set_size(op1, count + (!forward ? (size - 1) : 0));
+    op[-1] = *op1;                                     /* pre */
+    op[-3].value.bytes = ptr + size;                   /* post */
+    if (forward) {
+        op[-1].tas.rsize = ptr - op[-1].value.bytes;   /* pre */
+        op[-3].tas.rsize = count;                      /* post */
+    } else {
+        op[-1].tas.rsize = count;                      /* pre */
+        op[-3].tas.rsize -= count + size;              /* post */
+    }
     make_true(op);
     return 0;
 }
