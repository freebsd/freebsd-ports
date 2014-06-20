--- qmail-local.c.orig	Sun Nov 23 18:30:43 2003
+++ qmail-local.c	Sun Nov 23 18:31:31 2003
@@ -645,7 +645,7 @@
     {
      cmds.s[j] = 0;
      k = j;
-     while ((k > i) && (cmds.s[k - 1] == ' ') || (cmds.s[k - 1] == '\t'))
+     while ((k > i) && ((cmds.s[k - 1] == ' ') || (cmds.s[k - 1] == '\t')))
        cmds.s[--k] = 0;
      switch(cmds.s[i])
       {
