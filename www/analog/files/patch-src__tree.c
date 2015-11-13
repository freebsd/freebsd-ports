--- src/tree.c.orig	2004-12-19 13:51:31 UTC
+++ src/tree.c
@@ -769,11 +769,13 @@ void Bnextname(char **name, char **namee
     if (((*name = strstr(whole, "Mosaic")) != NULL && (len = 6)) ||
 	((*name = strstr(whole, "mosaic")) != NULL && (len = 6)) ||
 	((*name = strstr(whole, "Konqueror")) != NULL && (len = 9)) ||
+	((*name = strstr(whole, "Baiduspider")) != NULL && (len = 11)) ||
 	((*name = strstr(whole, "Galeon")) != NULL && (len = 6)) ||
 	((*name = strstr(whole, "Phoenix")) != NULL && (len = 7)) ||
 	((*name = strstr(whole, "Firebird")) != NULL && (len = 8)) ||
 	((*name = strstr(whole, "Firefox")) != NULL && (len = 7)) ||
 	((*name = strstr(whole, "Chimera")) != NULL && (len = 7)) ||
+	((*name = strstr(whole, "Chrome")) != NULL && (len = 6)) ||
 	((*name = strstr(whole, "Camino")) != NULL && (len = 6)) ||
 	((*name = strstr(whole, "Safari")) != NULL && (len = 6)) ||
 	((*name = strstr(whole, "WebTV")) != NULL && (len = 5)) ||
@@ -871,7 +873,17 @@ void Pnextname(char **name, char **namee
 	  else
 	    *name = "Windows:Unknown Windows";
 	}
-	else if (*c >= '6' && *c <= '9')
+	else if (*c == '6') {
+	  if (*(c + 1) == '.' && (*(c + 2) == '0'))
+	    *name = "Windows:Windows Vista";
+	  else if (*(c + 1) == '.' && (*(c + 2) == '1'))
+	    *name = "Windows:Windows 7";
+	  else if (*(c + 1) == '.' && (*(c + 2) == '2'))
+	    *name = "Windows:Windows 8";
+	  else
+	    *name = "Windows:Unknown Windows";
+	}
+	else if (*c >= '7' && *c <= '9')
 	  *name = "Windows:Unknown Windows";
 	else
 	  *name = "Windows:Windows NT";
@@ -904,8 +916,16 @@ void Pnextname(char **name, char **namee
 	*name = "Macintosh";
     else if (strstr(whole, "Linux") != NULL || strstr(whole, "linux") != NULL)
       *name = "Unix:Linux";
-    else if (strstr(whole, "BSD") != NULL)
-      *name = "Unix:BSD";
+    else if (strstr(whole, "FreeBSD") != NULL || strstr(whole, "freebsd") != NULL)
+      *name = "Unix:FreeBSD";
+    else if (strstr(whole, "OpenBSD") != NULL || strstr(whole, "openbsd") != NULL)
+      *name = "Unix:OpenBSD";
+    else if (strstr(whole, "NetBSD") != NULL || strstr(whole, "netbsd") != NULL)
+      *name = "Unix:NetBSD";
+    else if (strstr(whole, "BSD/OS") != NULL || strstr(whole, "bsd/os") != NULL)
+      *name = "Unix:BSD/OS";
+    else if (strstr(whole, "BSD") != NULL || strstr(whole, "bsd") != NULL)
+      *name = "Unix:Unknown BSD";
     else if (strstr(whole, "SunOS") != NULL || strstr(whole, "sunos") != NULL)
       *name = "Unix:SunOS";
     else if (strstr(whole, "HP-UX") != NULL || strstr(whole, "HPUX") != NULL ||
