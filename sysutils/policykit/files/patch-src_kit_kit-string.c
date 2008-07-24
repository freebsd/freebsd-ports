--- src/kit/kit-string.c.orig	2008-05-30 17:24:44.000000000 -0400
+++ src/kit/kit-string.c	2008-07-24 01:21:34.000000000 -0400
@@ -123,13 +123,18 @@ static char
         if ( !s )
                 return NULL;
 
-        if ( strlen(s) > n )
-                nAvail = n + 1;
-        else
-                nAvail = strlen(s) + 1;
-        p = malloc ( nAvail );
+        if (memchr(s, '\0', n) != NULL) {
+                nAvail = strlen(s);
+                if ( nAvail > n )
+                        nAvail = n;
+        } else {
+                nAvail = n;
+        }
+        p = malloc ( nAvail + 1 );
+        if (p == NULL)
+                return NULL;
         memcpy ( p, s, nAvail );
-        p[nAvail - 1] = '\0';
+        p[nAvail] = '\0';
 
         return p;
 }
