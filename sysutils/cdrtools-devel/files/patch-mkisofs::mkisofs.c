--- mkisofs/mkisofs.c.orig	Fri Apr 20 17:45:50 2001
+++ mkisofs/mkisofs.c	Mon Aug  6 10:46:21 2001
@@ -2279,11 +2279,11 @@
 		}
 	}
 	/* We don't need root privilleges anymore. */
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
