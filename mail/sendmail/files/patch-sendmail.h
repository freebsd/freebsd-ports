--- sendmail/sendmail.h.orig	2016-06-12 18:23:05.239106000 -0400
+++ sendmail/sendmail.h	2016-06-12 18:42:38.972341000 -0400
@@ -2647,6 +2647,13 @@
 extern char	*milter_unknown __P((char *, ENVELOPE *, char *));
 #endif /* MILTER */
 
+#if USE_BLACKLIST
+/* blacklistd functions */
+void blacklist_init(void);
+void blacklist_notify(int, int, char *);
+#include <blacklist.h>
+#endif
+
 extern char	*addquotes __P((char *, SM_RPOOL_T *));
 extern char	*arpadate __P((char *));
 extern bool	atobool __P((char *));
