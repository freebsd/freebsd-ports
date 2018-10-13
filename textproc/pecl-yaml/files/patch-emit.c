https://github.com/php/pecl-file_formats-yaml/commit/a217a24a674adafd03a03382e0950cbb743ba9a8
From a217a24a674adafd03a03382e0950cbb743ba9a8 Mon Sep 17 00:00:00 2001
From: Remi Collet <remi@remirepo.net>
Date: Wed, 4 Jul 2018 12:14:48 +0200
Subject: [PATCH] Fix for PHP 7.3

--- emit.c.orig	2017-07-29 21:56:18 UTC
+++ emit.c
@@ -173,7 +173,11 @@ static void y_scan_recursion(const y_emit_state_t *sta
 		return;
 	}
 
+#if PHP_VERSION_ID >= 70300
+	if (!(GC_FLAGS(ht) & GC_IMMUTABLE) && GC_IS_RECURSIVE(ht)) {
+#else
 	if (ZEND_HASH_APPLY_PROTECTION(ht) && ht->u.v.nApplyCount > 0) {
+#endif
 		zval tmp;
 		ZVAL_LONG(&tmp, (zend_ulong) ht);
 
@@ -182,17 +186,29 @@ static void y_scan_recursion(const y_emit_state_t *sta
 		return;
 	}
 
+#if PHP_VERSION_ID >= 70300
+	if (!(GC_FLAGS(ht) & GC_IMMUTABLE)) {
+		GC_PROTECT_RECURSION(ht);
+	}
+#else
 	if (ZEND_HASH_APPLY_PROTECTION(ht)) {
 		ht->u.v.nApplyCount++;
 	}
+#endif
 
 	ZEND_HASH_FOREACH_VAL(ht, elm) {
 		y_scan_recursion(state, elm TSRMLS_CC);
 	} ZEND_HASH_FOREACH_END();
 
+#if PHP_VERSION_ID >= 70300
+	if (!(GC_FLAGS(ht) & GC_IMMUTABLE)) {
+		GC_UNPROTECT_RECURSION(ht);
+	}
+#else
 	if (ZEND_HASH_APPLY_PROTECTION(ht)) {
 		ht->u.v.nApplyCount--;
 	}
+#endif
 
 	return;
 }
@@ -462,7 +478,6 @@ static int y_write_array(
 	zval key_zval;
 	zend_ulong kidx;
 	zend_string *kstr;
-	HashTable *tmp_ht;
 	zend_long recursive_idx = -1;
 	char *anchor = { 0 };
 	size_t anchor_size;
@@ -495,7 +510,11 @@ static int y_write_array(
 		anchor = (char*) emalloc(anchor_size + 1);
 		snprintf(anchor, anchor_size + 1, "refid%ld", recursive_idx + 1);
 
-		if (ZEND_HASH_APPLY_PROTECTION(ht) && ht->u.v.nApplyCount > 1) {
+#if PHP_VERSION_ID >= 70300
+		if (!(GC_FLAGS(ht) & GC_IMMUTABLE) && GC_IS_RECURSIVE(ht)) {
+#else
+		if (ZEND_HASH_APPLY_PROTECTION(ht) && ht->u.v.nApplyCount > 0) {
+#endif
 			/* node has been visited before */
 			status = yaml_alias_event_initialize(
 					&event, (yaml_char_t *) anchor);
@@ -536,6 +555,18 @@ static int y_write_array(
 		return FAILURE;
 	}
 
+#if PHP_VERSION_ID >= 70300
+	if (!(GC_FLAGS(ht) & GC_IMMUTABLE)) {
+		/* increment access count for hash */
+		GC_PROTECT_RECURSION(ht);
+	}
+#else
+	if (ZEND_HASH_APPLY_PROTECTION(ht)) {
+		/* increment access count for hash */
+		ht->u.v.nApplyCount++;
+	}
+#endif
+
 	/* emit array elements */
 	ZEND_HASH_FOREACH_KEY_VAL(ht, kidx, kstr, elm) {
 		ZVAL_DEREF(elm);
@@ -555,23 +586,23 @@ static int y_write_array(
 			}
 		}
 
-		tmp_ht = HASH_OF(elm);
-		if (tmp_ht && ZEND_HASH_APPLY_PROTECTION(tmp_ht)) {
-			/* increment access count for hash */
-			tmp_ht->u.v.nApplyCount++;
-		}
-
 		status = y_write_zval(state, elm, NULL TSRMLS_CC);
 
-		if (tmp_ht && ZEND_HASH_APPLY_PROTECTION(tmp_ht)) {
-			tmp_ht->u.v.nApplyCount--;
-		}
 
 		if (SUCCESS != status) {
 			return FAILURE;
 		}
 	} ZEND_HASH_FOREACH_END();
 
+#if PHP_VERSION_ID >= 70300
+	if (!(GC_FLAGS(ht) & GC_IMMUTABLE)) {
+		GC_UNPROTECT_RECURSION(ht);
+	}
+#else
+	if (ZEND_HASH_APPLY_PROTECTION(ht)) {
+		ht->u.v.nApplyCount--;
+	}
+#endif
 
 	if (Y_ARRAY_SEQUENCE == array_type) {
 		status = yaml_sequence_end_event_initialize(&event);
