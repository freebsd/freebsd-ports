diff -ruN modules/postgres/db_val.c /home/snar/ser-0.9.7/modules/postgres/db_val.c
--- modules/postgres/db_val.c	2005-07-20 21:11:52.000000000 +0400
+++ modules/postgres/db_val.c	2006-10-25 23:32:10.000000000 +0400
@@ -166,12 +166,14 @@
 	return 0;
 }
 
+
 /*
  * Does not copy strings
  */
 int str2valp(db_type_t _t, db_val_t* _v, const char* _s, int _l, void *_p)
 {
-	char dbuf[256];
+#define DBUF_SIZE 256
+	char dbuf[DBUF_SIZE];
 #ifdef PARANOID
 	if (!_v) {
 		LOG(L_ERR, "str2valp(): Invalid parameter value\n");
@@ -185,11 +187,12 @@
 		VAL_NULL(_v) = 1;
 		return 0;
 	}
-
+	VAL_NULL(_v) = 0;
+	
 	switch(_t) {
 	case DB_INT:
 	case DB_BITMAP:
-		sprintf(dbuf, "got int %s", _s);
+		snprintf(dbuf, DBUF_SIZE, "got int %s", _s);
 		DLOG("str2valp", dbuf);
 		if (str2int(_s, &VAL_INT(_v)) < 0) {
 			LOG(L_ERR, "str2valp(): Error while converting integer value from string\n");
@@ -201,7 +204,7 @@
 		break;
 	
 	case DB_DOUBLE:
-		sprintf(dbuf, "got double %s", _s);
+		snprintf(dbuf, DBUF_SIZE, "got double %s", _s);
 		DLOG("str2valp", dbuf);
 		if (str2double(_s, &VAL_DOUBLE(_v)) < 0) {
 			LOG(L_ERR, "str2valp(): Error while converting double value from string\n");
@@ -213,7 +216,7 @@
 		break;
 
 	case DB_STRING:
-		sprintf(dbuf, "got string %s", _s);
+		snprintf(dbuf, DBUF_SIZE, "got string %s", _s);
 		DLOG("str2valp", dbuf);
 
 		VAL_STRING(_v) = aug_strdup(_s, _p);
@@ -228,13 +231,13 @@
 		VAL_STR(_v).len = _l;
 		VAL_TYPE(_v) = DB_STR;
 
-		sprintf(dbuf, "got len string %d %s", _l, _s);
+		snprintf(dbuf, DBUF_SIZE, "got len string %d %s", _l, _s);
 		DLOG("str2valp", dbuf);
 
 		return 0;
 
 	case DB_DATETIME:
-		sprintf(dbuf, "got time %s", _s);
+		snprintf(dbuf, DBUF_SIZE, "got time %s", _s);
 		DLOG("str2valp", dbuf);
 		if (str2time(_s, &VAL_TIME(_v)) < 0) {
 			PLOG("str2valp", "error converting datetime");
@@ -253,7 +256,7 @@
 		VAL_STR(_v).len = _l;
 		VAL_TYPE(_v) = DB_BLOB;
 
-		sprintf(dbuf, "got blob %d", _l);
+		snprintf(dbuf, DBUF_SIZE, "got blob %d", _l);
 		DLOG("str2valp", dbuf);
 
 		return 0;
