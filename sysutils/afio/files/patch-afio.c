--- afio.c.orig	2018-11-30 14:25:04 UTC
+++ afio.c
@@ -3423,7 +3423,7 @@ openotty (name, asb, linkp, ispass, dozf
 	return (warn (name, syserr ()));
       break;
 #endif /* S_IFIFO */
-#ifdef	S_IFSOCK
+#ifdef	S_IFSOCK && !defined (__FreeBSD__)
     case S_IFSOCK:
       fd = 0;
       if (exists)
