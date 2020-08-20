--- env.h.orig	1997-07-12 16:29:23 UTC
+++ env.h
@@ -1,4 +1,4 @@
-char **EnvVector;
+static char **EnvVector;
 void EnvInit (char **env);
 char *EnvGet (char *name);
 void EnvPut (char *name, char *value);
