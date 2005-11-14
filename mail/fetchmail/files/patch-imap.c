Index: imap.c
===================================================================
--- imap.c	(revision 4423)
+++ imap.c	(working copy)
@@ -57,72 +57,85 @@
 		*cp = toupper(*cp);
 
 	/* interpret untagged status responses */
-	if (strstr(buf, "* CAPABILITY"))
-	{
-	    strncpy(capabilities, buf + 12, sizeof(capabilities));
-	    capabilities[sizeof(capabilities)-1] = '\0';
-	}
-	else if (strstr(buf, "EXISTS"))
-	{
-	    count = atoi(buf+2);
-	    /*
-	     * Don't trust the message count passed by the server.
-	     * Without this check, it might be possible to do a
-	     * DNS-spoofing attack that would pass back a ridiculous 
-	     * count, and allocate a malloc area that would overlap
-	     * a portion of the stack.
-	     */
-	    if (count > INT_MAX/sizeof(int))
+	if (buf[0] == '*' && buf[1] == ' ') {
+	    if (strstr(buf, " CAPABILITY"))
 	    {
-		report(stderr, "bogus message count!");
-		return(PS_PROTOCOL);
+		strncpy(capabilities, buf + 12, sizeof(capabilities));
+		capabilities[sizeof(capabilities)-1] = '\0';
 	    }
-
-	    /*
-	     * Nasty kluge to handle RFC2177 IDLE.  If we know we're idling
-	     * we can't wait for the tag matching the IDLE; we have to tell the
-	     * server the IDLE is finished by shipping back a DONE when we
-	     * see an EXISTS.  Only after that will a tagged response be
-	     * shipped.  The idling flag also gets cleared on a timeout.
-	     */
-	    if (stage == STAGE_IDLE)
+	    else if (strstr(buf, " EXISTS"))
 	    {
-		/* If IDLE isn't supported, we were only sending NOOPs anyway. */
-		if (has_idle)
+		count = atoi(buf+2);
+		/*
+		 * Don't trust the message count passed by the server.
+		 * Without this check, it might be possible to do a
+		 * DNS-spoofing attack that would pass back a ridiculous 
+		 * count, and allocate a malloc area that would overlap
+		 * a portion of the stack.
+		 */
+		if (count > INT_MAX/sizeof(int))
 		{
-		    /* we do our own write and report here to disable tagging */
-		    SockWrite(sock, "DONE\r\n", 6);
-		    if (outlevel >= O_MONITOR)
-		        report(stdout, "IMAP> DONE\n");
+		    report(stderr, "bogus message count!");
+		    return(PS_PROTOCOL);
 		}
 
-		mytimeout = saved_timeout;
-		stage = STAGE_FETCH;
+		/*
+		 * Nasty kluge to handle RFC2177 IDLE.  If we know we're idling
+		 * we can't wait for the tag matching the IDLE; we have to tell the
+		 * server the IDLE is finished by shipping back a DONE when we
+		 * see an EXISTS.  Only after that will a tagged response be
+		 * shipped.  The idling flag also gets cleared on a timeout.
+		 */
+		if (stage == STAGE_IDLE)
+		{
+		    /* If IDLE isn't supported, we were only sending NOOPs anyway. */
+		    if (has_idle)
+		    {
+			/* we do our own write and report here to disable tagging */
+			SockWrite(sock, "DONE\r\n", 6);
+			if (outlevel >= O_MONITOR)
+			    report(stdout, "IMAP> DONE\n");
+		    }
+
+		    mytimeout = saved_timeout;
+		    stage = STAGE_FETCH;
+		}
 	    }
+	    /* a space is required to avoid confusion with the \Recent flag */
+	    else if (strstr(buf, " RECENT"))
+	    {
+		recentcount = atoi(buf+2);
+	    }
+	    /* servers are not required to update the EXISTS counts,
+	     * so count down by ourselves */
+	    else if (strstr(buf, " EXPUNGE"))
+	    {
+		if (atoi(buf+2) > 0) {
+		    if (count > 0)
+			count --;
+		}
+	    }
+	    else if (strstr(buf, " PREAUTH")) {
+		preauth = TRUE;
+	    }
+	    /*
+	     * The server may decide to make the mailbox read-only, 
+	     * which causes fetchmail to go into a endless loop
+	     * fetching the same message over and over again. 
+	     * 
+	     * However, for check_only, we use EXAMINE which will
+	     * mark the mailbox read-only as per the RFC.
+	     * 
+	     * This checks for the condition and aborts if 
+	     * the mailbox is read-only. 
+	     *
+	     * See RFC 2060 section 6.3.1 (SELECT).
+	     * See RFC 2060 section 6.3.2 (EXAMINE).
+	     */ 
+	    else if (!check_only && strstr(buf, "[READ-ONLY]")) {
+		return(PS_LOCKBUSY);
+	    }
 	}
-	/* a space is required to avoid confusion with the \Recent flag */
-	else if (strstr(buf, " RECENT"))
-	{
-	    recentcount = atoi(buf+2);
-	}
-	else if (strstr(buf, "PREAUTH"))
-	    preauth = TRUE;
-	/*
-	 * The server may decide to make the mailbox read-only, 
-	 * which causes fetchmail to go into a endless loop
-	 * fetching the same message over and over again. 
-	 * 
-	 * However, for check_only, we use EXAMINE which will
-	 * mark the mailbox read-only as per the RFC.
-	 * 
-	 * This checks for the condition and aborts if 
-	 * the mailbox is read-only. 
-	 *
-	 * See RFC 2060 section 6.3.1 (SELECT).
-	 * See RFC 2060 section 6.3.2 (EXAMINE).
-	 */ 
-	else if (!check_only && strstr(buf, "[READ-ONLY]"))
-	    return(PS_LOCKBUSY);
     } while
 	(tag[0] != '\0' && strncmp(buf, tag, strlen(tag)));
 
