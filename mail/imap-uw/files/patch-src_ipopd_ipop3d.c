--- src/ipopd/ipop3d.c.orig	2008-06-04 20:18:34.000000000 +0200
+++ src/ipopd/ipop3d.c	2009-01-16 10:19:50.000000000 +0100
@@ -34,6 +34,11 @@
 #include <time.h>
 #include "c-client.h"
 
+#ifdef DRAC_AUTH
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#include <stdlib.h>
+#endif /* DRAC_AUTH */
 
 #define CRLF PSOUT ("\015\012")	/* primary output terpri */
 
@@ -59,6 +64,12 @@
 
 /* Global storage */
 
+#ifdef DRAC_AUTH
+#define DRACTIMEOUT 10*60     /* check every 10 minutes */
+time_t lastdrac = 0;          /* time of last drac check */
+extern char *getenv ();
+#endif /* DRAC_AUTH */
+
 char *version = "104";		/* edit number of this server */
 short state = AUTHORIZATION;	/* server state */
 short critical = NIL;		/* non-zero if in critical code */
@@ -100,7 +111,53 @@
 int mbxopen (char *mailbox);
 long blat (char *text,long lines,unsigned long size,STRING *st);
 void rset ();
-
+#ifdef DRAC_AUTH
+void drac_auth();
+#endif /* DRAC_AUTH */
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
@@ -113,7 +170,7 @@
     (((s = strrchr (argv[0],'/')) || (s = strrchr (argv[0],'\\'))) ?
      s+1 : argv[0]) : "ipop3d";
 				/* set service name before linkage */
-  mail_parameters (NIL,SET_SERVICENAME,(void *) "pop");
+  mail_parameters (NIL,SET_SERVICENAME,(void *) "pop3");
 #include "linkage.c"
 				/* initialize server */
   server_init (pgmname,"pop3","pop3s",clkint,kodint,hupint,trmint,NIL);
@@ -228,9 +285,13 @@
 	      syslog (LOG_INFO,"AUTHENTICATE %s failure host=%.80s",s,
 		      tcp_clienthost ());
 	    }
-	    else if ((state = mbxopen ("INBOX")) == TRANSACTION)
+	    else if ((state = mbxopen ("INBOX")) == TRANSACTION) {
+		#ifdef DRAC_AUTH
+		drac_auth();
+		#endif /* DRAC_AUTH */
 	      syslog (LOG_INFO,"Auth user=%.80s host=%.80s nmsgs=%lu/%lu",
 		      user,tcp_clienthost (),nmsgs,stream->nmsgs);
+		}
 	    else syslog (LOG_INFO,"Auth user=%.80s host=%.80s no mailbox",
 			 user,tcp_clienthost ());
 	  }
@@ -260,9 +321,13 @@
 	      PSOUT ("-ERR Missing APOP argument\015\012");
 	    else if (!(user = apop_login (challenge,s,t,argc,argv)))
 	      PSOUT ("-ERR Bad APOP\015\012");
-	    else if ((state = mbxopen ("INBOX")) == TRANSACTION)
+	    else if ((state = mbxopen ("INBOX")) == TRANSACTION) {
+		#ifdef DRAC_AUTH
+		drac_auth();
+		#endif /* DRAC_AUTH */
 	      syslog (LOG_INFO,"APOP user=%.80s host=%.80s nmsgs=%lu/%lu",
 		      user,tcp_clienthost (),nmsgs,stream->nmsgs);
+		}
 	    else syslog (LOG_INFO,"APOP user=%.80s host=%.80s no mailbox",
 			 user,tcp_clienthost ());
 	  }
@@ -665,6 +730,9 @@
 				/* attempt the login */
     if (server_login (user,pass,t,argc,argv)) {
       int ret = mbxopen ("INBOX");
+	#ifdef DRAC_AUTH
+	drac_auth();
+	#endif /* DRAC_AUTH */
       if (ret == TRANSACTION)	/* mailbox opened OK? */
 	syslog (LOG_INFO,"%sLogin user=%.80s host=%.80s nmsgs=%lu/%lu",
 		t ? "Admin " : "",user,tcp_clienthost (),nmsgs,stream->nmsgs);
