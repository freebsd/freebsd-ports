--- ./dk-filter/dk-filter.c.orig	2007-06-01 05:22:16.000000000 +0900
+++ ./dk-filter/dk-filter.c	2008-02-28 12:18:03.000000000 +0900
@@ -3650,11 +3650,12 @@
 		pw = getpwnam(become);
 		if (pw == NULL)
 		{
+			char *q;
 			uid_t uid;
 
-			uid = atoi(become);
-			if (uid != 0 && uid != LONG_MIN && uid != LONG_MAX)
+			uid = (uid_t) strtol(become, &q, 10);
+			if (*q == '\0')
 				pw = getpwuid(uid);
 			if (pw == NULL)
 			{
