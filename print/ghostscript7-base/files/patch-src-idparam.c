--- src/idparam.c.orig	2013-04-30 10:54:55.000000000 +0900
+++ src/idparam.c	2013-04-30 10:55:23.000000000 +0900
@@ -61,8 +61,7 @@
 		    int maxval, int defaultval, int *pvalue)
 {
     ref *pdval;
-    int code;
-    long ival;
+    int code, ival;
 
     if (pdict == 0 || dict_find_string(pdict, kstr, &pdval) <= 0) {
 	ival = defaultval;
@@ -349,7 +348,7 @@
     } else {
 	if (!r_has_type(puniqueid, t_integer) ||
 	    puniqueid->value.intval < 0 ||
-	    puniqueid->value.intval > 0xffffffL
+	    puniqueid->value.intval > 0xffffff
 	    )
 	    return_error(e_rangecheck);
 	/* Apparently fonts created by Fontographer often have */
