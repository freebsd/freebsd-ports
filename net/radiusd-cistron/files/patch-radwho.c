--- src/radwho.c.orig	2003-12-08 17:10:24.000000000 +0100
+++ src/radwho.c	2010-01-27 07:51:39.000000000 +0100
@@ -20,6 +20,7 @@
 #include <errno.h>
 #include <sys/stat.h>
 #include <sys/utsname.h>
+#include <sys/ioctl.h>
 #include <time.h>
 #include <ctype.h>
 #include <netinet/in.h>
@@ -40,18 +41,20 @@
  *	Header above output and format.
  */
 char *hdr1 = 
-"Login      Name              What  TTY  When      From      Location";
-char *ufmt1 = "%-10.10s %-17.17s %-5.5s %-4.4s %-9.9s %-9.9s %-.16s%s";
-char *ufmt1r = "%s,%s,%s,%s,%s,%s,%s%s";
-char *rfmt1 = "%-10.10s %-17.17s %-5.5s %s%-3d %-9.9s %-9.9s %-.19s%s";
-char *rfmt1r = "%s,%s,%s,%s%u,%s,%s,%s%s";
+"Login            Name              What  TTY  When      From      Location";
+char *ufmt1 = "%-16.16s %-17.17s %-5.5s %-4.4s %-9.9s %-9.9s %-.*s%s";
+char *ufmt1r = "%s,%s,%s,%s,%s,%s,%u%s";
+char *rfmt1 = "%-16.16s %-17.17s %-5.5s %s%-3d %-9.9s %-9.9s %-.*s%s";
+char *rfmt1r = "%s,%s,%s,%s%u,%s,%s,%u%s";
+#define FMT1_HOST_SIZE        13
 
 char *hdr2 = 
-"Login      Port    What   When          From       Location";
-char *ufmt2 = "%-10.10s %-6.6d %-7.7s %-13.13s %-10.10s %-.16s%s";
-char *ufmt2r = "%s,%u,%s,%s,%s,%s%s";
-char *rfmt2 = "%-10.10s %s%-5d  %-6.6s %-13.13s %-10.10s %-.28s%s";
-char *rfmt2r = "%s,%s%u,%s,%s,%s,%s%s";
+"Login           Port    What   When          From       Location";
+char *ufmt2 = "%-16.16s %-6.6d %-7.7s %-13.13s %-10.10s %-.*s%s";
+char *ufmt2r = "%s,%u,%s,%s,%s,%u%s";
+char *rfmt2 = "%-16.16s %s%-5d  %-6.6s %-13.13s %-10.10s %-.*s%s";
+char *rfmt2r = "%s,%s%u,%s,%s,%s,%u%s";
+#define FMT2_HOST_SIZE        19
 
 char *eol = "\n";
 NAS *naslist;
@@ -307,7 +310,8 @@
 		return tmp;
 	}
 	if (strncmp(tty, "cu", 2) == 0) {
-		return tmp + 2;
+		sprintf(tmp, "%.15s", tty + 2);
+		return tmp;
 	}
 	return "??";
 }
@@ -371,6 +375,8 @@
  */
 int main(int argc, char **argv)
 {
+	struct winsize	ws;
+	int extra_width = 0;
 	FILE *fp;
 	struct radutmp rt;
 	struct utmp ut;
@@ -389,6 +395,11 @@
 	char *p, *q, *portind;
 	int c, portno;
 
+	ioctl(0, TIOCGWINSZ, &ws);
+	if (ws.ws_col >= 80) {
+		extra_width = ws.ws_col - 80;
+	}
+
 	while((c = getopt(argc, argv, "Dd:flhnsipcru:")) != EOF) switch(c) {
 		case 'D':
 			use_dns = 0;
@@ -471,6 +482,55 @@
 		if (*p) sys_finger(p);
 	}
 
+#if defined(__FreeBSD__) && __FreeBSD_version > 900007
+	if (showlocal) {
+		struct utmpx *utx;
+
+		if (rawoutput == 0)
+		{	
+			fputs(showname ? hdr1 : hdr2, stdout);
+			fputs(eol, stdout);
+		}
+		hdrdone = 1;
+
+		/*
+		 *	Show the logged in UNIX users.
+		 */
+		gethostname(myname, 128);
+		setutxent();
+		for (;;) {
+			utx = getutxent();
+			if (utx == NULL)
+				break;
+			if (utx->ut_user[0] && utx->ut_line[0] &&
+			    utx->ut_type == USER_PROCESS) {
+				strncpy(inbuf, utx->ut_name, UT_NAMESIZE);
+				inbuf[UT_NAMESIZE] = '\0';
+				if (showname)
+					printf((rawoutput == 0? ufmt1: ufmt1r),
+						inbuf,
+						fullname(inbuf),
+						"shell",
+						ttyshort(utx->ut_line),
+						dotime(utx->ut_tv.tv_sec),
+						utx->ut_host,
+						FMT1_HOST_SIZE + extra_width,
+						myname, eol);
+				else
+					printf((rawoutput==0? ufmt2:ufmt2r),
+						inbuf,
+						ttyshort(utx->ut_line),
+						"shell",
+						dotime(utx->ut_tv.tv_sec),
+						utx->ut_host,
+						FMT2_HOST_SIZE + extra_width,
+						myname, eol);
+			}
+
+		}
+		endutxent();
+	}
+#else
 	if (showlocal && (fp = fopen(UTMP_FILE, "r"))) {
 		if (rawoutput == 0)
 		{	
@@ -486,14 +546,17 @@
 		while(fread(&ut, sizeof(ut), 1, fp) == 1) {
 #ifdef USER_PROCESS
 			if (ut.ut_user[0] && ut.ut_line[0] &&
-				ut.ut_type == USER_PROCESS) {
+				ut.ut_type == USER_PROCESS)
 #else
-			if (ut.ut_user[0] && ut.ut_line[0]) {
+			if (ut.ut_user[0] && ut.ut_line[0])
 #endif
-			   if (showname)
+							    {
+			    strncpy(inbuf, ut.ut_name, UT_NAMESIZE);
+			    inbuf[UT_NAMESIZE] = '\0';
+			    if (showname)
 				printf((rawoutput == 0? ufmt1: ufmt1r),
-					ut.ut_name,
-					fullname(ut.ut_name),
+					inbuf,
+					fullname(inbuf),
 					"shell",
 					ttyshort(ut.ut_line),
 #ifdef __svr4__
@@ -502,10 +565,11 @@
 					dotime(ut.ut_time),
 #endif
 					ut.ut_host,
+					FMT1_HOST_SIZE + extra_width,
 					myname, eol);
 			    else
 				printf((rawoutput==0? ufmt2:ufmt2r),
-					ut.ut_name,
+					inbuf,
 					ttyshort(ut.ut_line),
 					"shell",
 #ifdef __svr4__
@@ -514,11 +578,13 @@
 					dotime(ut.ut_time),
 #endif
 					ut.ut_host,
+					FMT2_HOST_SIZE + extra_width,
 					myname, eol);
 			}
 		}
 		fclose(fp);
 	}
+#endif
 
 	/*
 	 *	Show the users logged in on the terminal server(s).
@@ -560,6 +626,7 @@
 				portind, portno,
 				dotime(rt.time),
 				nasname(ntohl(rt.nas_address)),
+				FMT1_HOST_SIZE + extra_width,
 				hostname(rt.framed_address), eol);
 			else
 			    printf((rawoutput == 0? rfmt2: rfmt2r),
@@ -568,6 +635,7 @@
 				proto(rt.proto, rt.porttype),
 				dotime(rt.time),
 				nasname(ntohl(rt.nas_address)),
+				FMT2_HOST_SIZE + extra_width,
 				hostname(rt.framed_address), eol);
 		}
 	}
