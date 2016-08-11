--- newsfetch.c.orig	2016-06-20 15:59:53 UTC
+++ newsfetch.c
@@ -7,6 +7,7 @@
 
  
 #include <stdio.h>
+#include <string.h>
 #include <signal.h>
 #include <pwd.h>
 #include <sys/types.h>
@@ -28,6 +29,7 @@ int terminate = 1;
 int wait_after_articles = 0, articles_fetched=0, last_than_current;
 int wait_for_time = 0, timeout=READ_TIMEOUT, article_fetching=0;
 int cleanup=1, max_article, news_target=0, first_article, only_list=0;
+int port = 119;
 char group[100], pipe_command[100];
 FILE *rcfp, *rctmpfp, *socket_fp[2];
 char lockfile[100];
@@ -59,6 +61,16 @@ if(argc < 2)
 	getHomedir(homedir);
 	strcpy(hostname,argv[1]);
 
+	{
+	  char *p;
+	  int n;
+
+	  if (NULL != (p = strchr(hostname, ':')) && 0 < (n = atoi(p + 1))) {
+	    port = n;
+	    *p = '\0';
+	  }
+	}
+
 	get_commandline(argc, argv, dirname, rcfile,
                 &cleanup, &wait_after_articles, &wait_for_time, 
 		&command_flag, execute_command,
@@ -75,7 +87,7 @@ if(argc < 2)
 			generateProcmailrc(homedir, rcfile, dirname, pipe_command);
 		}
 
-	socket_id=ConnectServer(hostname,119, 0);
+	socket_id=ConnectServer(hostname, port, 0);
 
 	/* two file descriptor are for portability among diff systems */
 	createFd(socket_id, socket_fp);
