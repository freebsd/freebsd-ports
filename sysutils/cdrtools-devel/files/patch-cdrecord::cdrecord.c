--- cdrecord/cdrecord.c.orig	Sat May 31 17:34:37 2003
+++ cdrecord/cdrecord.c	Sun Jun  1 16:09:02 2003
@@ -429,11 +429,11 @@
 	 */
 	if (geteuid() != getuid()) {	/* AIX does not like to do this */
 					/* If we are not root		*/
-#ifdef	HAVE_SETREUID
-		if (setreuid(-1, getuid()) < 0)
-#else
 #ifdef	HAVE_SETEUID
 		if (seteuid(getuid()) < 0)
+#else
+#ifdef	HAVE_SETREUID
+		if (setreuid(-1, getuid()) < 0)
 #else
 		if (setuid(getuid()) < 0)
 #endif
