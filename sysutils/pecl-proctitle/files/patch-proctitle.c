--- proctitle.c.orig	2022-12-11 12:38:30 UTC
+++ proctitle.c
@@ -69,7 +69,11 @@ PHP_MINIT_FUNCTION(proctitle)
 }
 #endif
 
-/* {{{ proto void setproctitle(string title)
+ZEND_BEGIN_ARG_INFO_EX(arginfo_title, 0, 0, 1)
+    ZEND_ARG_INFO(0, title)
+ZEND_END_ARG_INFO()
+
+/*
  * Changes the current process' title in system's list of processes
  */
 PHP_FUNCTION(setproctitle)
@@ -117,10 +121,10 @@ PHP_FUNCTION(setthreadtitle)
  *
  * Every user visible function must have an entry in proctitle_functions[].
  */
-static zend_function_entry proctitle_functions[] = {
-	PHP_FE(setproctitle,	NULL)
+static const zend_function_entry proctitle_functions[] = {
+	PHP_FE(setproctitle, arginfo_title)
 #if HAVE_PRCTL
-	PHP_FE(setthreadtitle,	NULL)
+	PHP_FE(setthreadtitle, arginfo_title)
 #endif
 	{NULL, NULL, NULL}	/* Must be the last line in proctitle_functions[] */
 };
