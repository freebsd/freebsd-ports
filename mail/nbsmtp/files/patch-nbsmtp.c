--- nbsmtp.c.orig	Sat Apr  7 02:09:01 2001
+++ nbsmtp.c	Wed Apr 10 22:03:27 2002
@@ -19,6 +19,8 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -76,42 +78,45 @@
 {
   printf("Usage:\n");
   printf("%s -d domain -f from@addr -h host [-p port] [-l debuglevel]\n", prog);
+  exit(EXIT_FAILURE);
 }
 
 int main(int argc, char *argv[])
 {
-  int i;
+  int ch;
 
-  for(i=1; i<argc; i+=2){
-    switch(*(argv[i]+1))
+  while ( (ch = getopt(argc, argv, "h:d:f:p:l:")) != -1){
+    switch (ch)
       {
       case 'h':
-	host = (char *)strdup(argv[i+1]);
+	host = strdup(optarg);
 	break;
       case 'd':
-	domain = (char *)strdup(argv[i+1]);
+	domain = strdup(optarg);
 	break;
       case 'f':
-	fromaddr = (char *)strdup(argv[i+1]);
+	fromaddr = strdup(optarg);
 	break;
       case 'p':
-	port = atoi(argv[i+1]);
+	port = atoi(optarg);
 	break;
       case 'l':
-	debug_level =  atoi(argv[i+1]);
+	debug_level = atoi(optarg);
 	if(debug_level > 1)
 	  stdlog = fopen("nbsmtp.log", "w");
 	else
 	  stdlog = stdout;
 	break;
+      case '?':
       default:
 	print_usage(argv[0]);
+	break;
       }
   }
 
+  argc -= optind;
   if(domain==NULL || fromaddr==NULL || host==NULL){
     print_usage(argv[0]);
-    return 1;
   }
 
   if(port==0)
