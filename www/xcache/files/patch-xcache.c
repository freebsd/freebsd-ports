Index: xcache.c
===================================================================
--- xcache.c	(revision 899)
+++ xcache.c	(revision 900)
@@ -839,7 +839,7 @@
 				while (xc_stack_count(s)) {
 					entry_php = (xc_entry_php_t *) xc_stack_pop(s);
 					TRACE("unhold %d:%s", entry_php->file_inode, entry_php->entry.name.str.val);
-					entry_php->refcount ++;
+					--entry_php->refcount;
 					assert(entry_php->refcount >= 0);
 				}
 			} LEAVE_LOCK(cache);
@@ -1939,11 +1939,16 @@
 
 		if (stored_php) {
 			compiler->new_entry.php = stored_php;
-			xc_php_addref_unlocked(stored_php);
 			xc_entry_php_init(&compiler->new_entry, compiler->opened_path TSRMLS_CC);
 			stored_entry = xc_entry_php_store_unlocked(cache, compiler->entry_hash.entryslotid, &compiler->new_entry TSRMLS_CC);
-			TRACE(" cached %d:%s, holding", compiler->new_entry.file_inode, stored_entry->entry.name.str.val);
-			xc_entry_hold_php_unlocked(cache, stored_entry TSRMLS_CC);
+			if (stored_entry) {
+				xc_php_addref_unlocked(stored_php);
+				TRACE(" cached %d:%s, holding", compiler->new_entry.file_inode, stored_entry->entry.name.str.val);
+				xc_entry_hold_php_unlocked(cache, stored_entry TSRMLS_CC);
+			}
+			else {
+				gaveup = 1;
+			}
 			break;
 		}
 
@@ -2021,10 +2026,11 @@
 		}
 		/* entry_store */
 		compiler->new_entry.php = stored_php;
-		xc_php_addref_unlocked(stored_php);
 		stored_entry = xc_entry_php_store_unlocked(cache, compiler->entry_hash.entryslotid, &compiler->new_entry TSRMLS_CC);
-		if (!stored_entry) {
-			xc_php_release_unlocked(cache, stored_php);
+		if (stored_entry) {
+			xc_php_addref_unlocked(stored_php);
+			TRACE(" cached %d:%s, holding", compiler->new_entry.file_inode, stored_entry->entry.name.str.val);
+			xc_entry_hold_php_unlocked(cache, stored_entry TSRMLS_CC);
 		}
 	} LEAVE_LOCK_EX(cache);
 	/* }}} */
