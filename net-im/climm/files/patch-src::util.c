
$FreeBSD$

--- src/util.c	2002/04/05 10:00:08	1.1
+++ src/util.c	2002/04/05 10:03:37
@@ -343,7 +343,7 @@
 
     timeval = time (0);
     va_start (args, str);
-    sprintf (buf, "\n%-24.24s ", ctime (&timeval));
+    snprintf (buf, sizeof(buf), "\n%-24.24s ", ctime (&timeval));
     vsprintf (&buf[strlen (buf)], str, args);
     va_end (args);
 
@@ -356,12 +356,12 @@
             else
                 return -1;
         }
-        sprintf (buffer, "%s%ld.log", prG->logplace, uin);
+        snprintf (buffer, sizeof(buffer), "%s%ld.log", prG->logplace, uin);
 
 #if HAVE_SYMLINK
         if (ContactFindNick (uin))
         {
-            sprintf (symbuf, "%s%s.log", prG->logplace, ContactFindNick (uin));
+            snprintf (symbuf, sizeof(symbuf), "%s%s.log", prG->logplace, ContactFindNick (uin));
             symlink (buffer, symbuf);
         }
 #endif
