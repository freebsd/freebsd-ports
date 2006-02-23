--- proto.c.bak	22 Feb 2006 23:22:04 -0000	1.75
+++ proto.c	23 Feb 2006 01:20:53 -0000	1.76
@@ -196,15 +196,15 @@ proto_greet(struct config *config)
 		if (msg == NULL)
 			goto bad;
 		lprintf(-1, "Rejected by server: %s\n", msg);
-		return (-1);
+		return (STATUS_TRANSIENTFAILURE);
 	} else
 		goto bad;
 	lprintf(2, "Server software version: %s\n",
 	    swver != NULL ? swver : ".");
-	return (0);
+	return (STATUS_SUCCESS);
 bad:
 	lprintf(-1, "Invalid greeting from server\n");
-	return (-1);
+	return (STATUS_FAILURE);
 }
 
 /* Negotiate protocol version with the server. */
@@ -236,12 +236,12 @@ proto_negproto(struct config *config)
 	if (maj != PROTO_MAJ || min != PROTO_MIN) {
 		lprintf(-1, "Server protocol version %d.%d not supported "
 		    "by client\n", maj, min);
-		return (1);
+		return (STATUS_FAILURE);
 	}
-	return (0);
+	return (STATUS_SUCCESS);
 bad:
 	lprintf(-1, "Invalid PROTO command from server\n");
-	return (1);
+	return (STATUS_FAILURE);
 }
 
 static int
@@ -265,24 +265,24 @@ proto_login(struct config *config)
 	if (strcmp(realm, ".") != 0 || strcmp(challenge, ".") != 0) {
 		lprintf(-1, "Authentication required by the server and not "
 		    "supported by client\n");
-		return (1);
+		return (STATUS_FAILURE);
 	}
 	proto_printf(s, "AUTHMD5 . . .\n");
 	stream_flush(s);
 	line = stream_getln(s, NULL);
 	cmd = proto_get_ascii(&line);
 	if (strcmp(cmd, "OK") == 0)
-		return (0);
+		return (STATUS_SUCCESS);
 	if (strcmp(cmd, "!") == 0) {
 		msg = proto_get_rest(&line);
 		if (msg == NULL)
 			goto bad;
 		lprintf(-1, "Server error: %s\n", msg);
-		return (1);
+		return (STATUS_FAILURE);
 	}
 bad:
 	lprintf(-1, "Invalid server reply to AUTHMD5\n");
-	return (1);
+	return (STATUS_FAILURE);
 }
 
 /*
@@ -327,10 +327,10 @@ proto_fileattr(struct config *config)
 	if (line == NULL || strcmp(line, ".") != 0)
 		goto bad;
 	memcpy(config->fasupport, support, sizeof(config->fasupport));
-	return (0);
+	return (STATUS_SUCCESS);
 bad:
 	lprintf(-1, "Protocol error negotiating attribute support\n");
-	return (1);
+	return (STATUS_FAILURE);
 }
 
 /*
@@ -422,10 +422,10 @@ proto_xchgcoll(struct config *config)
 		if (line == NULL)
 			goto bad;
 	}
-	return (0);
+	return (STATUS_SUCCESS);
 bad:
 	lprintf(-1, "Protocol error during collection exchange\n");
-	return (1);
+	return (STATUS_FAILURE);
 }
 
 static struct mux *
@@ -482,7 +482,7 @@ proto_run(struct config *config)
 	struct killer killer;
 	struct threads *workers;
 	struct mux *m;
-	int error, i, status;
+	int i, status;
 
 	/*
 	 * We pass NULL for the close() function because we'll reuse
@@ -490,17 +490,17 @@ proto_run(struct config *config)
 	 */
 	config->server = stream_open_fd(config->socket, stream_read_fd,
 	    stream_write_fd, NULL);
-	error = proto_greet(config);
-	if (!error)
-		error = proto_negproto(config);
-	if (!error)
-		error = proto_login(config);
-	if (!error)
-		error = proto_fileattr(config);
-	if (!error)
-		error = proto_xchgcoll(config);
-	if (error)
-		return (STATUS_FAILURE);
+	status = proto_greet(config);
+	if (status == STATUS_SUCCESS)
+		status = proto_negproto(config);
+	if (status == STATUS_SUCCESS)
+		status = proto_login(config);
+	if (status == STATUS_SUCCESS)
+		status = proto_fileattr(config);
+	if (status == STATUS_SUCCESS)
+		status = proto_xchgcoll(config);
+	if (status != STATUS_SUCCESS)
+		return (status);
 
 	/* Multi-threaded action starts here. */
 	m = proto_mux(config);
