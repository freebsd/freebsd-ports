--- readcd/readcd.c.orig	Fri Sep 20 09:00:12 2002
+++ readcd/readcd.c
@@ -356,11 +356,11 @@
 	/*
 	 * We don't need root privilleges anymore.
 	 */
-#ifdef	HAVE_SETREUID
-	if (setreuid(-1, getuid()) < 0)
-#else
 #ifdef	HAVE_SETEUID
 	if (seteuid(getuid()) < 0)
+#else
+#ifdef	HAVE_SETREUID
+	if (setreuid(-1, getuid()) < 0)
 #else
 	if (setuid(getuid()) < 0)
 #endif
