--- php_imap.c.orig	2018-09-11 22:12:36 UTC
+++ php_imap.c
@@ -562,6 +562,15 @@ static const zend_module_dep imap_deps[]
 };
 /* }}} */
 
+
+/* {{{ PHP_INI
+ */
+PHP_INI_BEGIN()
+STD_PHP_INI_BOOLEAN("imap.enable_insecure_rsh", "0", PHP_INI_SYSTEM, OnUpdateBool, enable_rsh, zend_imap_globals, imap_globals)
+PHP_INI_END()
+/* }}} */
+
+
 /* {{{ imap_module_entry
  */
 zend_module_entry imap_module_entry = {
@@ -835,6 +844,8 @@ PHP_MINIT_FUNCTION(imap)
 {
 	unsigned long sa_all =	SA_MESSAGES | SA_RECENT | SA_UNSEEN | SA_UIDNEXT | SA_UIDVALIDITY;
 
+	REGISTER_INI_ENTRIES();
+
 #ifndef PHP_WIN32
 	mail_link(&unixdriver);		/* link in the unix driver */
 	mail_link(&mhdriver);		/* link in the mh driver */
@@ -1052,6 +1063,12 @@ PHP_MINIT_FUNCTION(imap)
 	GC_TEXTS               texts
 	*/
 
+	if (!IMAPG(enable_rsh)) {
+		/* disable SSH and RSH, see https://bugs.php.net/bug.php?id=77153 */
+		mail_parameters (NIL, SET_RSHTIMEOUT, 0);
+		mail_parameters (NIL, SET_SSHTIMEOUT, 0);
+	}
+
 	le_imap = zend_register_list_destructors_ex(mail_close_it, NULL, "imap", module_number);
 	return SUCCESS;
 }
