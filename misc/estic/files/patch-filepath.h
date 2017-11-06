--- spunk/filepath.h.orig	1996-11-13 23:12:02 UTC
+++ spunk/filepath.h
@@ -88,6 +88,7 @@ int FHasWildcards (const String& Pathnam
 // Return 1 if the given path contains one of the wildcard characters '*', '?'
 // or '[]', return zero otherwise.
 
+#if 0
 int FMatch (const String& Source, const String& Pattern);
 // Match the string in Source against Pattern. Pattern may contain the
 // wildcards '*', '?', '[abcd]' '[ab-d]', '[!abcd]', '[!ab-d]'
@@ -95,6 +96,7 @@ int FMatch (const String& Source, const 
 // otherwise a non zero value is returned.
 // If Pattern contains an invalid wildcard pattern (e.g. 'A[x'), the function
 // returns zero.
+#endif
 
 int FIsAbsolute (const String& Path);
 // Return true if the given path is an absolute path
