--- psi/zicc.c.orig	2015-03-30 08:21:24 UTC
+++ psi/zicc.c
@@ -61,6 +61,9 @@ int seticc(i_ctx_t * i_ctx_p, int ncomps
 
     palt_cs = gs_currentcolorspace(igs);
 
+    if (2*ncomps > sizeof(range_buff)/sizeof(float))
+	return_error(e_rangecheck);
+
     /* verify the DataSource entry */
     if (dict_find_string(ICCdict, "DataSource", &pstrmval) <= 0)
         return_error(e_undefined);
