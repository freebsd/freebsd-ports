--- backend/implicitclass.c.orig	2019-11-29 20:18:29 UTC
+++ backend/implicitclass.c
@@ -98,7 +98,7 @@ main(int  argc,				/* I - Number of command-line args 
   ipp_attribute_t *attr;
   int     bytes;      /* Bytes copied */
   char uri[HTTP_MAX_URI];
-  char    *argv_nt[7];
+  char    *argv_nt[8];
   int     outbuflen,filefd,exit_status,dup_status;
   static const char *pattrs[] =
                 {
@@ -350,6 +350,7 @@ main(int  argc,				/* I - Number of command-line args 
       /* We will send the filtered output of the pdftoippprinter.c to
 	 the IPP Backend*/
       argv_nt[6] = tempfile_filter;
+      argv_nt[7] = NULL;
       fprintf(stderr, "DEBUG: The filtered output of pdftoippprinter is written to file %s\n",
 	      tempfile_filter);
 
@@ -383,7 +384,8 @@ main(int  argc,				/* I - Number of command-line args 
       pid_t pid = fork();
       if ( pid == 0 ) {
 	fprintf(stderr, "DEBUG: Started IPP Backend with pid: %d\n",getpid());
-	execv("/usr/lib/cups/backend/ipp",argv_nt);
+	execv(CUPS_SERVERBIN "/backend/ipp",argv_nt);
+	exit(CUPS_BACKEND_FAILED);
       } else {
 	int status;
 	waitpid(pid, &status, 0);
