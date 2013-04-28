--- psi/zicc.c
+++ psi/zicc.c	2008-02-05 16:11:59.000000000 +0000
@@ -77,6 +77,9 @@ zseticcspace(i_ctx_t * i_ctx_p)
     dict_find_string(op, "N", &pnval);
     ncomps = pnval->value.intval;
 
+    if (2*ncomps > sizeof(range_buff)/sizeof(float))
+	return_error(e_rangecheck);
+
     /* verify the DataSource entry */
     if (dict_find_string(op, "DataSource", &pstrmval) <= 0)
         return_error(e_undefined);
