--- src/type1/t1load.c.orig	Sat Apr 17 21:32:53 2004
+++ src/type1/t1load.c	Sat Apr 17 21:34:43 2004
@@ -1527,6 +1527,11 @@
         parser->root.cursor = cur2;
       }
 
+      /* look for `eexec' */
+      else if ( *cur == 'e' && cur + 5 < limit &&
+                ft_strncmp( (char*)cur, "eexec", 5 ) == 0 )
+        break;
+
       /* look for `closefile' which ends the eexec section */
       else if ( *cur == 'c' && cur + 9 < limit &&
                 ft_strncmp( (char*)cur, "closefile", 9 ) == 0 )
