--- src/imapd/imapd.c.orig	2008-11-18 19:46:59.000000000 +0100
+++ src/imapd/imapd.c	2009-01-16 10:23:02.000000000 +0100
@@ -37,6 +37,11 @@
 #include "newsrc.h"
 #include <sys/stat.h>
 
+#ifdef DRAC_AUTH
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#include <stdlib.h>
+#endif /* DRAC_AUTH */
 
 #define CRLF PSOUT ("\015\012")	/* primary output terpri */
 
@@ -207,6 +212,12 @@
 
 /* Global storage */
 
+#ifdef DRAC_AUTH
+#define DRACTIMEOUT 10*60     /* check every 10 minutes */
+time_t lastdrac = 0;          /* time of last drac check */
+extern char *getenv ();
+#endif /* DRAC_AUTH */
+
 char *version = "404";		/* edit number of this server */
 char *logout = "Logout";	/* syslogreason for logout */
 char *goodbye = NIL;		/* bye reason */
@@ -283,7 +294,50 @@
   msg_string_next,		/* get next byte in string structure */
   msg_string_setpos		/* set position in string structure */
 };
-
+
+#ifdef DRAC_AUTH
+/* DRAC Authorization
+ */
+void drac_auth ()
+{
+  if (time (0) > lastdrac + DRACTIMEOUT)
+  {
+	  FILE *dracconf;
+	  char host[100];
+	  char *drachost;
+	  char *err;
+	  char *p;
+
+	  if ( (dracconf = fopen(ETC_DIR "/dracd.host", "r")) == NULL)
+	  {
+		syslog (LOG_INFO, "dracd: error opening %s/dracd.host config file",ETC_DIR);
+		exit(1);
+	  }
+
+	  fgets(host, 100, dracconf);
+	  p = strchr(host, '\n');
+	  if(p != NULL)
+		*p = '\0';
+	  fclose(dracconf);
+
+	  if( drachost = (host) )
+	  {
+		  struct sockaddr_in sin;
+		  int sinlen = sizeof (struct sockaddr_in);
+		  char *client = getpeername (0,(struct sockaddr *) &sin,(void *) &sinlen) ?
+			"UNKNOWN" : inet_ntoa (sin.sin_addr);
+
+		  lastdrac = time(0);
+
+		  if (dracauth(drachost, inet_addr(client), &err) != 0)
+			  syslog (LOG_INFO, err);
+		  else
+			  syslog (LOG_INFO, "dracd: authorized ip %s", client);
+	  }
+  }
+}
+#endif /* DRAC_AUTH */
+
 /* Main program */
 
 int main (int argc,char *argv[])
@@ -1525,6 +1579,9 @@
 	      lasterror ());
       return;
     }
+	#ifdef DRAC_AUTH
+	drac_auth();
+	#endif /* DRAC_AUTH */
 				/* change in number of messages? */
     if (existsquelled || (nmsgs != stream->nmsgs)) {
       PSOUT ("* ");
