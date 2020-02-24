--- Local/sa-exim.c.orig	2020-02-19 03:04:43 UTC
+++ Local/sa-exim.c
@@ -29,10 +29,7 @@ http://lists.merlins.org/lists/listinfo/sa-exim
 #include "sa-exim.h"
 
 /* Exim includes */
-#include "local_scan.h"
-extern FILE   *smtp_out;               /* Exim's incoming SMTP output file */
-extern int     body_linecount;         /* Line count in body */
-extern uschar *primary_hostname;
+#include <local_scan.h>
 
 #ifdef DLOPEN_LOCAL_SCAN
 
@@ -409,6 +406,11 @@ int parsemlheader(char *buffer, FILE *readfh, char *he
 	    if (buffer[strlen(buffer)-1] == '\n')
 	    {
 		buffer[strlen(buffer)-1]=0;
+		/* and any carriage return */
+		if (buffer[strlen(buffer)-1] == '\r')
+		{
+		    buffer[strlen(buffer)-1]=0;
+		}
 	    }
 	    if (SAEximDebug > 5)
 	    {
@@ -515,6 +517,7 @@ int local_scan(volatile int fd, uschar **return_text)
     int pid;
     int writefd[2];
     int readfd[2];
+    char *spamc_argv[10];
     int i;
     /* These are the only values that we want working after the longjmp 
      * The automatic ones can be clobbered, but we don't really care */
@@ -550,8 +553,9 @@ int local_scan(volatile int fd, uschar **return_text)
     static char *SAspamcpath=SPAMC_LOCATION;
     static char *SAsafemesgidchars=SAFEMESGIDCHARS
     static char *SAspamcSockPath=NULL;
-    static char *SAspamcPort="783";
-    static char *SAspamcHost="127.0.0.1";
+    static char *SAspamcPort=NULL;
+    static char *SAspamcHost=NULL;
+    static char *SAspamcUser=NULL;
     static char *SAEximRunCond="0";
     static char *SAEximRejCond="1";
     static int SAmaxbody=250*1024;
@@ -602,6 +606,10 @@ int local_scan(volatile int fd, uschar **return_text)
     /* Do not put a %s in there, or you'll segfault */
     static char *SAmsgerror="Temporary local error while processing message, please contact postmaster";
 
+    /* This needs to be retrieved through expand_string in order
+       not to violate the API. */
+    uschar *primary_hostname=expand_string("$primary_hostname");
+
     /* New values we read from spamassassin */
     char *xspamstatus=NULL;
     char *xspamflag=NULL;
@@ -712,6 +720,7 @@ int local_scan(volatile int fd, uschar **return_text)
 	    M_CHECKFORSTR(SAspamcSockPath);
 	    M_CHECKFORSTR(SAspamcPort);
 	    M_CHECKFORSTR(SAspamcHost);
+	    M_CHECKFORSTR(SAspamcUser);
 	    M_CHECKFORSTR(SAEximRunCond);
 	    M_CHECKFORSTR(SAEximRejCond);
 	    M_CHECKFORVAR(SAmaxbody, "%d");
@@ -914,6 +923,22 @@ int local_scan(volatile int fd, uschar **return_text)
 	ret=dup2(readfd[1],2);
 	CHECKERR(ret,"dup2 stderr",__LINE__);
 
+	i = 0;
+	spamc_argv[i++] = "spamc";
+	if (SAspamcUser && SAspamcUser[0])
+	{
+	    expand=expand_string(SAspamcUser);
+	    if (expand == NULL)
+	    {
+		log_write(0, LOG_MAIN | LOG_PANIC, "SA: SAspamcUser expansion failure on %s, will run as Exim user instead.", SAspamcUser);
+	    }
+	    else if (expand[0] != '\0')
+	    {
+		spamc_argv[i++] = "-u";
+		spamc_argv[i++] = expand;
+	    }
+	}
+
 	/* 
          * I could implement the spamc protocol and talk to spamd directly
          * instead of forking spamc, but considering the overhead spent
@@ -924,17 +949,30 @@ int local_scan(volatile int fd, uschar **return_text)
 	/* Ok, we cheat, spamc cares about how big the whole message is and
          * we only know about the body size, so I'll  give an extra 16K
          * to account for any headers that can accompany the message */
+
+	spamc_argv[i++] = "-s";
+	spamc_argv[i++] = string_sprintf("%d", SAmaxbody+16384);
+
 	if(SAspamcSockPath)
 	{
-	    ret=execl(SAspamcpath, "spamc", "-s", string_sprintf("%d", SAmaxbody+16384), "-U", SAspamcSockPath, NULL);
-	    CHECKERR(ret,string_sprintf("exec %s", SAspamcpath),__LINE__);
+    	    spamc_argv[i++] = "-U";
+	    spamc_argv[i++] = SAspamcSockPath;
 	}
 	else
 	{
-	    ret=execl(SAspamcpath, "spamc", "-s", string_sprintf("%d", SAmaxbody+16384), "-d", SAspamcHost, "-p", SAspamcPort, NULL);
-	    CHECKERR(ret,string_sprintf("exec %s", SAspamcpath),__LINE__);
+	    if (SAspamcHost) {
+		spamc_argv[i++] = "-d";
+		spamc_argv[i++] = SAspamcHost;
+	    }
+	    if (SAspamcPort) {
+		spamc_argv[i++] = "-p";
+		spamc_argv[i++] = SAspamcPort;
+	    }
 	}
-	
+	spamc_argv[i++] = NULL;
+
+	ret=execv(SAspamcpath, spamc_argv);
+	CHECKERR(ret,string_sprintf("exec %s", SAspamcpath),__LINE__);
     }
 
     if (SAEximDebug > 8)
@@ -1045,6 +1083,11 @@ int local_scan(volatile int fd, uschar **return_text)
 	if (buffer[strlen(buffer)-1] == '\n')
 	{
 	    buffer[strlen(buffer)-1]=0;
+	    /* and any carriage return */
+	    if (buffer[strlen(buffer)-1] == '\r')
+	    {
+		buffer[strlen(buffer)-1]=0;
+	    }
 	}
 restart:
 	if (SAEximDebug > 5)
@@ -1218,7 +1261,7 @@ restart:
 	    }
 
 	    stret=write(fd, buffer, strlen(buffer));
-	    CHECKERR(stret,string_sprintf("SA body write to msg"),__LINE__);
+	    CHECKERR(stret,string_sprintf("%s", "SA body write to msg"),__LINE__);
 	    if (SAEximDebug > 8)
 	    {
 		log_write(0, LOG_MAIN, "SA: Debug9: Wrote to msg; line %d (wrote %d)", line, ret);
@@ -1229,18 +1272,20 @@ restart:
 	    }
 	}
 
+	
 	if (SAEximDebug > 1)
 	{
 	    log_write(0, LOG_MAIN, "SA: Debug2: body_linecount before SA: %d", body_linecount);
 	}
 
 	/* update global variable $body_linecount to reflect the new body size*/
-	body_linecount = (line - 1);
+	if (body_linecount > 0) body_linecount = (line - 1); // Not updating if zero, indicating spool_wireformat
 
 	if (SAEximDebug > 1)
 	{
 	    log_write(0, LOG_MAIN, "SA: Debug2: body_linecount after SA: %d", body_linecount);
 	}
+
     }
 
     fclose((FILE *)readfh);
@@ -1331,6 +1376,9 @@ restart:
 	
 	if (dorej && doteergrube)
 	{
+	    char *teergrubewaitstr;
+	    teergrubewaitstr=string_sprintf(SAmsgteergrubewait, spamstatus);
+
 	    /* By default, we'll only save temp bounces by message ID so
 	     * that when the same message is submitted several times, we
 	     * overwrite the same file on disk and not create a brand new
@@ -1353,20 +1401,8 @@ restart:
 
 	    for (i=0;i<SAteergrubetime/10;i++)
 	    {
-		char *str;
-		
-		/* Unfortunately, we can't use exim's smtp_printf because it
-		 * doesn't return an error code if the write gets an EPIPE.
-		 * So, we write ourselves, but this won't work if you have a
-		 * TLS connection opened (that said, if you are teergrubing
-		 * a TLS connection, it's probably a relay host, not a
-		 * spammer, and in this case you should not teergrube a
-		 * friendly relay, so basically we should be ok).
-		 * If you do teergrube an SSL connection with the current
-		 * code, you will break it, but that's acceptable */
-		str=string_sprintf(string_sprintf("451- %s\r\n",SAmsgteergrubewait), spamstatus);
-		fprintf(smtp_out, str);
-		ret=fflush(smtp_out);
+		smtp_printf("451-%s\r\n", teergrubewaitstr);
+		ret=smtp_fflush();
 		if (ret != 0)
 		{
 		    log_write(0, LOG_MAIN | LOG_REJECT, "SA: Action: teergrubed sender for %d secs until it closed the connection: %s (scanned in %d/%d secs | Message-Id: %s). %s", i*10, spamstatus, scantime, fulltime, safemesgid, mailinfo);
