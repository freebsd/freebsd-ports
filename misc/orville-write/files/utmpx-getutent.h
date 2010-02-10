--- getutent.h.orig	2000-01-31 22:01:13.000000000 -0800
+++ getutent.h	2010-02-02 22:49:58.043092643 -0800
@@ -14,8 +14,8 @@
 int utmpname(const char *file);
 void endutent(void);
 void setutent(void);
-struct utmp *getutent(void);
-struct utmp *getutline(const struct utmp *ut);
+struct utmpx *getutent(void);
+struct utmpx *getutline(const struct utmpx *ut);
 #endif /*HAVE_GETUTENT*/
 
 #endif /* GETUTENT_H */
