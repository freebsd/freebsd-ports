--- autorespond.c.orig	Mon Aug 18 14:41:33 2003
+++ autorespond.c	Mon Aug 18 14:42:14 2003
@@ -572,7 +572,7 @@
 	if ( *rpath == '$' )
 	{
 		rpath = safe_malloc( strlen(TheUser) + strlen(TheDomain) + 2);
-		strncpy( rpath, TheUser, strlen(TheUser) );
+		strncpy( rpath, TheUser, strlen(TheUser) + 1 );
 		strncat( rpath, "@", 1 );
 		strncat( rpath, TheDomain, strlen(TheDomain) );
 	}
