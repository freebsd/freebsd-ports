--- hydra.c.orig	Fri Oct 17 16:25:46 2003
+++ hydra.c	Fri Oct 17 16:25:46 2003
@@ -55,33 +55,30 @@
 static pid_t pids[MAXTASKS];
 
 void help() {
-    printf("%s %s (c) 2002 by %s %s
-Syntax:  %s [[[-l LOGIN|-L FILE] [-p PASS|-P FILE]] | [-C FILE]] [-o FILE] [-t TASKS] [-g TASKS] [-w TIME] [-f] [-e ns] [-s PORT] [-S] server service [OPT]\n",
+    printf("%s %s (c) 2002 by %s %s\n"\
+"Syntax:  %s [[[-l LOGIN|-L FILE] [-p PASS|-P FILE]] | [-C FILE]] [-o FILE] [-t TASKS] [-g TASKS] [-w TIME] [-f] [-e ns] [-s PORT] [-S] server service [OPT]\n",
 PROGRAM,VERSION,AUTHOR,EMAIL,prg);
 printf("\nOptions:");
 #ifdef HYDRA_SSL
-printf("
-    -S        connect via SSL");
+printf("\n    -S        connect via SSL");
 #endif
-printf("
-    -s PORT   if the service is on a different default port, define it here
-    -l LOGIN or -L FILE login with LOGIN name, or load several logins from FILE
-    -p PASS  or -P FILE try password PASS, or load several passwords from FILE
-    -e ns     additional checks, \"n\" for null password, \"s\" try login as pass
-    -C FILE   colon seperated \"login:pass\" format, instead of -L/-P option
-    -o FILE   write found login/password pairs to FILE instead of stdout
-    -f        exit after the first found login/password pair
-    -t TASKS  run TASKS number of connects in parallel (default: %d)
-    -g TASKS  start TASKS number per second until -t TASKS are reached
-    -w TIME   in seconds, defines the max wait reply time (default: %d)
-    server    the target server
-    service   the service to crack. Supported protocols: [%s]
-    OPT       some service modules need additional input, put it here
-
-%s is a tool to guess valid login/password pairs on a target server.
-You can always find the newest version at %s
-Use this tool only for legal purposes!
-",TASKS,WAITTIME,SERVICES,PROGRAM,RESSOURCE);
+printf("\n"\
+"    -s PORT   if the service is on a different default port, define it here\n"\
+"    -l LOGIN or -L FILE login with LOGIN name, or load several logins from FILE\n"\
+"    -p PASS  or -P FILE try password PASS, or load several passwords from FILE\n"\
+"    -e ns     additional checks, \"n\" for null password, \"s\" try login as pass\n"\
+"    -C FILE   colon seperated \"login:pass\" format, instead of -L/-P option\n"\
+"    -o FILE   write found login/password pairs to FILE instead of stdout\n"\
+"    -f        exit after the first found login/password pair\n"\
+"    -t TASKS  run TASKS number of connects in parallel (default: %d)\n"\
+"    -g TASKS  start TASKS number per second until -t TASKS are reached\n"\
+"    -w TIME   in seconds, defines the max wait reply time (default: %d)\n"\
+"    server    the target server\n"\
+"    service   the service to crack. Supported protocols: [%s]\n"\
+"    OPT       some service modules need additional input, put it here\n\n"\
+"%s is a tool to guess valid login/password pairs on a target server.\n"\
+"You can always find the newest version at %s\n"\
+"Use this tool only for legal purposes!\n",TASKS,WAITTIME,SERVICES,PROGRAM,RESSOURCE);
     exit(-1);
 }
 
