--- appl/telnet/telnetd/termstat.c.orig	Wed Feb 28 14:06:51 2001
+++ appl/telnet/telnetd/termstat.c	Thu Jul 19 19:22:54 2001
@@ -283,10 +283,9 @@
 # endif	/* KLUDGELINEMODE */
 			send_do(TELOPT_LINEMODE, 1);
 			/* send along edit modes */
-			(void) sprintf(nfrontp, "%c%c%c%c%c%c%c", IAC, SB,
+			output_data("%c%c%c%c%c%c%c", IAC, SB,
 				TELOPT_LINEMODE, LM_MODE, useeditmode,
 				IAC, SE);
-			nfrontp += 7;
 			editmode = useeditmode;
 # ifdef	KLUDGELINEMODE
 		}
@@ -312,10 +311,9 @@
 			/*
 			 * Send along appropriate edit mode mask.
 			 */
-			(void) sprintf(nfrontp, "%c%c%c%c%c%c%c", IAC, SB,
+			output_data("%c%c%c%c%c%c%c", IAC, SB,
 				TELOPT_LINEMODE, LM_MODE, useeditmode,
 				IAC, SE);
-			nfrontp += 7;
 			editmode = useeditmode;
 		}
 							
@@ -359,20 +357,18 @@
 	if (his_state_is_will(TELOPT_LFLOW)) {
 		if (tty_flowmode() != flowmode) {
 			flowmode = tty_flowmode();
-			(void) sprintf(nfrontp, "%c%c%c%c%c%c",
+			output_data("%c%c%c%c%c%c",
 					IAC, SB, TELOPT_LFLOW,
 					flowmode ? LFLOW_ON : LFLOW_OFF,
 					IAC, SE);
-			nfrontp += 6;
 		}
 		if (tty_restartany() != restartany) {
 			restartany = tty_restartany();
-			(void) sprintf(nfrontp, "%c%c%c%c%c%c",
+			output_data("%c%c%c%c%c%c",
 					IAC, SB, TELOPT_LFLOW,
 					restartany ? LFLOW_RESTART_ANY
 						   : LFLOW_RESTART_XON,
 					IAC, SE);
-			nfrontp += 6;
 		}
 	}
 }
@@ -445,10 +441,9 @@
 					useeditmode |= MODE_SOFT_TAB;
 				if (tty_islitecho())
 					useeditmode |= MODE_LIT_ECHO;
-				(void) sprintf(nfrontp, "%c%c%c%c%c%c%c", IAC,
+				output_data("%c%c%c%c%c%c%c", IAC,
 					SB, TELOPT_LINEMODE, LM_MODE,
 							useeditmode, IAC, SE);
-				nfrontp += 7;
 				editmode = useeditmode;
 			}
 
@@ -504,11 +499,10 @@
 			set_termbuf();
 
  			if (!ack) {
- 				(void) sprintf(nfrontp, "%c%c%c%c%c%c%c", IAC,
+				output_data("%c%c%c%c%c%c%c", IAC,
 					SB, TELOPT_LINEMODE, LM_MODE,
  					useeditmode|MODE_ACK,
  					IAC, SE);
- 				nfrontp += 7;
  			}
  		
 			editmode = useeditmode;
