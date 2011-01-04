--- attacher.c.orig	2003-09-08 07:24:48.000000000 -0700
+++ attacher.c	2011-01-02 21:42:39.547897531 -0800
@@ -662,7 +662,7 @@
   printf("\n");
 
   prg = getenv("LOCKPRG");
-  if (prg && strcmp(prg, "builtin") && !access(prg, X_OK))
+  if (prg && (strcmp(prg, "builtin") || strcmp(prg,"builtin-passwd")) && !access(prg, X_OK))
     {
       signal(SIGCHLD, SIG_DFL);
       debug1("lockterminal: '%s' seems executable, execl it!\n", prg);
@@ -676,7 +676,11 @@
           setuid(real_uid);	/* this should be done already */
 #endif
           closeallfiles(0);	/* important: /etc/shadow may be open */
-          execl(prg, "SCREEN-LOCK", NULL);
+          if (strcmp(prg,"builtin-passwd"))
+            /* use system passsword for lock */
+            execl(prg, "SCREEN-LOCK", "-p", "-n", NULL);
+          else
+            execl(prg, "SCREEN-LOCK", NULL);
           exit(errno);
         }
       if (pid == -1)
