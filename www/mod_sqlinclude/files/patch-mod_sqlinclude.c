--- mod_sqlinclude.c.orig	Thu Oct 25 17:09:46 2001
+++ mod_sqlinclude.c	Thu Oct 25 17:10:00 2001
@@ -376,7 +376,7 @@
 	{ "SQL_SQLPassword", cmd_sqli_sqlpassword, NULL, RSRC_CONF, TAKE1,
 	 		"the MySQL password for SQLI_User. No default" },
 	{ "SQL_SQLDB", cmd_sqli_sqldb, NULL, RSRC_CONF, TAKE1,
-			"the MySQL database the module shall use. Default 'sqlinclude' },
+			"the MySQL database the module shall use. Default 'sqlinclude'" },
 				  
    { "SQL_Include", cmd_sqli_include, NULL, RSRC_CONF, TAKE1,
 			"valid SQL query. Data returned in 1st column will be passed to Apache" },
