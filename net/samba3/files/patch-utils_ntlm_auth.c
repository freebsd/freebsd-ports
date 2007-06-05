--- utils/ntlm_auth.c.orig	Sun Jun  3 04:28:29 2007
+++ utils/ntlm_auth.c	Sun Jun  3 04:47:26 2007
@@ -689,8 +689,8 @@
 	NTSTATUS nt_status;
 
 	if (strlen(buf) < 2) {
-		DEBUG(1, ("NTLMSSP query [%s] invalid", buf));
-		x_fprintf(x_stdout, "BH\n");
+		DEBUG(1, ("NTLMSSP query [%s] invalid\n", buf));
+		x_fprintf(x_stdout, "BH NTLMSSP query [%s] invalid\n", buf);
 		return;
 	}
 
@@ -714,7 +714,7 @@
 
 		if (opt_password == NULL) {
 			DEBUG(1, ("Out of memory\n"));
-			x_fprintf(x_stdout, "BH\n");
+			x_fprintf(x_stdout, "BH Out of memory\n");
 			data_blob_free(&request);
 			return;
 		}
@@ -741,14 +741,14 @@
 			x_fprintf(x_stdout, "GK %s\n", key64?key64:"<NULL>");
 			SAFE_FREE(key64);
 		} else {
-			x_fprintf(x_stdout, "BH\n");
+			x_fprintf(x_stdout, "BH missing NTLMSSP session key\n");
 		}
 			
 		data_blob_free(&request);
 		return;
 	} else {
-		DEBUG(1, ("NTLMSSP query [%s] invalid", buf));
-		x_fprintf(x_stdout, "BH\n");
+		DEBUG(1, ("NTLMSSP query [%s] invalid\n", buf));
+		x_fprintf(x_stdout, "BH NTLMSSP query [%s] invalid\n", buf);
 		return;
 	}
 
@@ -817,8 +817,8 @@
 	}
 
 	if (strlen(buf) < 2) {
-		DEBUG(1, ("NTLMSSP query [%s] invalid", buf));
-		x_fprintf(x_stdout, "BH\n");
+		DEBUG(1, ("NTLMSSP query [%s] invalid\n", buf));
+		x_fprintf(x_stdout, "BH NTLMSSP query [%s] invalid\n", buf);
 		return;
 	}
 
@@ -842,7 +842,7 @@
 
 		if (opt_password == NULL) {
 			DEBUG(1, ("Out of memory\n"));
-			x_fprintf(x_stdout, "BH\n");
+			x_fprintf(x_stdout, "BH Out of memory\n");
 			data_blob_free(&request);
 			return;
 		}
@@ -892,14 +892,14 @@
 			SAFE_FREE(key64);
 		}
 		else {
-			x_fprintf(x_stdout, "BH\n");
+			x_fprintf(x_stdout, "BH missing session key\n");
 		}
 
 		data_blob_free(&request);
 		return;
 	} else {
-		DEBUG(1, ("NTLMSSP query [%s] invalid", buf));
-		x_fprintf(x_stdout, "BH\n");
+		DEBUG(1, ("NTLMSSP query [%s] invalid\n", buf));
+		x_fprintf(x_stdout, "BH NTLMSSP query [%s] invalid\n", buf);
 		return;
 	}
 
@@ -1027,7 +1027,7 @@
 
 	if (len == -1) {
 		DEBUG(1, ("Could not write SPNEGO data blob\n"));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH Could not write SPNEGO data blob\n");
 		return;
 	}
 
@@ -1057,8 +1057,8 @@
 	pstring     reply_argument;
 
 	if (strlen(buf) < 2) {
-		DEBUG(1, ("SPENGO query [%s] invalid", buf));
-		x_fprintf(x_stdout, "BH\n");
+		DEBUG(1, ("SPNEGO query [%s] invalid\n", buf));
+		x_fprintf(x_stdout, "BH SPNEGO query [%s] invalid\n", buf);
 		return;
 	}
 
@@ -1068,8 +1068,8 @@
 	} else if (strncmp(buf, "KK", 2) == 0) {
 		
 	} else {
-		DEBUG(1, ("SPENGO query [%s] invalid", buf));
-		x_fprintf(x_stdout, "BH\n");
+		DEBUG(1, ("SPNEGO query [%s] invalid\n", buf));
+		x_fprintf(x_stdout, "BH SPNEGO query [%s] invalid\n", buf);
 		return;
 	}
 
@@ -1086,7 +1086,7 @@
 
 	if (strlen(buf) <= 3) {
 		DEBUG(1, ("GSS-SPNEGO query [%s] invalid\n", buf));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH GSS-SPENEGO query [%s] invalid\n", buf);
 		return;
 	}
 
@@ -1096,7 +1096,7 @@
 
 	if (len == -1) {
 		DEBUG(1, ("GSS-SPNEGO query [%s] invalid", buf));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH GSS-SPNEGO query [%s] invalid", buf);
 		return;
 	}
 
@@ -1107,8 +1107,8 @@
 
 		if ( (request.negTokenInit.mechTypes == NULL) ||
 		     (request.negTokenInit.mechTypes[0] == NULL) ) {
-			DEBUG(1, ("Client did not offer any mechanism"));
-			x_fprintf(x_stdout, "BH\n");
+			DEBUG(1, ("Client did not offer any mechanism\n"));
+			x_fprintf(x_stdout, "BH Client did not offer any mechanism\n");
 			return;
 		}
 
@@ -1116,15 +1116,15 @@
 		if (strcmp(request.negTokenInit.mechTypes[0], OID_NTLMSSP) == 0) {
 
 			if ( request.negTokenInit.mechToken.data == NULL ) {
-				DEBUG(1, ("Client did not provide  NTLMSSP data\n"));
-				x_fprintf(x_stdout, "BH\n");
+				DEBUG(1, ("Client did not provide NTLMSSP data\n"));
+				x_fprintf(x_stdout, "BH Client did not provide NTLMSSP data\n");
 				return;
 			}
 
 			if ( ntlmssp_state != NULL ) {
 				DEBUG(1, ("Client wants a new NTLMSSP challenge, but "
 					  "already got one\n"));
-				x_fprintf(x_stdout, "BH\n");
+				x_fprintf(x_stdout, "BH Client wants a new NTLMSSP challenge, but already got one\n");
 				ntlmssp_end(&ntlmssp_state);
 				return;
 			}
@@ -1157,7 +1157,7 @@
 
 			if ( request.negTokenInit.mechToken.data == NULL ) {
 				DEBUG(1, ("Client did not provide Kerberos data\n"));
-				x_fprintf(x_stdout, "BH\n");
+				x_fprintf(x_stdout, "BH Client did not provide Kerberos data\n");
 				return;
 			}
 
@@ -1183,7 +1183,7 @@
 				if (domain == NULL) {
 					DEBUG(1, ("Did not get a valid principal "
 						  "from ads_verify_ticket\n"));
-					x_fprintf(x_stdout, "BH\n");
+					x_fprintf(x_stdout, "BH Did not get a valid principal from ads_verify_ticket\n");
 					return;
 				}
 
@@ -1206,13 +1206,14 @@
 			   is the only one we support that sends this stuff */
 			DEBUG(1, ("Got a negTokenTarg for something non-NTLMSSP: %s\n",
 				  request.negTokenTarg.supportedMech));
-			x_fprintf(x_stdout, "BH\n");
+			x_fprintf(x_stdout, "BH Got a negTokenTarg for something non-NTLMSSP: %s\n",
+				  request.negTokenTarg.supportedMech);
 			return;
 		}
 
 		if (request.negTokenTarg.responseToken.data == NULL) {
 			DEBUG(1, ("Got a negTokenTarg without a responseToken!\n"));
-			x_fprintf(x_stdout, "BH\n");
+			x_fprintf(x_stdout, "BH Got a negTokenTarg without a responseToken!\n");
 			return;
 		}
 
@@ -1256,7 +1257,7 @@
 
 	if (len == -1) {
 		DEBUG(1, ("Could not write SPNEGO data blob\n"));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH Could not write SPNEGO data blob\n");
 		return;
 	}
 
@@ -1346,7 +1347,7 @@
 
 	if (client_ntlmssp_state == NULL) {
 		DEBUG(1, ("Got NTLMSSP tArg without a client state\n"));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH Got NTLMSSP tArg without a client state\n");
 		return;
 	}
 
@@ -1370,7 +1371,9 @@
 		DEBUG(1, ("Expected MORE_PROCESSING_REQUIRED from "
 			  "ntlmssp_client_update, got: %s\n",
 			  nt_errstr(status)));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH Expected MORE_PROCESSING_REQUIRED from "
+			  "ntlmssp_client_update, got: %s\n",
+			  nt_errstr(status));
 		data_blob_free(&request);
 		ntlmssp_end(&client_ntlmssp_state);
 		return;
@@ -1486,7 +1489,7 @@
 	switch (spnego.negTokenTarg.negResult) {
 	case SPNEGO_ACCEPT_INCOMPLETE:
 		DEBUG(1, ("Got a Kerberos negTokenTarg with ACCEPT_INCOMPLETE\n"));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH Got a Kerberos negTokenTarg with ACCEPT_INCOMPLETE\n");
 		break;
 	case SPNEGO_ACCEPT_COMPLETED:
 		DEBUG(10, ("Accept completed\n"));
@@ -1518,7 +1521,7 @@
 
 	if (strlen(buf) <= 3) {
 		DEBUG(1, ("SPNEGO query [%s] too short\n", buf));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH SPNEGO query [%s] too short\n", buf);
 		return;
 	}
 
@@ -1532,7 +1535,7 @@
 		
 		if (opt_password == NULL) {
 			DEBUG(1, ("Out of memory\n"));
-			x_fprintf(x_stdout, "BH\n");
+			x_fprintf(x_stdout, "BH Out of memory\n");
 			data_blob_free(&request);
 			return;
 		}
@@ -1546,7 +1549,7 @@
 	     (strncmp(buf, "AF ", 3) != 0) &&
 	     (strncmp(buf, "NA ", 3) != 0) ) {
 		DEBUG(1, ("SPNEGO request [%s] invalid\n", buf));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH SPNEGO request [%s] invalid\n", buf);
 		data_blob_free(&request);
 		return;
 	}
@@ -1559,7 +1562,7 @@
 
 	if (len == -1) {
 		DEBUG(1, ("Could not read SPNEGO data for [%s]\n", buf));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH Could not read SPNEGO data for [%s]\n", buf);
 		return;
 	}
 
@@ -1588,7 +1591,7 @@
 		}
 
 		DEBUG(1, ("Server offered no compatible mechanism\n"));
-		x_fprintf(x_stdout, "BH\n");
+		x_fprintf(x_stdout, "BH Server offered no compatible mechanism\n");
 		return;
 	}
 
@@ -1610,7 +1613,9 @@
 				DEBUG(1, ("Got a negTokenTarg with no mech and an "
 					  "unknown negResult: %d\n",
 					  spnego.negTokenTarg.negResult));
-				x_fprintf(x_stdout, "BH\n");
+				x_fprintf(x_stdout, "BH Got a negTokenTarg with no mech and an "
+					  "unknown negResult: %d\n",
+					  spnego.negTokenTarg.negResult);
 			}
 
 			ntlmssp_end(&client_ntlmssp_state);
@@ -1634,7 +1639,7 @@
 	}
 
 	DEBUG(1, ("Got an SPNEGO token I could not handle [%s]!\n", buf));
-	x_fprintf(x_stdout, "BH\n");
+	x_fprintf(x_stdout, "BH Got an SPNEGO token I could not handle [%s]!\n", buf);
 	return;
 
  out:
