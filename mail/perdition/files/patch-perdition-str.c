--- perdition/str.c.orig	2014-08-17 17:24:03.239221605 -0500
+++ perdition/str.c	2014-08-17 17:14:01.541576305 -0500
@@ -705,37 +705,6 @@
 }
 
 /**********************************************************************
- * strcasestring
- * Find the first occurrence of string in a string, case insensitively
- * pre: haystack: string to search in
- *      needle: string to search for
- * return: pointer to the first occurrence of needle
- *         NULL on error
- *
- * Note: returns a const char* rather than a char * like strstr().
- *       This seems more logical given the type of the inputs.
- *
- *       strcasestr() exists in gcc (and returns char *) but this
- *       is a GNU extension. As an implementation is needed for when
- *       perdition is compiled against other libcs, it may as be used all
- *       the time.
- **********************************************************************/
-
-const char *strcasestr(const char *haystack, const char *needle)
-{
-	size_t i, haystack_len, needle_len;
-
-	haystack_len = strlen(haystack);
-	needle_len = strlen(needle);
-
-	for (i = 0; haystack_len - i >= needle_len; i++)
-		if (!strcasecmp(haystack + i, needle))
-			return haystack + i;
-
-	return NULL;
-}
-
-/**********************************************************************
  * strcasedelimword
  * Find the first occurrence of a word in a string
  * That is, find a needle in a haystack and make sure that;
