--- appl/telnet/telnetd/telnetd.c.orig	Wed Feb 28 14:06:51 2001
+++ appl/telnet/telnetd/telnetd.c	Thu Jul 19 19:20:46 2001
@@ -782,9 +782,7 @@
 			{ IAC, SB, TELOPT_TSPEED, TELQUAL_SEND, IAC, SE };
 
 	if(nfrontp - netobuf + sizeof(sb) < sizeof(netobuf)) {
-	    memcpy(nfrontp, sb, sizeof(sb));
-	    nfrontp += sizeof(sb);
-	    *nfrontp = '\0';
+		output_datalen(sb, sizeof sb);
 	}
     }
     if (his_state_is_will(TELOPT_XDISPLOC)) {
@@ -792,9 +790,7 @@
 			{ IAC, SB, TELOPT_XDISPLOC, TELQUAL_SEND, IAC, SE };
 
 	if(nfrontp - netobuf + sizeof(sb) < sizeof(netobuf)) {
-	    memcpy(nfrontp, sb, sizeof(sb));
-	    nfrontp += sizeof(sb);
-	    *nfrontp = '\0';
+		output_datalen(sb, sizeof sb);
 	}
     }
     if (his_state_is_will(TELOPT_NEW_ENVIRON)) {
@@ -802,9 +798,7 @@
 			{ IAC, SB, TELOPT_NEW_ENVIRON, TELQUAL_SEND, IAC, SE };
 
 	if(nfrontp - netobuf + sizeof(sb) < sizeof(netobuf)) {
-	    memcpy(nfrontp, sb, sizeof(sb));
-	    nfrontp += sizeof(sb);
-	    *nfrontp = '\0';
+		output_datalen(sb, sizeof sb);
 	}
     }
     else if (his_state_is_will(TELOPT_OLD_ENVIRON)) {
@@ -812,17 +806,13 @@
 			{ IAC, SB, TELOPT_OLD_ENVIRON, TELQUAL_SEND, IAC, SE };
 
 	if(nfrontp - netobuf + sizeof(sb) < sizeof(netobuf)) {
-	    memcpy(nfrontp, sb, sizeof(sb));
-	    nfrontp += sizeof(sb);
-	    *nfrontp = '\0';
+		output_datalen(sb, sizeof sb);
 	}
     }
     if (his_state_is_will(TELOPT_TTYPE)) {
 
 	if(nfrontp - netobuf + sizeof(ttytype_sbbuf) < sizeof(netobuf)) {
-	    memcpy(nfrontp, ttytype_sbbuf, sizeof(ttytype_sbbuf));
-	    nfrontp += sizeof(ttytype_sbbuf);
-	    *nfrontp = '\0';
+		output_datalen(ttytype_sbbuf, sizeof ttytype_sbbuf);
 	}
     }
     if (his_state_is_will(TELOPT_TSPEED)) {
@@ -902,9 +892,7 @@
 	return;
     settimer(baseline);
     if(nfrontp - netobuf + sizeof(ttytype_sbbuf)) {
-    	memcpy(nfrontp, ttytype_sbbuf, sizeof(ttytype_sbbuf));
-    	nfrontp += sizeof(ttytype_sbbuf);
-	*nfrontp = '\0';
+	output_datalen(ttytype_sbbuf, sizeof ttytype_sbbuf);
     }
     while (sequenceIs(ttypesubopt, baseline))
 	ttloop();
@@ -1177,9 +1165,7 @@
 	 * mode, which we do not want.
 	 */
 	if (his_want_state_is_will(TELOPT_ECHO)) {
-		DIAG(TD_OPTIONS,
-			{sprintf(nfrontp, "td: simulating recv\r\n");
-			 nfrontp += strlen(nfrontp);});
+		DIAG(TD_OPTIONS, output_data("td: simulating recv\r\n"));
 		willoption(TELOPT_ECHO);
 	}
 
@@ -1308,9 +1294,7 @@
 	localstat();
 #endif	/* LINEMODE */
 
-	DIAG(TD_REPORT,
-		{sprintf(nfrontp, "td: Entering processing loop\r\n");
-		 nfrontp += strlen(nfrontp);});
+	DIAG(TD_REPORT, output_data("td: Entering processing loop\r\n"));
 
 #ifdef	convex
 	startslave(host);
@@ -1435,8 +1419,7 @@
 			netip = netibuf;
 		    }
 		    DIAG((TD_REPORT | TD_NETDATA),
-			    {sprintf(nfrontp, "td: netread %d chars\r\n", ncc);
-			     nfrontp += strlen(nfrontp);});
+			output_data("td: netread %d chars\r\n", ncc));
 		    DIAG(TD_NETDATA, printdata("nd", netip, ncc));
 		}
 
@@ -1483,8 +1466,7 @@
 					 * royally if we send them urgent
 					 * mode data.
 					 */
-					*nfrontp++ = IAC;
-					*nfrontp++ = DM;
+					output_data("%c%c", IAC, DM);
 					neturg = nfrontp-1; /* off by one XXX */
 #endif
 				}
@@ -1495,8 +1477,7 @@
 					    ptyibuf[0] & TIOCPKT_DOSTOP ? 1 : 0;
 					if (newflow != flowmode) {
 						flowmode = newflow;
-						(void) sprintf(nfrontp,
-							"%c%c%c%c%c%c",
+						output_data("%c%c%c%c%c%c",
 							IAC, SB, TELOPT_LFLOW,
 							flowmode ? LFLOW_ON
 								 : LFLOW_OFF,
@@ -1524,19 +1505,19 @@
 				break;
 			c = *ptyip++ & 0377, pcc--;
 			if (c == IAC)
-				*nfrontp++ = c;
+				output_data("%c", c);
 #if	defined(CRAY2) && defined(UNICOS5)
 			else if (c == '\n' &&
 				     my_state_is_wont(TELOPT_BINARY) && newmap)
-				*nfrontp++ = '\r';
+				output_data("\r");
 #endif	/* defined(CRAY2) && defined(UNICOS5) */
-			*nfrontp++ = c;
+			output_data("%c", c);
 			if ((c == '\r') && (my_state_is_wont(TELOPT_BINARY))) {
 				if (pcc > 0 && ((*ptyip & 0377) == '\n')) {
-					*nfrontp++ = *ptyip++ & 0377;
+					output_data("%c", *ptyip++ & 0377);
 					pcc--;
 				} else
-					*nfrontp++ = '\0';
+					output_data("%c", '\0');
 			}
 		}
 #if	defined(CRAY2) && defined(UNICOS5)
@@ -1707,10 +1688,7 @@
 		return;
 	}
 #endif
-	(void) strncpy(nfrontp, "\r\n[Yes]\r\n",
-		       sizeof(netobuf) - 1 - (nfrontp - netobuf));
-	nfrontp += 9;
-	*nfrontp = '\0';
+	output_data("\r\n[Yes]\r\n");
 }
 
 	void
