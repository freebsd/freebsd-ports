--- tclUnixSock.c.orig	Fri Apr 16 02:48:05 1999
+++ tclUnixSock.c	Wed Nov 14 23:21:18 2001
@@ -65,7 +65,7 @@
 char *
 Tcl_GetHostName()
 {
-#ifndef NO_UNAME
+#if 0
     struct utsname u;
     struct hostent *hp;
 #else
@@ -80,7 +80,7 @@
     }
 
     native = NULL;
-#ifndef NO_UNAME
+#if 0
     (VOID *) memset((VOID *) &u, (int) 0, sizeof(struct utsname));
     if (uname(&u) > -1) {				/* INTL: Native. */
         hp = gethostbyname(u.nodename);			/* INTL: Native. */
