--- radiusd/builddbm.c.orig	2008-12-15 08:03:24 UTC
+++ radiusd/builddbm.c
@@ -58,7 +58,7 @@ append_symbol(DBM_closure *closure, User
 
         if (2 + check_len + reply_len > closure->pair_buffer_size) {
                 grad_log(GRAD_LOG_ERR, "%s:%d: %s",
-                         closure->filename, sym->lineno,
+                         closure->filename, sym->loc.line,
 		         _("too many attributes"));
                 return -1;
         }
