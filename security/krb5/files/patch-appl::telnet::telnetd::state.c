--- appl/telnet/telnetd/state.c.orig	Wed Feb 28 14:06:51 2001
+++ appl/telnet/telnetd/state.c	Mon Jul 23 17:48:48 2001
@@ -33,6 +33,7 @@
 
 /* based on @(#)state.c	8.1 (Berkeley) 6/4/93 */
 
+#include <stdarg.h>
 #include "telnetd.h"
 #if	defined(AUTHENTICATION)
 #include <libtelnet/auth.h>
@@ -86,7 +87,7 @@
   if (!auth_negotiated) {
     static char *error =
       "An environment option was sent before authentication negotiation completed.\r\nThis may create a security hazard. Connection dropped.\r\n";
-    writenet(error, strlen(error));
+    output_datalen(error, strlen(error));
     netflush();
     exit(1);
   }
@@ -209,8 +210,7 @@
 				}
 
 				netclear();	/* clear buffer back */
-				*nfrontp++ = IAC;
-				*nfrontp++ = DM;
+				output_data("%c%c", IAC, DM);
 				neturg = nfrontp-1; /* off by one XXX */
 				DIAG(TD_OPTIONS,
 					printoption("td: send IAC", DM));
@@ -463,8 +463,7 @@
 			set_his_want_state_will(option);
 		do_dont_resp[option]++;
 	}
-	(void) sprintf(nfrontp, (char *)doopt, option);
-	nfrontp += sizeof (dont) - 2;
+	output_data((const char *)doopt, option);
 
 	DIAG(TD_OPTIONS, printoption("td: send do", option));
 }
@@ -683,8 +682,7 @@
 		set_his_want_state_wont(option);
 		do_dont_resp[option]++;
 	}
-	(void) sprintf(nfrontp, (char *)dont, option);
-	nfrontp += sizeof (doopt) - 2;
+	output_data((const char *)dont, option);
 
 	DIAG(TD_OPTIONS, printoption("td: send dont", option));
 }
@@ -833,8 +831,7 @@
 		set_my_want_state_will(option);
 		will_wont_resp[option]++;
 	}
-	(void) sprintf(nfrontp, (char *)will, option);
-	nfrontp += sizeof (doopt) - 2;
+	output_data((const char *)will, option);
 
 	DIAG(TD_OPTIONS, printoption("td: send will", option));
 }
@@ -993,8 +990,7 @@
 		set_my_want_state_wont(option);
 		will_wont_resp[option]++;
 	}
-	(void) sprintf(nfrontp, (char *)wont, option);
-	nfrontp += sizeof (wont) - 2;
+	output_data((const char *)wont, option);
 
 	DIAG(TD_OPTIONS, printoption("td: send wont", option));
 }
@@ -1393,9 +1389,8 @@
 	    env_ovar_wrong:
 			env_ovar = OLD_ENV_VALUE;
 			env_ovalue = OLD_ENV_VAR;
-			DIAG(TD_OPTIONS, {sprintf(nfrontp,
-				"ENVIRON VALUE and VAR are reversed!\r\n");
-				nfrontp += strlen(nfrontp);});
+			DIAG(TD_OPTIONS,
+			    output_data("ENVIRON VALUE and VAR are reversed!\r\n"));
 
 		}
 	    }
@@ -1633,11 +1628,51 @@
 	ADD(IAC);
 	ADD(SE);
 
-	writenet(statusbuf, ncp - statusbuf);
+	output_datalen(statusbuf, ncp - statusbuf);
 	netflush();	/* Send it on its way */
 
 	DIAG(TD_OPTIONS,
 		{printsub('>', statusbuf, ncp - statusbuf); netflush();});
+}
+
+/*
+ * This function appends data to nfrontp and advances nfrontp.
+ */
+
+int
+output_data(const char *format, ...)
+{
+	va_list args;
+	size_t remaining, ret;
+
+	va_start(args, format);
+	remaining = BUFSIZ - (nfrontp - netobuf);
+	/* try a netflush() if the room is too low */
+	if (strlen(format) > remaining || BUFSIZ / 4 > remaining) {
+		netflush();
+		remaining = BUFSIZ - (nfrontp - netobuf);
+	}
+	ret = vsnprintf(nfrontp, remaining, format, args);
+	nfrontp += ((ret < remaining - 1) ? ret : remaining - 1);
+	va_end(args);
+	return ret;
+}
+
+int
+output_datalen(const char *buf, size_t len)
+{
+	size_t remaining;
+
+	remaining = BUFSIZ - (nfrontp - netobuf);
+	if (remaining < len) {
+		netflush();
+		remaining = BUFSIZ - (nfrontp - netobuf);
+	}
+	if (remaining < len)
+		return -1;
+	memmove(nfrontp, buf, len);
+	nfrontp += len;
+	return (len);
 }
 
 static int envvarok(varp)
