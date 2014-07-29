
$FreeBSD$

--- modules/tm/t_msgbuilder.c	2004/06/29 19:22:35	1.1
+++ modules/tm/t_msgbuilder.c	2004/06/29 19:56:19
@@ -124,7 +124,7 @@
 
 	/* User Agent */
 	if (server_signature) {
-		*len += USER_AGENT_LEN + CRLF_LEN;
+		*len += USER_AGENT_LEN + CRLF_LEN + (server_name ? strlen(server_name) : UA_NAME_LEN);
 	}
 	/* Content Length, EoM */
 	*len+=CONTENT_LENGTH_LEN+1 + CRLF_LEN + CRLF_LEN;
@@ -164,7 +164,13 @@
 
 	/* User Agent header */
 	if (server_signature) {
-		append_mem_block(p,USER_AGENT CRLF, USER_AGENT_LEN+CRLF_LEN );
+		append_mem_block(p, USER_AGENT, USER_AGENT_LEN);
+		if (server_name) {
+			append_mem_block(p, server_name, strlen(server_name));
+		} else {
+			append_mem_block(p, UA_NAME, UA_NAME_LEN);
+		}
+		append_mem_block(p, CRLF, CRLF_LEN);
 	}
 	/* Content Length, EoM */
 	append_mem_block(p, CONTENT_LENGTH "0" CRLF CRLF ,
@@ -397,7 +403,7 @@
 	*len += CSEQ_LEN + cseq.len + 1 + method->len + CRLF_LEN;                                    /* CSeq */
 	*len += calculate_routeset_length(dialog);                                                   /* Route set */
 	*len += (body ? (CONTENT_LENGTH_LEN + content_length.len + CRLF_LEN) : 0);                   /* Content-Length */
-	*len += (server_signature ? (USER_AGENT_LEN + CRLF_LEN) : 0);                                /* Signature */
+	*len += (server_signature ? (USER_AGENT_LEN + CRLF_LEN + (server_name ? strlen(server_name) : UA_NAME_LEN)) : 0);/* Signature */
 	*len += (headers ? headers->len : 0);                                                        /* Additional headers */
 	*len += (body ? body->len : 0);                                                              /* Message body */
 	*len += CRLF_LEN;                                                                            /* End of Header */
@@ -426,7 +432,15 @@
 	}
 	
 	     /* Server signature */
-	if (server_signature) memapp(w, USER_AGENT CRLF, USER_AGENT_LEN + CRLF_LEN);
+	if (server_signature) {
+		memapp(w, USER_AGENT, USER_AGENT_LEN);
+		if (server_name) {
+			memapp(w, server_name, strlen(server_name));
+		} else {
+			memapp(w, UA_NAME, UA_NAME_LEN);
+		}
+		memapp(w, CRLF, CRLF_LEN);
+	}
 	if (headers) memapp(w, headers->s, headers->len);
 	memapp(w, CRLF, CRLF_LEN);
      	if (body) memapp(w, body->s, body->len);
