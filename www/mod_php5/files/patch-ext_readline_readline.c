--- ext/readline/readline.c.orig	Thu May 24 14:42:05 2001
+++ ext/readline/readline.c	Tue Dec  4 08:14:49 2001
@@ -57,7 +57,7 @@
 	PHP_FE(readline_info,  	            NULL)
 	PHP_FE(readline_add_history, 		NULL)
 	PHP_FE(readline_clear_history, 		NULL)
-#ifdef HAVE_READLINE
+#ifdef HAVE_LIBREADLINE
 	PHP_FE(readline_list_history, 		NULL)
 #else
 	PHP_FALIAS(readline_list_history, warn_not_available,			NULL)
@@ -147,7 +147,7 @@
 		add_assoc_string(return_value,"line_buffer",SAFE_STRING(rl_line_buffer),1);
 		add_assoc_long(return_value,"point",rl_point);
 		add_assoc_long(return_value,"end",rl_end);
-#ifdef HAVE_READLINE
+#ifdef HAVE_LIBREADLINE
 		add_assoc_long(return_value,"mark",rl_mark);
 		add_assoc_long(return_value,"done",rl_done);
 		add_assoc_long(return_value,"pending_input",rl_pending_input);
@@ -174,7 +174,7 @@
 			RETVAL_LONG(rl_point);
 		} else if (! strcasecmp((*what)->value.str.val,"end")) {
 			RETVAL_LONG(rl_end);
-#ifdef HAVE_READLINE
+#ifdef HAVE_LIBREADLINE
 		} else if (! strcasecmp((*what)->value.str.val,"mark")) {
 			RETVAL_LONG(rl_mark);
 		} else if (! strcasecmp((*what)->value.str.val,"done")) {
@@ -256,7 +256,7 @@
 /* }}} */
 /* {{{ proto array readline_list_history(void) 
    Lists the history */
-#ifdef HAVE_READLINE
+#ifdef HAVE_LIBREADLINE
 PHP_FUNCTION(readline_list_history)
 {
 	HIST_ENTRY **history;
