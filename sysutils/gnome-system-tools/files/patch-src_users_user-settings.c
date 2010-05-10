--- src/users/user-settings.c.orig	2010-01-11 19:53:32.000000000 +0100
+++ src/users/user-settings.c	2010-01-20 15:42:10.000000000 +0100
@@ -31,7 +31,15 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <stdlib.h>
+#ifdef __FreeBSD__
+# include <sys/param.h>
+# if __FreeBSD_version >= 900007
+# define HAVE_UTMPX_H
+#include <utmpx.h>
+# else
 #include <utmp.h>
+# endif
+#endif
 #include <ctype.h>
 
 #include "users-table.h"
@@ -274,10 +282,10 @@ static void
 set_login_length (GtkWidget *entry)
 {
 	gint max_len;
-#ifdef __FreeBSD__
+#if (defined(__FreeBSD__) && !defined(HAVE_UTMPX_H))
 	max_len = UT_NAMESIZE;
 #else
-	struct utmp ut;
+	struct utmpx ut;
 
 	max_len = sizeof (ut.ut_user);
 #endif
