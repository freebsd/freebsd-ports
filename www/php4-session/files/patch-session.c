--- session.c	2007/01/09 15:31:36	1.336.2.53.2.13
+++ session.c	2007/02/15 09:41:30	1.336.2.53.2.14
@@ -271,8 +271,12 @@
 {
 	zval **sym_track = NULL;
 	
-	zend_hash_find(Z_ARRVAL_P(PS(http_session_vars)), name, namelen + 1, 
-			(void *) &sym_track);
+	IF_SESSION_VARS() {
+		zend_hash_find(Z_ARRVAL_P(PS(http_session_vars)), name, namelen + 1,
+				(void *) &sym_track);
+	} else {
+		return;
+	}
 
 	/*
 	 * Set up a proper reference between $_SESSION["x"] and $x.
@@ -281,11 +285,10 @@
 	if (PG(register_globals)) {
 		zval **sym_global = NULL;
 		
-		zend_hash_find(&EG(symbol_table), name, namelen + 1, 
-				(void *) &sym_global);
-				
-		if ((Z_TYPE_PP(sym_global) == IS_ARRAY && Z_ARRVAL_PP(sym_global) == &EG(symbol_table)) || *sym_global == PS(http_session_vars)) {
-			return;
+		if (zend_hash_find(&EG(symbol_table), name, namelen + 1, (void *) &sym_global) == SUCCESS) {
+			if ((Z_TYPE_PP(sym_global) == IS_ARRAY && Z_ARRVAL_PP(sym_global) == &EG(symbol_table)) || *sym_global == PS(http_session_vars)) {
+				return;
+			}
 		}
 
 		if (sym_global == NULL && sym_track == NULL) {
