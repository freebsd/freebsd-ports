
$FreeBSD$

--- modules/usrloc/udomain.c
+++ modules/usrloc/udomain.c
@@ -288,7 +288,7 @@
 		}
 		flags       = VAL_BITMAP(ROW_VALUES(row) + 8);
 		ua.s        = (char*)VAL_STRING(ROW_VALUES(row) + 9);
-		ua.len      = strlen(ua.s);
+		ua.len      = (ua.s != NULL) ? strlen(ua.s) : 0;
 
 		if (use_domain) {
 			domain    = (char*)VAL_STRING(ROW_VALUES(row) + 10);
