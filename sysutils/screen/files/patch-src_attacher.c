diff --git attacher.c attacher.c
index f2b60f0..9138176 100644
--- attacher.c
+++ attacher.c
@@ -431,53 +431,62 @@ void SendCmdMessage(char *sty, char *match, char **av, int query)
 			sty[FILENAME_MAX] = 0;
 		if (strlen(sty) > 2 * MAXSTR - 1)
 			sty[2 * MAXSTR - 1] = 0;
-		sprintf(SocketPath + strlen(SocketPath), "/%s", sty);
+
+		snprintf(SocketPath + strlen(SocketPath),
+			sizeof(SocketPath) - strlen(SocketPath), "/%s", sty);
+
 		if ((s = MakeClientSocket(1)) == -1)
 			exit(1);
 	}
-	memset((char *)&m, 0, sizeof(Message));
+
+	memset(&m, 0, sizeof(Message));
 	m.type = query ? MSG_QUERY : MSG_COMMAND;
+
 	if (attach_tty) {
-		strncpy(m.m_tty, attach_tty_is_in_new_ns ? attach_tty_name_in_ns : attach_tty, ARRAY_SIZE(m.m_tty) - 1);
-		m.m_tty[ARRAY_SIZE(m.m_tty) - 1] = 0;
+		snprintf(m.m_tty, sizeof(m.m_tty), "%s",
+			attach_tty_is_in_new_ns ? attach_tty_name_in_ns : attach_tty);
 	}
+
 	p = m.m.command.cmd;
 	n = 0;
-	size_t space_left = ARRAY_SIZE(m.m.command.cmd);
+	size_t space_left = sizeof(m.m.command.cmd);
 
 	for (; *av && n < MAXARGS - 1; ++av, ++n) {
-               int printed = snprintf(p, space_left, "%s", *av);
-               if (printed < 0 || (size_t)printed >= space_left)
-                       Panic(0, "Total length of the command to send too large.\n");
+		int printed = snprintf(p, space_left, "%s", *av);
+		if (printed < 0 || (size_t)printed >= space_left)
+			Panic(0, "Total length of the command to send too large.\n");
 
-               printed += 1; // add null terminator
-               p += printed;
-               space_left -= printed;
+		/* move past string and null terminator */
+		p += printed + 1;
+		space_left -= printed + 1;
 	}
-	*p = 0;
+
+	*p = '\0';
 	m.m.command.nargs = n;
-	strncpy(m.m.attach.auser, LoginName, ARRAY_SIZE(m.m.attach.auser) - 1);
-	m.m.command.auser[ARRAY_SIZE(m.m.command.auser) - 1] = 0;
+
+	snprintf(m.m.command.auser, sizeof(m.m.command.auser), "%s", LoginName);
 	m.protocol_revision = MSG_REVISION;
-	strncpy(m.m.command.preselect, preselect ? preselect : "", ARRAY_SIZE(m.m.command.preselect) - 1);
-	m.m.command.preselect[ARRAY_SIZE(m.m.command.preselect) - 1] = 0;
+	snprintf(m.m.command.preselect, sizeof(m.m.command.preselect), "%s",
+		preselect ? preselect : "");
 	m.m.command.apid = getpid();
+
 	if (query) {
 		/* Create a server socket so we can get back the result */
 		char *sp = SocketPath + strlen(SocketPath);
-		char query[] = "-queryX";
 		char c;
 		int r = -1;
+
 		for (c = 'A'; c <= 'Z'; c++) {
-			query[6] = c;
-			strncpy(sp, query, strlen(SocketPath));
+			snprintf(sp, sizeof(SocketPath) - strlen(SocketPath),
+				"-query%c", c);
 			if ((r = MakeServerSocket()) >= 0)
 				break;
 		}
+
 		if (r < 0) {
 			for (c = '0'; c <= '9'; c++) {
-				query[6] = c;
-				strncpy(sp, query, strlen(SocketPath));
+				snprintf(sp, sizeof(SocketPath) - strlen(SocketPath),
+					"-query%c", c);
 				if ((r = MakeServerSocket()) >= 0)
 					break;
 			}
@@ -486,8 +495,8 @@ void SendCmdMessage(char *sty, char *match, char **av, int query)
 		if (r < 0)
 			Panic(0, "Could not create a listening socket to read the results.");
 
-		strncpy(m.m.command.writeback, SocketPath, ARRAY_SIZE(m.m.command.writeback) - 1);
-		m.m.command.writeback[ARRAY_SIZE(m.m.command.writeback) - 1] = '\0';
+		snprintf(m.m.command.writeback, sizeof(m.m.command.writeback),
+			"%s", SocketPath);
 
 		/* Send the message, then wait for a response */
 		xsignal(SIGCONT, QueryResultSuccess);
@@ -504,7 +513,7 @@ void SendCmdMessage(char *sty, char *match, char **av, int query)
 		ReceiveRaw(r);
 		close(r);
 		unlink(SocketPath);
-		if (QueryResult == 2)	/* An error happened */
+		if (QueryResult == 2)   /* An error happened */
 			exit(1);
 	} else {
 		if (WriteMessage(s, &m))
