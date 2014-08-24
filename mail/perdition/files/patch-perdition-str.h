--- perdition/str.h.orig	2014-08-17 17:23:58.809239705 -0500
+++ perdition/str.h	2014-08-17 17:14:09.246054705 -0500
@@ -335,25 +335,6 @@
 char *str_replace(char *str, size_t n, ...);
 
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
-const char *strcasestr(const char *haystack, const char *needle);
-
-/**********************************************************************
  * strcasedelimword
  * Find the first occurrence of a word in a string
  * That is, find a needle in a haystack and make sure that;
