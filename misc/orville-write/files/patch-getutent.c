--- getutent.c.orig	2000-01-31 22:02:45.000000000 -0800
+++ getutent.c	2010-02-02 22:53:30.347068707 -0800
@@ -20,18 +20,8 @@
 {
     if (utmp.state == 0)
     {
-	if ((utmp.fd= open(utmp.fname ? utmp.fname : _PATH_UTMP,
-		O_RDONLY)) < 0)
-	{
-	    utmp.state= -1;
-	    return -1;
-	}
-	else
-	{
 	    utmp.state= 1;
-	    fcntl(utmp.fd, F_SETFD, 1);		/* Close over execs */
 	    return 0;
-	}
     }
 }
 
@@ -42,8 +32,7 @@
 void endutent()
 {
     if (utmp.state == 1)
-    	close(utmp.fd);
-    utmp.state= 0;
+    	utmp.state= 0;
 }
 
 
@@ -52,8 +41,7 @@
 
 void setutent()
 {
-    if (utmp.state == 1)
-    	lseek(utmp.fd, 0L, 0);
+	;
 }
 
 
@@ -75,9 +63,9 @@
 /* GETUTENT - Read the next entry from the utmp file into static storage.
  */
 
-struct utmp *getutent()
+struct utmpx *getutent()
 {
-static struct utmp ut;
+static struct utmpx *ut;
 
     switch (utmp.state)
     {
@@ -85,11 +73,11 @@
 	openut();
     	/* Drop through */
     case 1:
-	if (read(utmp.fd, &ut, sizeof(struct utmp)) == sizeof(struct utmp))
-	    return &ut;
+	if ((ut = getutxent()) != NULL)
+	    return ut;
     	/* Drop through */
     default:
-    	return (struct utmp *)NULL;
+    	return (struct utmpx *)NULL;
     }
 }
 
@@ -100,9 +88,9 @@
  * we conform with Linux and Solaris.
  */
 
-struct utmp *getutline(const struct utmp *in)
+struct utmpx *getutline(const struct utmpx *in)
 {
-static struct utmp ut;
+static struct utmpx *ut;
 
     switch (utmp.state)
     {
@@ -110,20 +98,20 @@
 	openut();
     	/* Drop through */
     case 1:
-	while (read(utmp.fd, &ut, sizeof(struct utmp)) == sizeof(struct utmp))
+	while ((ut = getutxent()) != NULL)
 	{
 	    if (
 #if defined(USER_PROCESS) && defined(LOGIN_PROCESS)
-	        (ut.ut_type == USER_PROCESS || ut.ut_type == LOGIN_PROCESS) &&
+	        (ut->ut_type == USER_PROCESS || ut->ut_type == LOGIN_PROCESS) &&
 #endif
-		!strncmp(ut.ut_line, in->ut_line, UT_LINESIZE))
+		!strncmp(ut->ut_line, in->ut_line, sizeof(ut->ut_line)))
 	    {
-		return &ut;
+		return ut;
 	    }
     	}
     	/* Drop through */
     default:
-    	return (struct utmp *)NULL;
+    	return (struct utmpx *)NULL;
     }
 }
 
