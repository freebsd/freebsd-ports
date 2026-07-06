--- radiusd/builddbm.c.orig	2025-12-11 11:21:32 UTC
+++ radiusd/builddbm.c
@@ -56,7 +56,7 @@ append_symbol(DBM_closure *closure, User_symbol *sym)
 
 	if (2 + check_len + reply_len > closure->pair_buffer_size) {
 		grad_log(GRAD_LOG_ERR, "%s:%d: %s",
-			 closure->filename, sym->lineno,
+			 closure->filename, sym->loc.line,
 			 _("too many attributes"));
 		return -1;
 	}
