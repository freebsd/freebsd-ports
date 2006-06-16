--- vdelivermail.c.orig	Fri Sep  2 21:47:29 2005
+++ vdelivermail.c	Thu Jun 15 16:50:36 2006
@@ -201,7 +201,7 @@
     if ( is_domain_valid(TheDomain) != 0 )
         vexiterr (EXIT_BOUNCE, "invalid domain name");
 
-    strncpy(TheUserFull, TheUser, sizeof(TheUserFull));
+    snprintf (TheUserFull, sizeof(TheUserFull), "%s", TheUser);
 
 #ifdef QMAIL_EXT
     /* !! Shouldn't this work its way backwards, and try all possibilities?
@@ -247,7 +247,7 @@
 
     /* check for wildcard if there's no match */
     if(tmpstr == NULL) {
-        for(i=strlen(TheUser);i >= 0 && j != 1;--i) {
+        for(i=strlen(TheUser);i > 0 && j != 1;--i) {
             if(TheUser[i-1]=='-') {
                 tmpuser[0] = '\0';
                 strncat(tmpuser,TheUser,i); 
@@ -547,10 +547,10 @@
             if (user_over_maildirquota(address,format_maildirquota(quota))==1) {
 
                 /* check for over quota message in domain */
-                sprintf(tmp_file, "%s/.over-quota.msg",TheDomainDir);
+                snprintf(tmp_file, sizeof(tmp_file), "%s/.over-quota.msg",TheDomainDir);
                 if ( (fs=fopen(tmp_file, "r")) == NULL ) {
                     /* if no domain over quota then check in vpopmail dir */
-                    sprintf(tmp_file, "%s/%s/.over-quota.msg",VPOPMAILDIR,DOMAINS_DIR);
+                    snprintf(tmp_file, sizeof(tmp_file), "%s/%s/.over-quota.msg",VPOPMAILDIR,DOMAINS_DIR);
                     fs=fopen(tmp_file, "r");
                 }
 
@@ -577,10 +577,10 @@
         if (domain_over_maildirquota(address)==1)
         {
             /* check for over quota message in domain */
-            sprintf(tmp_file, "%s/.over-quota.msg",TheDomainDir);
+            snprintf(tmp_file, sizeof(tmp_file), "%s/.over-quota.msg",TheDomainDir);
             if ( (fs=fopen(tmp_file, "r")) == NULL ) {
                 /* if no domain over quota then check in vpopmail dir */
-                sprintf(tmp_file, "%s/%s/.over-quota.msg",VPOPMAILDIR,DOMAINS_DIR);
+                snprintf(tmp_file, sizeof(tmp_file), "%s/%s/.over-quota.msg",VPOPMAILDIR,DOMAINS_DIR);
                 fs=fopen(tmp_file, "r");
             }
 
@@ -769,6 +769,7 @@
      printf("Unable to fork: %d.", errno); 
      vexit(EXIT_DEFER);
    case 0:
+     setenv("SHELL", "/bin/sh", 1);
      args[0] = "/bin/sh"; args[1] = "-c"; args[2] = prog; args[3] = 0;
      sig_catch(SIGPIPE,SIG_DFL);
      execv(*args,args);
@@ -943,10 +944,10 @@
       FILE *fs;
       char tmp_file[256];
 
-        sprintf(tmp_file, "%s/.no-user.msg",TheDomainDir);
+        snprintf(tmp_file, sizeof(tmp_file), "%s/.no-user.msg",TheDomainDir);
         if ( (fs=fopen(tmp_file, "r")) == NULL ) {
             /* if no domain no user then check in vpopmail dir */
-            sprintf(tmp_file, "%s/%s/.no-user.msg",VPOPMAILDIR,DOMAINS_DIR);
+            snprintf(tmp_file, sizeof(tmp_file), "%s/%s/.no-user.msg",VPOPMAILDIR,DOMAINS_DIR);
             fs=fopen(tmp_file, "r");
         }
         if ( fs == NULL ) {
@@ -993,7 +994,7 @@
  struct stat     sb;
  char quotawarnmsg[BUFF_SIZE];
 
-    sprintf (quotawarnmsg, "%s%s", dir, "/quotawarn");
+    snprintf (quotawarnmsg, sizeof(quotawarnmsg), "%s%s", dir, "/quotawarn");
     time(&tm);
 
     /* Send only one warning every 24 hours */
@@ -1011,12 +1012,12 @@
     close(fd);
 
     /* Look in the domain for a .quotawarn.msg */
-    sprintf(quotawarnmsg, "%s/.quotawarn.msg", TheDomainDir);
+    snprintf(quotawarnmsg, sizeof(quotawarnmsg), "%s/.quotawarn.msg", TheDomainDir);
     if ( ((read_fd = open(quotawarnmsg, O_RDONLY)) < 0) || 
            (stat(quotawarnmsg, &sb) != 0)) {
 
         /* if that fails look in vpopmail dir */
-        sprintf(quotawarnmsg, "%s/%s/.quotawarn.msg", VPOPMAILDIR, DOMAINS_DIR);
+        snprintf(quotawarnmsg, sizeof(quotawarnmsg), "%s/%s/.quotawarn.msg", VPOPMAILDIR, DOMAINS_DIR);
         if ( ((read_fd = open(quotawarnmsg, O_RDONLY)) < 0) || 
               (stat(quotawarnmsg, &sb) != 0)) {
             return 0;
