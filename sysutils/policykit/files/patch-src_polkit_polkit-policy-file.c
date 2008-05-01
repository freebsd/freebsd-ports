--- src/polkit/polkit-policy-file.c.orig	2008-04-15 20:33:27.000000000 -0400
+++ src/polkit/polkit-policy-file.c	2008-04-21 23:39:16.000000000 -0400
@@ -804,27 +804,6 @@ polkit_policy_file_entry_foreach (PolKit
 
         return FALSE;
 }
-#ifdef HAVE_SOLARIS
-char *strndup ( const char *s, size_t n)
-{
-        size_t nAvail;
-        char *p;
-
-        if ( !s )
-                return 0;
-
-        if ( strlen(s) > n )
-                nAvail = n + 1;
-        else
-                nAvail = strlen(s) + 1;
-        p = malloc ( nAvail );
-        memcpy ( p, s, nAvail );
-        p[nAvail - 1] = '\0';
-
-        return p;
-}
-#endif
-
 #ifdef POLKIT_BUILD_TESTS
 
 /* this checks that the policy descriptions read from test-valid-3-lang.policy are correct */
