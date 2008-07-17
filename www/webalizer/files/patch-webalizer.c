--- webalizer.c.orig	2008-07-02 00:23:43.000000000 +0200
+++ webalizer.c	2008-07-05 09:00:42.000000000 +0200
@@ -929,7 +930,11 @@
                {
                   /* Save query portion in log.rec.srchstr */
                   strncpy(log_rec.srchstr,(char *)cp1,MAXSRCH);
+#ifdef USE_FULL_CGI_REFS
+                  *cp1++;
+#else
                   *cp1++='\0';
+#endif
                   break;
                }
                else cp1++;
