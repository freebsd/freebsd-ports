--- clamfilter.c.orig	Fri Dec  3 02:50:42 2004
+++ clamfilter.c	Sun Feb 27 18:50:00 2005
@@ -11,6 +11,7 @@
 #include <sys/wait.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <stdio.h>
 #include <syslog.h>
 #include <stdarg.h>
 #include <errno.h>
@@ -20,7 +21,7 @@
 #endif
 
 #ifndef CLAMDSCAN
-#define CLAMDSCAN "/usr/bin/clamdscan"
+#define CLAMDSCAN LOCALBASE "/bin/clamdscan"
 #endif
 
 #ifndef VIRUS_NOTIFY
@@ -63,7 +64,7 @@
 		//skip header, move to header content
 		*result += strlen(header);
 		//search for header content end
-		if (!(tmp = strstr(*result,"\n")))
+		if (!(tmp = (char *) strstr(*result,"\n")))
 		{
 			//not found - all header
 			tmp = *result+strlen(*result);
@@ -77,7 +78,7 @@
 			//skip header, move to header content
 			*result += strlen(header);
 			//search for header content end
-			if (!(tmp = strstr(*result,"\n")))
+			if (!(tmp = (char *) strstr(*result,"\n")))
 			{
 				//not found - all header
 				tmp = *result+strlen(*result);
@@ -291,7 +292,7 @@
 	int readfd,writefd;
 	int status;
 	char buffer[102401];
-	int size;
+	int size, res;
 
 	if (pipe(childread)) { 
 		syslog(LOG_MAIL|LOG_ERR, "check_file: " \
@@ -314,7 +315,7 @@
 		dup2(open("/dev/null","w"),2);
 		dup2(readfd,0);
 		dup2(open("/dev/null","w"),1);
-		int res=execl(CLAMDSCAN, CLAMDSCAN, "--quiet", temporalfile, NULL);
+		res=execl(CLAMDSCAN, CLAMDSCAN, "--quiet", temporalfile, NULL);
 		syslog(LOG_MAIL|LOG_ERR, "check_file: " \
 			"child: cannot exec, return code %d", res);
 		return(EX_TEMPFAIL);
@@ -339,8 +340,8 @@
 }
 
 
-void read_args(int argc, char** argv, const char** returnpath, 
-		const char** receipent, const char ** fromemail) {
+void read_args(int argc, char** argv, char** returnpath, 
+		char** receipent, char ** fromemail) {
 	int opt, i, j; int restlen;
 
 	while(-1 != (opt = getopt(argc, argv, "f:F:D"))) {
@@ -433,9 +434,9 @@
 	int exitcode = 0;
 	int len = 0;
 	int virusresult = 0;
-	const char *returnpath = NULL;
-	const char *receipent = NULL;
-	const char *fromemail = NULL;
+	char *returnpath = NULL;
+	char *receipent = NULL;
+	char *fromemail = NULL;
 
 	read_args(argc, argv, &returnpath, &receipent, &fromemail);
 
