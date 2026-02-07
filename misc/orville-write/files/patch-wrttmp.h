--- wrttmp.h.orig	2000-01-26 04:26:03 UTC
+++ wrttmp.h
@@ -30,7 +30,7 @@
 #define WRTTMP_H
 
 #include <sys/types.h>
-#include <utmp.h>
+#include <utmpx.h>
 
 /* BSDI is only Unix I know of that threatens to change namesize from 8 to
  * anything else.  Most don't even have a define for it.  Here we default
@@ -38,10 +38,10 @@
  * for us.
  */
 #ifndef UT_NAMESIZE
-#define UT_NAMESIZE 8
+#define UT_NAMESIZE (sizeof(((struct utmpx *)0)->ut_user) -1)
 #endif
 #ifndef UT_LINESIZE
-#define UT_LINESIZE 8
+#define UT_LINESIZE (sizeof(((struct utmpx *)0)->ut_line) -1)
 #endif
 
 #if defined(TTY_GROUP) || defined(TTY_OTHERS)
@@ -65,9 +65,9 @@ struct wrthdr {
 	};
 
 struct wrttmp {
-	char wrt_line[UT_LINESIZE];	/* a tty line */
-	char wrt_what[UT_NAMESIZE];	/* what this user is doing? */
-	char wrt_last[UT_NAMESIZE];	/* Who did he last write to? */
+	char wrt_line[sizeof(((struct utmpx *)0)->ut_line) -1];	/* a tty line */
+	char wrt_what[sizeof(((struct utmpx *)0)->ut_user) -1];	/* what this user is doing? */
+	char wrt_last[sizeof(((struct utmpx *)0)->ut_user) -1];	/* Who did he last write to? */
 #ifndef TTYPERMS
 	char wrt_mesg;			/* user's write perms (y or n) */
 #endif /*TTYPERMS*/
