--- src/auths/plaintext.c.orig	Tue Apr  1 14:53:33 2003
+++ src/auths/plaintext.c	Tue Apr  1 14:53:40 2003
@@ -93,7 +93,7 @@
   if (Ustrcmp(data, "=") == 0)
     {
     expand_nstring[++expand_nmax] = US"";
-    expand_nstring[expand_nmax] = 0;
+    expand_nlength[expand_nmax] = 0;
     }
   else
     {
