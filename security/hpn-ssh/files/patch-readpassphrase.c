--- openbsd-compat/readpassphrase.c.orig	Sat Mar 30 06:08:34 2002
+++ openbsd-compat/readpassphrase.c	Sat Mar 30 06:09:33 2002
@@ -165,6 +165,13 @@
 	errno = save_errno;
 	return(nr == -1 ? NULL : buf);
 }
+
+static void handler(int s)
+{
+
+	signo = s;
+}
+
 #endif /* HAVE_READPASSPHRASE */
   
 #if 0
@@ -177,8 +184,3 @@
 }
 #endif
 
-static void handler(int s)
-{
-
-	signo = s;
-}
