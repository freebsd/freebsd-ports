--- appl/telnet/telnetd/utility.c.orig	Wed Feb 28 14:06:52 2001
+++ appl/telnet/telnetd/utility.c	Thu Jul 19 19:58:05 2001
@@ -58,8 +58,7 @@
 {
     void netflush();
 
-    DIAG(TD_REPORT, {sprintf(nfrontp, "td: ttloop\r\n");
-		     nfrontp += strlen(nfrontp);});
+    DIAG(TD_REPORT, output_data("td: ttloop\r\n"));
     if (nfrontp-nbackp) {
 	netflush();
     }
@@ -74,8 +73,7 @@
 	syslog(LOG_INFO, "ttloop:  peer died: %m");
 	exit(1);
     }
-    DIAG(TD_REPORT, {sprintf(nfrontp, "td: ttloop read %d chars\r\n", ncc);
-		     nfrontp += strlen(nfrontp);});
+    DIAG(TD_REPORT, output_data("td: ttloop read %d chars\r\n", ncc));
     netip = netibuf;
     telrcv();			/* state machine */
     if (ncc > 0) {
@@ -117,9 +115,8 @@
 	int n;
 
 	if ((n = pfrontp - pbackp) > 0) {
-		DIAG((TD_REPORT | TD_PTYDATA),
-			{ sprintf(nfrontp, "td: ptyflush %d chars\r\n", n);
-			  nfrontp += strlen(nfrontp); });
+		DIAG(TD_REPORT | TD_PTYDATA,
+		    output_data("td: ptyflush %d chars\r\n", n));
 		DIAG(TD_PTYDATA, printdata("pd", pbackp, n));
 		n = write(pty, pbackp, n);
 	}
@@ -251,11 +248,9 @@
     extern int not42;
 
     if ((n = nfrontp - nbackp) > 0) {
-	DIAG(TD_REPORT,
-	    { sprintf(nfrontp, "td: netflush %d chars\r\n", n);
-	      n += strlen(nfrontp);  /* get count first */
-	      nfrontp += strlen(nfrontp);  /* then move pointer */
-	    });
+	DIAG(TD_REPORT, {
+	    n += output_data("td: netflush %d chars\r\n", n);
+	});
 #ifdef	ENCRYPTION
 	if (encrypt_output) {
 		char *s = nclearto ? nclearto : nbackp;
@@ -528,12 +523,11 @@
 	register int option;
 {
 	if (TELOPT_OK(option))
-		sprintf(nfrontp, "%s %s\r\n", fmt, TELOPT(option));
+		output_data("%s %s\r\n", fmt, TELOPT(option));
 	else if (TELCMD_OK(option))
-		sprintf(nfrontp, "%s %s\r\n", fmt, TELCMD(option));
+		output_data("%s %s\r\n", fmt, TELCMD(option));
 	else
-		sprintf(nfrontp, "%s %d\r\n", fmt, option);
-	nfrontp += strlen(nfrontp);
+		output_data("%s %d\r\n", fmt, option);
 	return;
 }
 
@@ -550,9 +544,8 @@
 		return;
 
 	if (direction) {
-	    sprintf(nfrontp, "td: %s suboption ",
+	    output_data("td: %s suboption ",
 					direction == '<' ? "recv" : "send");
-	    nfrontp += strlen(nfrontp);
 	    if (length >= 3) {
 		register int j;
 
@@ -560,232 +553,192 @@
 		j = pointer[length-1];
 
 		if (i != IAC || j != SE) {
-		    sprintf(nfrontp, "(terminated by ");
-		    nfrontp += strlen(nfrontp);
+		    output_data("(terminated by ");
 		    if (TELOPT_OK(i))
-			sprintf(nfrontp, "%s ", TELOPT(i));
+			output_data("%s ", TELOPT(i));
 		    else if (TELCMD_OK(i))
-			sprintf(nfrontp, "%s ", TELCMD(i));
+			output_data("%s ", TELCMD(i));
 		    else
-			sprintf(nfrontp, "%d ", i);
-		    nfrontp += strlen(nfrontp);
+			output_data("%d ", i);
 		    if (TELOPT_OK(j))
-			sprintf(nfrontp, "%s", TELOPT(j));
+			output_data("%s", TELOPT(j));
 		    else if (TELCMD_OK(j))
-			sprintf(nfrontp, "%s", TELCMD(j));
+			output_data("%s", TELCMD(j));
 		    else
-			sprintf(nfrontp, "%d", j);
-		    nfrontp += strlen(nfrontp);
-		    sprintf(nfrontp, ", not IAC SE!) ");
-		    nfrontp += strlen(nfrontp);
+			output_data("%d", j);
+		    output_data(", not IAC SE!) ");
 		}
 	    }
 	    length -= 2;
 	}
 	if (length < 1) {
-	    sprintf(nfrontp, "(Empty suboption??\?)");
-	    nfrontp += strlen(nfrontp);
+	    output_data("(Empty suboption??\?)");
 	    return;
 	}
 	switch (pointer[0]) {
 	case TELOPT_TTYPE:
-	    sprintf(nfrontp, "TERMINAL-TYPE ");
-	    nfrontp += strlen(nfrontp);
+	    output_data("TERMINAL-TYPE ");
 	    switch (pointer[1]) {
 	    case TELQUAL_IS:
-		sprintf(nfrontp, "IS \"%.*s\"", length-2, (char *)pointer+2);
+		output_data("IS \"%.*s\"", length-2, (char *)pointer+2);
 		break;
 	    case TELQUAL_SEND:
-		sprintf(nfrontp, "SEND");
+		output_data("SEND");
 		break;
 	    default:
-		sprintf(nfrontp,
+		output_data(
 				"- unknown qualifier %d (0x%x).",
 				pointer[1], pointer[1]);
 	    }
-	    nfrontp += strlen(nfrontp);
 	    break;
 	case TELOPT_TSPEED:
-	    sprintf(nfrontp, "TERMINAL-SPEED");
-	    nfrontp += strlen(nfrontp);
+	    output_data("TERMINAL-SPEED");
 	    if (length < 2) {
-		sprintf(nfrontp, " (empty suboption??\?)");
-		nfrontp += strlen(nfrontp);
+		output_data(" (empty suboption??\?)");
 		break;
 	    }
 	    switch (pointer[1]) {
 	    case TELQUAL_IS:
-		sprintf(nfrontp, " IS %.*s", length-2, (char *)pointer+2);
-		nfrontp += strlen(nfrontp);
+		output_data(" IS %.*s", length-2, (char *)pointer+2);
 		break;
 	    default:
 		if (pointer[1] == 1)
-		    sprintf(nfrontp, " SEND");
+		    output_data(" SEND");
 		else
-		    sprintf(nfrontp, " %d (unknown)", pointer[1]);
-		nfrontp += strlen(nfrontp);
+		    output_data(" %d (unknown)", pointer[1]);
 		for (i = 2; i < length; i++) {
-		    sprintf(nfrontp, " ?%d?", pointer[i]);
-		    nfrontp += strlen(nfrontp);
+		    output_data(" ?%d?", pointer[i]);
 		}
 		break;
 	    }
 	    break;
 
 	case TELOPT_LFLOW:
-	    sprintf(nfrontp, "TOGGLE-FLOW-CONTROL");
-	    nfrontp += strlen(nfrontp);
+	    output_data("TOGGLE-FLOW-CONTROL");
 	    if (length < 2) {
-		sprintf(nfrontp, " (empty suboption??\?)");
-		nfrontp += strlen(nfrontp);
+		output_data(" (empty suboption??\?)");
 		break;
 	    }
 	    switch (pointer[1]) {
 	    case LFLOW_OFF:
-		sprintf(nfrontp, " OFF"); break;
+		output_data(" OFF"); break;
 	    case LFLOW_ON:
-		sprintf(nfrontp, " ON"); break;
+		output_data(" ON"); break;
 	    case LFLOW_RESTART_ANY:
-		sprintf(nfrontp, " RESTART-ANY"); break;
+		output_data(" RESTART-ANY"); break;
 	    case LFLOW_RESTART_XON:
-		sprintf(nfrontp, " RESTART-XON"); break;
+		output_data(" RESTART-XON"); break;
 	    default:
-		sprintf(nfrontp, " %d (unknown)", pointer[1]);
+		output_data(" %d (unknown)", pointer[1]);
 	    }
-	    nfrontp += strlen(nfrontp);
 	    for (i = 2; i < length; i++) {
-		sprintf(nfrontp, " ?%d?", pointer[i]);
-		nfrontp += strlen(nfrontp);
+		output_data(" ?%d?", pointer[i]);
 	    }
 	    break;
 
 	case TELOPT_NAWS:
-	    sprintf(nfrontp, "NAWS");
-	    nfrontp += strlen(nfrontp);
+	    output_data("NAWS");
 	    if (length < 2) {
-		sprintf(nfrontp, " (empty suboption??\?)");
-		nfrontp += strlen(nfrontp);
+		output_data(" (empty suboption??\?)");
 		break;
 	    }
 	    if (length == 2) {
-		sprintf(nfrontp, " ?%d?", pointer[1]);
-		nfrontp += strlen(nfrontp);
+		output_data(" ?%d?", pointer[1]);
 		break;
 	    }
-	    sprintf(nfrontp, " %d %d (%d)",
+	    output_data(" %d %d (%d)",
 		pointer[1], pointer[2],
 		(int)((((unsigned int)pointer[1])<<8)|((unsigned int)pointer[2])));
-	    nfrontp += strlen(nfrontp);
 	    if (length == 4) {
-		sprintf(nfrontp, " ?%d?", pointer[3]);
-		nfrontp += strlen(nfrontp);
+		output_data(" ?%d?", pointer[3]);
 		break;
 	    }
-	    sprintf(nfrontp, " %d %d (%d)",
+	    output_data(" %d %d (%d)",
 		pointer[3], pointer[4],
 		(int)((((unsigned int)pointer[3])<<8)|((unsigned int)pointer[4])));
-	    nfrontp += strlen(nfrontp);
 	    for (i = 5; i < length; i++) {
-		sprintf(nfrontp, " ?%d?", pointer[i]);
-		nfrontp += strlen(nfrontp);
+		output_data(" ?%d?", pointer[i]);
 	    }
 	    break;
 
 	case TELOPT_LINEMODE:
-	    sprintf(nfrontp, "LINEMODE ");
-	    nfrontp += strlen(nfrontp);
+	    output_data("LINEMODE ");
 	    if (length < 2) {
-		sprintf(nfrontp, " (empty suboption??\?)");
-		nfrontp += strlen(nfrontp);
+		output_data(" (empty suboption??\?)");
 		break;
 	    }
 	    switch (pointer[1]) {
 	    case WILL:
-		sprintf(nfrontp, "WILL ");
+		output_data("WILL ");
 		goto common;
 	    case WONT:
-		sprintf(nfrontp, "WONT ");
+		output_data("WONT ");
 		goto common;
 	    case DO:
-		sprintf(nfrontp, "DO ");
+		output_data("DO ");
 		goto common;
 	    case DONT:
-		sprintf(nfrontp, "DONT ");
+		output_data("DONT ");
 	    common:
-		nfrontp += strlen(nfrontp);
 		if (length < 3) {
-		    sprintf(nfrontp, "(no option??\?)");
-		    nfrontp += strlen(nfrontp);
+		    output_data("(no option??\?)");
 		    break;
 		}
 		switch (pointer[2]) {
 		case LM_FORWARDMASK:
-		    sprintf(nfrontp, "Forward Mask");
-		    nfrontp += strlen(nfrontp);
+		    output_data("Forward Mask");
 		    for (i = 3; i < length; i++) {
-			sprintf(nfrontp, " %x", pointer[i]);
-			nfrontp += strlen(nfrontp);
+			output_data(" %x", pointer[i]);
 		    }
 		    break;
 		default:
-		    sprintf(nfrontp, "%d (unknown)", pointer[2]);
-		    nfrontp += strlen(nfrontp);
+		    output_data("%d (unknown)", pointer[2]);
 		    for (i = 3; i < length; i++) {
-			sprintf(nfrontp, " %d", pointer[i]);
-			nfrontp += strlen(nfrontp);
+			output_data(" %d", pointer[i]);
 		    }
 		    break;
 		}
 		break;
 		
 	    case LM_SLC:
-		sprintf(nfrontp, "SLC");
-		nfrontp += strlen(nfrontp);
+		output_data("SLC");
 		for (i = 2; i < length - 2; i += 3) {
 		    if (SLC_NAME_OK(pointer[i+SLC_FUNC]))
-			sprintf(nfrontp, " %s", SLC_NAME(pointer[i+SLC_FUNC]));
+			output_data(" %s", SLC_NAME(pointer[i+SLC_FUNC]));
 		    else
-			sprintf(nfrontp, " %d", pointer[i+SLC_FUNC]);
-		    nfrontp += strlen(nfrontp);
+			output_data(" %d", pointer[i+SLC_FUNC]);
 		    switch (pointer[i+SLC_FLAGS]&SLC_LEVELBITS) {
 		    case SLC_NOSUPPORT:
-			sprintf(nfrontp, " NOSUPPORT"); break;
+			output_data(" NOSUPPORT"); break;
 		    case SLC_CANTCHANGE:
-			sprintf(nfrontp, " CANTCHANGE"); break;
+			output_data(" CANTCHANGE"); break;
 		    case SLC_VARIABLE:
-			sprintf(nfrontp, " VARIABLE"); break;
+			output_data(" VARIABLE"); break;
 		    case SLC_DEFAULT:
-			sprintf(nfrontp, " DEFAULT"); break;
+			output_data(" DEFAULT"); break;
 		    }
-		    nfrontp += strlen(nfrontp);
-		    sprintf(nfrontp, "%s%s%s",
+		    output_data("%s%s%s",
 			pointer[i+SLC_FLAGS]&SLC_ACK ? "|ACK" : "",
 			pointer[i+SLC_FLAGS]&SLC_FLUSHIN ? "|FLUSHIN" : "",
 			pointer[i+SLC_FLAGS]&SLC_FLUSHOUT ? "|FLUSHOUT" : "");
-		    nfrontp += strlen(nfrontp);
 		    if (pointer[i+SLC_FLAGS]& ~(SLC_ACK|SLC_FLUSHIN|
 						SLC_FLUSHOUT| SLC_LEVELBITS)) {
-			sprintf(nfrontp, "(0x%x)", pointer[i+SLC_FLAGS]);
-			nfrontp += strlen(nfrontp);
+			output_data("(0x%x)", pointer[i+SLC_FLAGS]);
 		    }
-		    sprintf(nfrontp, " %d;", pointer[i+SLC_VALUE]);
-		    nfrontp += strlen(nfrontp);
+		    output_data(" %d;", pointer[i+SLC_VALUE]);
 		    if ((pointer[i+SLC_VALUE] == IAC) &&
 			(pointer[i+SLC_VALUE+1] == IAC))
 				i++;
 		}
 		for (; i < length; i++) {
-		    sprintf(nfrontp, " ?%d?", pointer[i]);
-		    nfrontp += strlen(nfrontp);
+		    output_data(" ?%d?", pointer[i]);
 		}
 		break;
 
 	    case LM_MODE:
-		sprintf(nfrontp, "MODE ");
-		nfrontp += strlen(nfrontp);
+		output_data("MODE ");
 		if (length < 3) {
-		    sprintf(nfrontp, "(no mode??\?)");
-		    nfrontp += strlen(nfrontp);
+		    output_data("(no mode??\?)");
 		    break;
 		}
 		{
@@ -796,24 +749,19 @@
 			pointer[2]&MODE_SOFT_TAB ? "|SOFT_TAB" : "",
 			pointer[2]&MODE_LIT_ECHO ? "|LIT_ECHO" : "",
 			pointer[2]&MODE_ACK ? "|ACK" : "");
-		    sprintf(nfrontp, "%s", tbuf[1] ? &tbuf[1] : "0");
-		    nfrontp += strlen(nfrontp);
+		    output_data("%s", tbuf[1] ? &tbuf[1] : "0");
 		}
 		if (pointer[2]&~(MODE_EDIT|MODE_TRAPSIG|MODE_ACK)) {
-		    sprintf(nfrontp, " (0x%x)", pointer[2]);
-		    nfrontp += strlen(nfrontp);
+		    output_data(" (0x%x)", pointer[2]);
 		}
 		for (i = 3; i < length; i++) {
-		    sprintf(nfrontp, " ?0x%x?", pointer[i]);
-		    nfrontp += strlen(nfrontp);
+		    output_data(" ?0x%x?", pointer[i]);
 		}
 		break;
 	    default:
-		sprintf(nfrontp, "%d (unknown)", pointer[1]);
-		nfrontp += strlen(nfrontp);
+		output_data("%d (unknown)", pointer[1]);
 		for (i = 2; i < length; i++) {
-		    sprintf(nfrontp, " %d", pointer[i]);
-		    nfrontp += strlen(nfrontp);
+		    output_data(" %d", pointer[i]);
 		}
 	    }
 	    break;
@@ -822,24 +770,20 @@
 	    register char *cp;
 	    register int j, k;
 
-	    sprintf(nfrontp, "STATUS");
-	    nfrontp += strlen(nfrontp);
+	    output_data("STATUS");
 
 	    switch (pointer[1]) {
 	    default:
 		if (pointer[1] == TELQUAL_SEND)
-		    sprintf(nfrontp, " SEND");
+		    output_data(" SEND");
 		else
-		    sprintf(nfrontp, " %d (unknown)", pointer[1]);
-		nfrontp += strlen(nfrontp);
+		    output_data(" %d (unknown)", pointer[1]);
 		for (i = 2; i < length; i++) {
-		    sprintf(nfrontp, " ?%d?", pointer[i]);
-		    nfrontp += strlen(nfrontp);
+		    output_data(" ?%d?", pointer[i]);
 		}
 		break;
 	    case TELQUAL_IS:
-		sprintf(nfrontp, " IS\r\n");
-		nfrontp += strlen(nfrontp);
+		output_data(" IS\r\n");
 
 		for (i = 2; i < length; i++) {
 		    switch(pointer[i]) {
@@ -850,18 +794,15 @@
 		    common2:
 			i++;
 			if (TELOPT_OK(pointer[i]))
-			    sprintf(nfrontp, " %s %s", cp, TELOPT(pointer[i]));
+			    output_data(" %s %s", cp, TELOPT(pointer[i]));
 			else
-			    sprintf(nfrontp, " %s %d", cp, pointer[i]);
-			nfrontp += strlen(nfrontp);
+			    output_data(" %s %d", cp, pointer[i]);
 
-			sprintf(nfrontp, "\r\n");
-			nfrontp += strlen(nfrontp);
+			output_data("\r\n");
 			break;
 
 		    case SB:
-			sprintf(nfrontp, " SB ");
-			nfrontp += strlen(nfrontp);
+			output_data(" SB ");
 			i++;
 			j = k = i;
 			while (j < length) {
@@ -877,20 +818,17 @@
 			}
 			printsub(0, &pointer[i], k - i);
 			if (i < length) {
-			    sprintf(nfrontp, " SE");
-			    nfrontp += strlen(nfrontp);
+			    output_data(" SE");
 			    i = j;
 			} else
 			    i = j - 1;
 
-			sprintf(nfrontp, "\r\n");
-			nfrontp += strlen(nfrontp);
+			output_data("\r\n");
 
 			break;
 				
 		    default:
-			sprintf(nfrontp, " %d", pointer[i]);
-			nfrontp += strlen(nfrontp);
+			output_data(" %d", pointer[i]);
 			break;
 		    }
 		}
@@ -900,86 +838,77 @@
 	  }
 
 	case TELOPT_XDISPLOC:
-	    sprintf(nfrontp, "X-DISPLAY-LOCATION ");
-	    nfrontp += strlen(nfrontp);
+	    output_data("X-DISPLAY-LOCATION ");
 	    switch (pointer[1]) {
 	    case TELQUAL_IS:
-		sprintf(nfrontp, "IS \"%.*s\"", length-2, (char *)pointer+2);
+		output_data("IS \"%.*s\"", length-2, (char *)pointer+2);
 		break;
 	    case TELQUAL_SEND:
-		sprintf(nfrontp, "SEND");
+		output_data("SEND");
 		break;
 	    default:
-		sprintf(nfrontp, "- unknown qualifier %d (0x%x).",
+		output_data("- unknown qualifier %d (0x%x).",
 				pointer[1], pointer[1]);
 	    }
-	    nfrontp += strlen(nfrontp);
 	    break;
 
 	case TELOPT_NEW_ENVIRON:
-	    sprintf(nfrontp, "NEW-ENVIRON ");
+	    output_data("NEW-ENVIRON ");
 	    goto env_common1;
 	case TELOPT_OLD_ENVIRON:
-	    sprintf(nfrontp, "OLD-ENVIRON");
+	    output_data("OLD-ENVIRON");
 	env_common1:
-	    nfrontp += strlen(nfrontp);
 	    switch (pointer[1]) {
 	    case TELQUAL_IS:
-		sprintf(nfrontp, "IS ");
+		output_data("IS ");
 		goto env_common;
 	    case TELQUAL_SEND:
-		sprintf(nfrontp, "SEND ");
+		output_data("SEND ");
 		goto env_common;
 	    case TELQUAL_INFO:
-		sprintf(nfrontp, "INFO ");
+		output_data("INFO ");
 	    env_common:
-		nfrontp += strlen(nfrontp);
 		{
 		    register int noquote = 2;
 		    for (i = 2; i < length; i++ ) {
 			switch (pointer[i]) {
 			case NEW_ENV_VAR:
-			    sprintf(nfrontp, "\" VAR " + noquote);
-			    nfrontp += strlen(nfrontp);
+			    output_data("\" VAR " + noquote);
 			    noquote = 2;
 			    break;
 
 			case NEW_ENV_VALUE:
-			    sprintf(nfrontp, "\" VALUE " + noquote);
-			    nfrontp += strlen(nfrontp);
+			    output_data("\" VALUE " + noquote);
 			    noquote = 2;
 			    break;
 
 			case ENV_ESC:
-			    sprintf(nfrontp, "\" ESC " + noquote);
-			    nfrontp += strlen(nfrontp);
+			    output_data("\" ESC " + noquote);
 			    noquote = 2;
 			    break;
 
 			case ENV_USERVAR:
-			    sprintf(nfrontp, "\" USERVAR " + noquote);
-			    nfrontp += strlen(nfrontp);
+			    output_data("\" USERVAR " + noquote);
 			    noquote = 2;
 			    break;
 
 			default:
 			    if (isprint(pointer[i]) && pointer[i] != '"') {
 				if (noquote) {
-				    *nfrontp++ = '"';
+				    output_data("\"");
 				    noquote = 0;
 				}
-				*nfrontp++ = pointer[i];
+				output_data("%c", pointer[i]);
 			    } else {
-				sprintf(nfrontp, "\" %03o " + noquote,
+				output_data("\" %03o " + noquote,
 							pointer[i]);
-				nfrontp += strlen(nfrontp);
 				noquote = 2;
 			    }
 			    break;
 			}
 		    }
 		    if (!noquote)
-			*nfrontp++ = '"';
+			output_data("\"");
 		    break;
 		}
 	    }
@@ -987,90 +916,69 @@
 
 #if	defined(AUTHENTICATION)
 	case TELOPT_AUTHENTICATION:
-	    sprintf(nfrontp, "AUTHENTICATION");
-	    nfrontp += strlen(nfrontp);
+	    output_data("AUTHENTICATION");
 	
 	    if (length < 2) {
-		sprintf(nfrontp, " (empty suboption??\?)");
-		nfrontp += strlen(nfrontp);
+		output_data(" (empty suboption??\?)");
 		break;
 	    }
 	    switch (pointer[1]) {
 	    case TELQUAL_REPLY:
 	    case TELQUAL_IS:
-		sprintf(nfrontp, " %s ", (pointer[1] == TELQUAL_IS) ?
+		output_data(" %s ", (pointer[1] == TELQUAL_IS) ?
 							"IS" : "REPLY");
-		nfrontp += strlen(nfrontp);
 		if (AUTHTYPE_NAME_OK(pointer[2]))
-		    sprintf(nfrontp, "%s ", AUTHTYPE_NAME(pointer[2]));
+		    output_data("%s ", AUTHTYPE_NAME(pointer[2]));
 		else
-		    sprintf(nfrontp, "%d ", pointer[2]);
-		nfrontp += strlen(nfrontp);
+		    output_data("%d ", pointer[2]);
 		if (length < 3) {
-		    sprintf(nfrontp, "(partial suboption??\?)");
-		    nfrontp += strlen(nfrontp);
+		    output_data("(partial suboption??\?)");
 		    break;
 		}
-		sprintf(nfrontp, "%s|%s%s",
+		output_data("%s|%s",
 			((pointer[3] & AUTH_WHO_MASK) == AUTH_WHO_CLIENT) ?
 			"CLIENT" : "SERVER",
 			((pointer[3] & AUTH_HOW_MASK) == AUTH_HOW_MUTUAL) ?
 			"MUTUAL" : "ONE-WAY",
 			((pointer[3] & AUTH_ENCRYPT_MASK) == AUTH_ENCRYPT_ON) ?
 			"|ENCRYPT" : "");
-		nfrontp += strlen(nfrontp);
 
 		auth_printsub(&pointer[1], length - 1, buf, sizeof(buf));
-		sprintf(nfrontp, "%s", buf);
-		nfrontp += strlen(nfrontp);
+		output_data("%s", buf);
 		break;
 
 	    case TELQUAL_SEND:
 		i = 2;
-		sprintf(nfrontp, " SEND ");
-		nfrontp += strlen(nfrontp);
+		output_data(" SEND ");
 		while (i < length) {
 		    if (AUTHTYPE_NAME_OK(pointer[i]))
-			sprintf(nfrontp, "%s ", AUTHTYPE_NAME(pointer[i]));
+			output_data("%s ", AUTHTYPE_NAME(pointer[i]));
 		    else
-			sprintf(nfrontp, "%d ", pointer[i]);
-		    nfrontp += strlen(nfrontp);
+			output_data("%d ", pointer[i]);
 		    if (++i >= length) {
-			sprintf(nfrontp, "(partial suboption??\?)");
-			nfrontp += strlen(nfrontp);
+			output_data("(partial suboption??\?)");
 			break;
 		    }
-		    sprintf(nfrontp, "%s|%s%s ",
+		    output_data( "%s|%s%s ",
 			((pointer[i] & AUTH_WHO_MASK) == AUTH_WHO_CLIENT) ?
 							"CLIENT" : "SERVER",
 			((pointer[i] & AUTH_HOW_MASK) == AUTH_HOW_MUTUAL) ?
 							"MUTUAL" : "ONE-WAY",
 			((pointer[3] & AUTH_ENCRYPT_MASK) == AUTH_ENCRYPT_ON) ?
 			"|ENCRYPT" : "");
-		    nfrontp += strlen(nfrontp);
 		    ++i;
 		}
 		break;
 
 	    case TELQUAL_NAME:
-		i = 2;
-		sprintf(nfrontp, " NAME \"");
-		nfrontp += strlen(nfrontp);
-		while (i < length) {
-		    if (isprint(pointer[i]))
-			*nfrontp++ = pointer[i++];
-		    else {
-			sprintf(nfrontp, "\"%03o",pointer[i++]);
-		    	nfrontp += strlen(nfrontp);
-		    }
-		}
-		*nfrontp++ = '"';
+		output_data(" NAME \"%.*s\"",
+		    length - 2,
+		    pointer + 2);
 		break;
 
 	    default:
 		    for (i = 2; i < length; i++) {
-			sprintf(nfrontp, " ?%d?", pointer[i]);
-			nfrontp += strlen(nfrontp);
+			output_data(" ?%d?", pointer[i]);
 		    }
 		    break;
 	    }
@@ -1079,86 +987,70 @@
 
 #ifdef	ENCRYPTION
 	case TELOPT_ENCRYPT:
-	    sprintf(nfrontp, "ENCRYPT");
-	    nfrontp += strlen(nfrontp);
+	    output_data("ENCRYPT");
 	    if (length < 2) {
-		sprintf(nfrontp, " (empty suboption??\?)");
-		nfrontp += strlen(nfrontp);
+		output_data(" (empty suboption??\?)");
 		break;
 	    }
 	    switch (pointer[1]) {
 	    case ENCRYPT_START:
-		sprintf(nfrontp, " START");
-		nfrontp += strlen(nfrontp);
+		output_data(" START");
 		break;
 
 	    case ENCRYPT_END:
-		sprintf(nfrontp, " END");
-		nfrontp += strlen(nfrontp);
+		output_data(" END");
 		break;
 
 	    case ENCRYPT_REQSTART:
-		sprintf(nfrontp, " REQUEST-START");
-		nfrontp += strlen(nfrontp);
+		output_data(" REQUEST-START");
 		break;
 
 	    case ENCRYPT_REQEND:
-		sprintf(nfrontp, " REQUEST-END");
-		nfrontp += strlen(nfrontp);
+		output_data(" REQUEST-END");
 		break;
 
 	    case ENCRYPT_IS:
 	    case ENCRYPT_REPLY:
-		sprintf(nfrontp, " %s ", (pointer[1] == ENCRYPT_IS) ?
+		output_data(" %s ", (pointer[1] == ENCRYPT_IS) ?
 							"IS" : "REPLY");
-		nfrontp += strlen(nfrontp);
 		if (length < 3) {
-		    sprintf(nfrontp, " (partial suboption??\?)");
-		    nfrontp += strlen(nfrontp);
+		    output_data(" (partial suboption??\?)");
 		    break;
 		}
 		if (ENCTYPE_NAME_OK(pointer[2]))
-		    sprintf(nfrontp, "%s ", ENCTYPE_NAME(pointer[2]));
+		    output_data("%s ", ENCTYPE_NAME(pointer[2]));
 		else
-		    sprintf(nfrontp, " %d (unknown)", pointer[2]);
-		nfrontp += strlen(nfrontp);
+		    output_data(" %d (unknown)", pointer[2]);
 
 		encrypt_printsub(&pointer[1], length - 1, buf, sizeof(buf));
-		sprintf(nfrontp, "%s", buf);
-		nfrontp += strlen(nfrontp);
+		output_data("%s", buf);
 		break;
 
 	    case ENCRYPT_SUPPORT:
 		i = 2;
-		sprintf(nfrontp, " SUPPORT ");
-		nfrontp += strlen(nfrontp);
+		output_data(" SUPPORT ");
 		while (i < length) {
 		    if (ENCTYPE_NAME_OK(pointer[i]))
-			sprintf(nfrontp, "%s ", ENCTYPE_NAME(pointer[i]));
+			output_data("%s ", ENCTYPE_NAME(pointer[i]));
 		    else
-			sprintf(nfrontp, "%d ", pointer[i]);
-		    nfrontp += strlen(nfrontp);
+			output_data("%d ", pointer[i]);
 		    i++;
 		}
 		break;
 
 	    case ENCRYPT_ENC_KEYID:
-		sprintf(nfrontp, " ENC_KEYID", pointer[1]);
-		nfrontp += strlen(nfrontp);
+		output_data(" ENC_KEYID");
 		goto encommon;
 
 	    case ENCRYPT_DEC_KEYID:
-		sprintf(nfrontp, " DEC_KEYID", pointer[1]);
-		nfrontp += strlen(nfrontp);
+		output_data(" DEC_KEYID");
 		goto encommon;
 
 	    default:
-		sprintf(nfrontp, " %d (unknown)", pointer[1]);
-		nfrontp += strlen(nfrontp);
+		output_data(" %d (unknown)", pointer[1]);
 	    encommon:
 		for (i = 2; i < length; i++) {
-		    sprintf(nfrontp, " %d", pointer[i]);
-		    nfrontp += strlen(nfrontp);
+		    output_data(" %d", pointer[i]);
 		}
 		break;
 	    }
@@ -1167,18 +1059,15 @@
 
 	default:
 	    if (TELOPT_OK(pointer[0]))
-	        sprintf(nfrontp, "%s (unknown)", TELOPT(pointer[0]));
+	        output_data( "%s (unknown)", TELOPT(pointer[0]));
 	    else
-	        sprintf(nfrontp, "%d (unknown)", pointer[i]);
-	    nfrontp += strlen(nfrontp);
+	        output_data( "%d (unknown)", pointer[i]);
 	    for (i = 1; i < length; i++) {
-		sprintf(nfrontp, " %d", pointer[i]);
-		nfrontp += strlen(nfrontp);
+		output_data( " %d", pointer[i]);
 	    }
 	    break;
 	}
-	sprintf(nfrontp, "\r\n");
-	nfrontp += strlen(nfrontp);
+	output_data( "\r\n");
 }
 
 /*
@@ -1200,26 +1089,22 @@
 		}
 
 		/* add a line of output */
-		sprintf(nfrontp, "%s: ", tag);
-		nfrontp += strlen(nfrontp);
+		output_data("%s: ", tag);
 		for (i = 0; i < 20 && cnt; i++) {
-			sprintf(nfrontp, "%02x", *ptr);
-			nfrontp += strlen(nfrontp); 
+			output_data("%02x", *ptr);
 			if (isprint(*ptr)) {
 				xbuf[i] = *ptr;
 			} else {
 				xbuf[i] = '.';
 			}
 			if (i % 2) { 
-				*nfrontp = ' ';
-				nfrontp++;
+				output_data(" ");
 			}
 			cnt--;
 			ptr++;
 		}
 		xbuf[i] = '\0';
-		sprintf(nfrontp, " %s\r\n", xbuf );
-		nfrontp += strlen(nfrontp);
+		output_data(" %s\r\n", xbuf );
 	} 
 }
 #endif /* DIAGNOSTICS */
