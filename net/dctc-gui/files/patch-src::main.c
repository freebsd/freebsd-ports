--- src/main.c.orig	Mon Nov 18 23:53:50 2002
+++ src/main.c	Mon Nov 18 23:55:01 2002
@@ -43,6 +43,9 @@
 GtkWidget *done_popup=NULL;
 GtkWidget *fav_popup=NULL;
 
+/* sigchld handling */
+extern void sig_chld(int);
+
 /* this string is "$HOME/.dctc" */
 GString *dctc_main_dir=NULL;
 
@@ -289,11 +292,9 @@
    sigset_t set;
 
    /* ignore SIGPIPE */
-	/* ignore SIGCHLD */
 	/* ignore SIGHUP */
    sigemptyset(&set);
    sigaddset(&set,SIGPIPE);
-   sigaddset(&set,SIGCHLD);
    sigaddset(&set,SIGHUP);
    act.sa_handler=SIG_IGN;
    act.sa_mask=set;
@@ -301,8 +302,10 @@
 
    sigprocmask(SIG_UNBLOCK,&set,NULL);
 	sigaction(SIGPIPE,&act,NULL);
-	sigaction(SIGCHLD,&act,NULL);
 	sigaction(SIGHUP,&act,NULL);
+
+   /* handle SIGCHLD */
+   signal(SIGCHLD, sig_chld); /* Prevents zombies */
 }
 
 static void start_dctc_client_from_huburl(char *dchub_url,char *profile)
