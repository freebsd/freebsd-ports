This patch contains:
From: Dmitry Kohmanyuk <dk@genesyslab.com>
Subject: nntpbtr patch - looping in NEWNEWS

patch from serge@freenet.kiev.ua - locking when sleep + decl fix

patch from me (dk@farm.org): UDP time either closed on firewalls or unreliable
over dial-up, TCP time better anyway

--- nntpbtr.c.orig	Sun Jun 11 18:16:08 1995
+++ nntpbtr.c	Sun Jan 12 12:33:02 1997
@@ -49,12 +49,16 @@
 struct	passwd	*getpwnam();
 #endif
 
-off_t bytecount = 0;
 off_t bfdpos;
+
+#ifndef	RNEWS
 char batchtmp[] = BATCHTMP;
+#endif
 
 #endif
 
+off_t bytecount = 0;
+
 long MINfree = MINFREE;
 int MAXINfiles = MAXINFILES;
 char *host,	*hosts[4], **hostp, *group = "*", *distribution = "";
@@ -273,9 +277,11 @@
 	submit(1);
 	close_history();
 	printstat();
-	if( rnum && (time_flag >= 0) ) {
+	if( time_flag >= 0 ) {
 		title("PAUSE before next run");
+		getlock(host,oldtime);
 		sleep(PAUSETIME);
+		unlock(host);
 		goto repeat;
 	}
 	exit(0);
@@ -472,6 +478,7 @@
 #endif
 		log_err("connect time out expired");
 	}
+#if 0	/* disabled UDP time - unreliable */
 	if((server = udp_open(host, "time")) < 0) 
 		log_err("UDP open error");
 	signal(SIGALRM, alarm_hdlr);
@@ -486,6 +493,7 @@
 		goto finish;
 	}
 	close(server);
+#endif	/* 0 */
 	if((server = tcp_open(host, "time")) < 0) {
 		sleep(60);
 		goto repeat;
@@ -920,6 +928,8 @@
 		log_warn("send NEWNEWS error");
 rep2:
 		fflush(fd); rewind(fd); ftruncate(fileno(fd),(off_t)0);
+		title("SLEEPING - NEWNEWS failed");
+		sleep(60);
 		hfd = reconnect(host);
 		goto repeat;
 	}
