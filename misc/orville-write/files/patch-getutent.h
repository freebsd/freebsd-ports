--- getutent.h.orig	2000-02-01 06:01:13 UTC
+++ getutent.h
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
