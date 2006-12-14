--- erpcd/ch_passwd.c.orig	Mon Jul 21 19:51:16 1997
+++ erpcd/ch_passwd.c	Thu Dec 14 13:40:15 2006
@@ -65,6 +65,9 @@
 #endif
 #endif
 
+#include <stdlib.h>
+#include <string.h>
+
 char	*strcpy();
 char	*crypt();
 char	*getpass();
@@ -87,6 +90,8 @@
 static DBM *open_dbm();
 static void unlock_database();
 #endif
+
+static int matches_password(char *, char *);
 
 static int
 alldigits(str)
