--- libschily/fnmatch.c.orig	2017-08-29 23:04:40 UTC
+++ libschily/fnmatch.c
@@ -369,11 +369,11 @@ rangematch(pattern, test, flags, newp, p
 					/*
 					 * Convert to the other case
 					 */
-					if (strcmp(class, "upper") == 0)
+					if (strcmp(class, "upper") == 0) {
 						if (iswctype(otest,
 						    wctype("lower")))
 							ok = 1;
-					else if (strcmp(class, "lower") == 0)
+					} else if (strcmp(class, "lower") == 0)
 						if (iswctype(otest,
 						    wctype("upper")))
 							ok = 1;
