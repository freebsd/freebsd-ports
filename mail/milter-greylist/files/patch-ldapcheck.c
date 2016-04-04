--- ldapcheck.c.orig	2013-01-19 16:01:15 UTC
+++ ldapcheck.c
@@ -60,6 +60,22 @@ __RCSID("$Id: ldapcheck.c,v 1.18 2013/01
 #include "prop.h"
 #include "ldapcheck.h"
 
+#ifndef SIMPLEQ_HEAD 
+# define SIMPLEQ_HEAD			STAILQ_HEAD
+# define SIMPLEQ_HEAD_INITIALIZER	STAILQ_HEAD_INITIALIZER
+# define SIMPLEQ_ENTRY 			STAILQ_ENTRY
+# define SIMPLEQ_INIT 			STAILQ_INIT
+# define SIMPLEQ_INSERT_HEAD 		STAILQ_INSERT_HEAD
+# define SIMPLEQ_INSERT_TAIL 		STAILQ_INSERT_TAIL
+# define SIMPLEQ_INSERT_AFTER 		STAILQ_INSERT_AFTER
+# define SIMPLEQ_REMOVE_HEAD 		STAILQ_REMOVE_HEAD
+# define SIMPLEQ_FOREACH 		STAILQ_FOREACH
+# define SIMPLEQ_EMPTY 			STAILQ_EMPTY
+# define SIMPLEQ_FIRST 			STAILQ_FIRST
+# define SIMPLEQ_NEXT 			STAILQ_NEXT
+# define SIMPLEQ_REMOVE 		STAILQ_REMOVE
+#endif
+
 struct ldapconf_entry {
 	char *lc_url;
 	char *lc_dn;
