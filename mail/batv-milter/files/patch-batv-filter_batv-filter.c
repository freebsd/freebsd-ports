--- ./batv-filter/batv-filter.c.orig	2009-05-28 01:16:45.000000000 +0900
+++ ./batv-filter/batv-filter.c	2009-06-04 07:30:43.000000000 +0900
@@ -53,7 +53,12 @@
 #include <openssl/sha.h>
 
 /* libsm includes */
-#include <sm/string.h>
+#ifdef WITHOUT_SMSTRING
+# define sm_strlcat     strlcat
+# define sm_strlcpy     strlcpy
+#else /* WITHOUT_SMSTRING */
+# include <sm/string.h>
+#endif /* WITHOUT_SMSTRING */
 
 /* libmilter includes */
 #ifndef DEBUG
@@ -3461,10 +3466,11 @@
 		pw = getpwnam(user);
 		if (pw == NULL)
 		{
+			char *q;
 			uid_t uid;
 
-			uid = atoi(user);
-			if (uid != 0 && uid != LONG_MIN && uid != LONG_MAX)
+			uid = (uid_t) strtol(user, &q, 10);
+			if (*q == '\0')
 				pw = getpwuid(uid);
 
 			if (pw == NULL)
