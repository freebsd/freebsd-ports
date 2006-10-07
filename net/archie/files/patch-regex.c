--- regex.c.orig	Sun Oct  1 23:04:54 2006
+++ regex.c	Sun Oct  1 23:04:56 2006
@@ -447,7 +447,7 @@
 static char *bol;
 static char *bopat[MAXTAG];
 static char *eopat[MAXTAG];
-char *pmatch();
+static char *pmatch();
 
 /*
  * re_exec:
