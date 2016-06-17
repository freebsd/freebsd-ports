--- psi/zicc.c.orig	2009-01-21 15:34:55 UTC
+++ psi/zicc.c
@@ -161,6 +161,9 @@ zseticcspace(i_ctx_t * i_ctx_p)
     if (2*ncomps > sizeof(range_buff)/sizeof(range_buff[0]))
         return_error(e_rangecheck);
 
+    if (2*ncomps > sizeof(range_buff)/sizeof(float))
+	return_error(e_rangecheck);
+
     /* verify the DataSource entry */
     if (dict_find_string(op, "DataSource", &pstrmval) <= 0)
         return_error(e_undefined);
