
$FreeBSD$

--- modules/postgres/db_val.c.orig	Mon Apr 14 21:52:47 2003
+++ modules/postgres/db_val.c	Tue Apr 13 22:27:28 2004
@@ -188,6 +188,7 @@
 
 	switch(_t) {
 	case DB_INT:
+	case DB_BITMAP:
 		sprintf(dbuf, "got int %s", _s);
 		DLOG("str2valp", dbuf);
 		if (str2int(_s, &VAL_INT(_v)) < 0) {
