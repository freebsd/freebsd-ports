--- nsprpub/pr/src/misc/prtime.c.orig	Sun Mar 31 12:17:46 2002
+++ nsprpub/pr/src/misc/prtime.c	Tue Dec 17 21:30:30 2002
@@ -1666,12 +1666,13 @@
  * values for these two fields.
  */
 
-#if defined(SUNOS4) || (__GLIBC__ >= 2) || defined(XP_BEOS)
+#if defined(__FreeBSD__)|| defined(SUNOS4) \
+		|| (__GLIBC__ >= 2) || defined(XP_BEOS)
     if (mktime(&a) == -1) {
         PR_snprintf(buf, buflen, "can't get timezone");
         return 0;
     }
-#endif
+#endif /* check for __FreeBSD__, too <alane@freebsd.org> */
 
     return strftime(buf, buflen, fmt, &a);
 }
