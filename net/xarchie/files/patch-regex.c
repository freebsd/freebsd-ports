--- regex.c.orig	Wed May 30 21:31:24 2007
+++ regex.c	Wed May 30 21:33:02 2007
@@ -438,7 +438,8 @@
 static char *bol;
 static char *bopat[MAXTAG];
 static char *eopat[MAXTAG];
-char *pmatch();
+static char *pmatch(char *lp, CHAR *ap);
+
 
 /*
  * re_exec:
