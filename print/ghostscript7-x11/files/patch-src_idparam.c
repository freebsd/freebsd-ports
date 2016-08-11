--- src/idparam.c.orig	2003-01-17 00:49:04 UTC
+++ src/idparam.c
@@ -61,8 +61,7 @@ dict_int_null_param(const ref * pdict, c
 		    int maxval, int defaultval, int *pvalue)
 {
     ref *pdval;
-    int code;
-    long ival;
+    int code, ival;
 
     if (pdict == 0 || dict_find_string(pdict, kstr, &pdval) <= 0) {
 	ival = defaultval;
@@ -349,7 +348,7 @@ dict_uid_param(const ref * pdict, gs_uid
     } else {
 	if (!r_has_type(puniqueid, t_integer) ||
 	    puniqueid->value.intval < 0 ||
-	    puniqueid->value.intval > 0xffffffL
+	    puniqueid->value.intval > 0xffffff
 	    )
 	    return_error(e_rangecheck);
 	/* Apparently fonts created by Fontographer often have */
