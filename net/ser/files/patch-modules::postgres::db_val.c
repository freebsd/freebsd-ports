
$FreeBSD$

--- modules/postgres/db_val.c
+++ modules/postgres/db_val.c
@@ -185,6 +185,7 @@
 		VAL_NULL(_v) = 1;
 		return 0;
 	}
+	VAL_NULL(_v) = 0;
 
 	switch(_t) {
 	case DB_INT:
