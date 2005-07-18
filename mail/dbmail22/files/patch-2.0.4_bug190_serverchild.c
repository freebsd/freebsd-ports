Index: serverchild.c
===================================================================
--- serverchild.c	(revision 1600)
+++ serverchild.c	(revision 1758)
@@ -66,13 +66,13 @@
 void client_close(void)
 {
 	if (client.tx) {
-		trace(TRACE_DEBUG,"%s,%s: closing write stream", __FILE__,__FUNCTION__);
+		trace(TRACE_DEBUG,"%s,%s: closing write stream", __FILE__,__func__);
 		fflush(client.tx);
 		fclose(client.tx);	/* closes clientSocket as well */
 		client.tx = NULL;
 	}
 	if (client.rx) {
-		trace(TRACE_DEBUG,"%s,%s: closing read stream", __FILE__,__FUNCTION__);
+		trace(TRACE_DEBUG,"%s,%s: closing read stream", __FILE__,__func__);
 		shutdown(fileno(client.rx), SHUT_RDWR);
 		fclose(client.rx);
 		client.rx = NULL;
@@ -86,7 +86,7 @@
 	
 	trace(TRACE_DEBUG,
 		"%s,%s: database connection still open, closing",
-		__FILE__,__FUNCTION__);
+		__FILE__,__func__);
 	db_disconnect();
 	auth_disconnect();
 	connected = 0;		/* FIXME a signal between this line and the previous one 
@@ -99,18 +99,22 @@
 
 void noop_child_sig_handler(int sig, siginfo_t *info UNUSED, void *data UNUSED)
 {
-       trace(TRACE_DEBUG, "%s,%s: ignoring signal [%d]", __FILE__, __FUNCTION__, sig);
+	int saved_errno = errno;
+	trace(TRACE_DEBUG, "%s,%s: ignoring signal [%d]", __FILE__, __func__, sig);
+	errno = saved_errno;
 }
 
 void active_child_sig_handler(int sig, siginfo_t * info UNUSED, void *data UNUSED)
 {
+	int saved_errno = errno;
+	
 	static int triedDisconnect = 0;
 
 #ifdef _USE_STR_SIGNAL
-	trace(TRACE_ERROR, "%s,%s: got signal [%s]", __FILE__, __FUNCTION__,
+	trace(TRACE_ERROR, "%s,%s: got signal [%s]", __FILE__, __func__,
 	      strsignal(sig));
 #else
-	trace(TRACE_ERROR, "%s,%s: got signal [%d]", __FILE__, __FUNCTION__, sig);
+	trace(TRACE_ERROR, "%s,%s: got signal [%d]", __FILE__, __func__, sig);
 #endif
 
 	/* perform reinit at SIGHUP otherwise exit, but do nothing on
@@ -118,10 +122,10 @@
 	switch (sig) {
 	case SIGCHLD:
 		trace(TRACE_DEBUG, "%s,%s: SIGCHLD received... ignoring",
-			__FILE__, __FUNCTION__);
+			__FILE__, __func__);
 		break;
 	case SIGALRM:
-		trace(TRACE_DEBUG, "%s,%s: timeout received", __FILE__, __FUNCTION__);
+		trace(TRACE_DEBUG, "%s,%s: timeout received", __FILE__, __func__);
 		client_close();
 		break;
 
@@ -132,23 +136,23 @@
 		if (ChildStopRequested) {
 			trace(TRACE_DEBUG,
 				"%s,%s: already caught a stop request. Closing right now",
-				__FILE__,__FUNCTION__);
+				__FILE__,__func__);
 
 			/* already caught this signal, exit the hard way now */
 			client_close();
 			disconnect_all();
 			child_unregister();
-			trace(TRACE_DEBUG, "%s,%s: exit",__FILE__,__FUNCTION__);
+			trace(TRACE_DEBUG, "%s,%s: exit",__FILE__,__func__);
 			exit(1);
 		}
-		trace(TRACE_DEBUG, "%s,%s: setting stop request",__FILE__,__FUNCTION__);
+		trace(TRACE_DEBUG, "%s,%s: setting stop request",__FILE__,__func__);
 		DelChildSigHandler();
 	 	ChildStopRequested = 1;
 		break;
 	default:
 		/* bad shtuff, exit */
 		trace(TRACE_DEBUG,
-		      "%s,%s: cannot ignore this. Terminating",__FILE__,__FUNCTION__);
+		      "%s,%s: cannot ignore this. Terminating",__FILE__,__func__);
 
 		/*
 		 * For some reason i have not yet determined the process starts eating up
@@ -164,10 +168,12 @@
 			disconnect_all();
 		}
 
-		trace(TRACE_DEBUG, "%s,%s: exit", __FILE__, __FUNCTION__);
+		trace(TRACE_DEBUG, "%s,%s: exit", __FILE__, __func__);
 		child_unregister();
 		exit(1);
 	}
+
+	errno = saved_errno;
 }
 
 
@@ -239,16 +245,19 @@
 	if (! pid) {
 		if (child_register() == -1) {
 			trace(TRACE_FATAL, "%s,%s: child_register failed", 
-				__FILE__, __FUNCTION__);
+				__FILE__, __func__);
 			exit(0);
 
 		}
 	
  		ChildStopRequested = 0;
  		SetChildSigHandler();
- 		trace(TRACE_INFO, "%s,%s: signal handler placed, going to perform task now",
-			__FILE__, __FUNCTION__);
- 		PerformChildTask(info);
+ 		
+		trace(TRACE_INFO, "%s,%s: signal handler placed, going to perform task now",
+			__FILE__, __func__);
+		
+ 		if (PerformChildTask(info)== -1)
+			return -1;
  		child_unregister();
  		exit(0);
 	} else {
@@ -269,22 +278,22 @@
 	struct hostent *clientHost;
 
 	if (!info) {
-		trace(TRACE_ERROR,
-		      "PerformChildTask(): NULL info supplied");
+		trace(TRACE_ERROR, "%s,%s: NULL info supplied",
+				__FILE__, __func__);
 		return -1;
 	}
 
 	if (db_connect() != 0) {
-		trace(TRACE_ERROR,
-		      "PerformChildTask(): could not connect to database");
+		trace(TRACE_ERROR, "%s,%s: could not connect to database", 
+				__FILE__, __func__);
 		return -1;
 	}
 	if (db_check_version() != 0) 
 		return -1;
 
 	if (auth_connect() != 0) {
-		trace(TRACE_ERROR,
-		      "PerformChildTask(): could not connect to authentication");
+		trace(TRACE_ERROR, "%s,%s: could not connect to authentication",
+				__FILE__, __func__);
 		return -1;
 	}
 
@@ -294,12 +303,13 @@
 	for (i = 0; i < info->maxConnect && !ChildStopRequested; i++) {
 
 		if (db_check_connection()) {
-			trace(TRACE_ERROR, "%s,%s: database has gone away", __FILE__, __func__);
+			trace(TRACE_ERROR, "%s,%s: database has gone away", 
+					__FILE__, __func__);
 			return -1;
 		}
 	
-		trace(TRACE_INFO,
-		      "PerformChildTask(): waiting for connection");
+		trace(TRACE_INFO, "%s,%s: waiting for connection",
+				__FILE__, __func__);
 
 		child_reg_disconnected();
 
@@ -312,8 +322,8 @@
 	
 		if (clientSocket == -1) {
 			i--;	/* don't count this as a connect */
-			trace(TRACE_INFO,
-			      "PerformChildTask(): accept failed");
+			trace(TRACE_INFO, "%s,%s: accept failed",
+					__FILE__, __func__);
 			continue;	/* accept failed, refuse connection & continue */
 		}
 
@@ -337,30 +347,29 @@
 				strncpy(client.clientname,
 					clientHost->h_name, FIELDSIZE);
 
-			trace(TRACE_MESSAGE,
-			      "PerformChildTask(): incoming connection from [%s (%s)]",
+			trace(TRACE_MESSAGE, "%s,%s: incoming connection from [%s (%s)]",
+					__FILE__, __func__,
 			      client.ip,
 			      client.clientname[0] ? client.
 			      clientname : "Lookup failed");
 		} else {
-			trace(TRACE_MESSAGE,
-			      "PerformChildTask(): incoming connection from [%s]",
-			      client.ip);
+			trace(TRACE_MESSAGE, "%s,%s: incoming connection from [%s]",
+					__FILE__, __func__, client.ip);
 		}
 
 		/* make streams */
 		if (!(client.rx = fdopen(dup(clientSocket), "r"))) {
 			/* read-FILE opening failure */
-			trace(TRACE_ERROR,
-			      "PerformChildTask(): error opening read file stream");
+			trace(TRACE_ERROR, "%s,%s: error opening read file stream",
+					__FILE__, __func__);
 			close(clientSocket);
 			continue;
 		}
 
 		if (!(client.tx = fdopen(clientSocket, "w"))) {
 			/* write-FILE opening failure */
-			trace(TRACE_ERROR,
-			      "PerformChildTask(): error opening write file stream");
+			trace(TRACE_ERROR, "%s,%s: error opening write file stream",
+					__FILE__, __func__);
 			fclose(client.rx);
 			close(clientSocket);
 			memset(&client, 0, sizeof(client));
@@ -370,8 +379,8 @@
 		setvbuf(client.tx, (char *) NULL, _IOLBF, 0);
 		setvbuf(client.rx, (char *) NULL, _IOLBF, 0);
 
-		trace(TRACE_DEBUG,
-		      "PerformChildTask(): client info init complete, calling client handler");
+		trace(TRACE_DEBUG, "%s,%s: client info init complete, calling client handler",
+				__FILE__, __func__);
 
 		/* streams are ready, perform handling */
 		info->ClientHandler(&client);
@@ -379,17 +388,19 @@
 		set_proc_title("%s", "Idle");
 #endif
 
-		trace(TRACE_DEBUG,
-		      "PerformChildTask(): client handling complete, closing streams");
+		trace(TRACE_DEBUG, "%s,%s: client handling complete, closing streams",
+				__FILE__, __func__);
 		client_close();
-		trace(TRACE_INFO, "PerformChildTask(): connection closed");
+		trace(TRACE_INFO, "%s,%s: connection closed",
+				__FILE__, __func__);
 	}
 
 	if (!ChildStopRequested)
-		trace(TRACE_ERROR,
-		      "PerformChildTask(): maximum number of connections reached, stopping now");
+		trace(TRACE_ERROR, "%s,%s: maximum number of connections reached, stopping now",
+				__FILE__, __func__);
 	else
-		trace(TRACE_ERROR, "PerformChildTask(): stop requested");
+		trace(TRACE_ERROR, "%s,%s: stop requested",
+				__FILE__, __func__);
 
 	child_reg_disconnected();
 	disconnect_all();
