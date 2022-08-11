--- src/mlmmj-send.c.orig	2022-07-14 05:25:21 UTC
+++ src/mlmmj-send.c
@@ -817,13 +817,12 @@ int main(int argc, char **argv)
 	char *listctrl = NULL, *subddirname = NULL, *listdir = NULL;
 	char *mlmmjbounce = NULL, *bindir, *mailmap, *probefile, *a;
 	char *body = NULL, *hdrs = NULL, *memmailsizestr = NULL, *verp = NULL;
-	char relay[16], *listname, *listfqdn, *verpfrom, *maxverprecipsstr;
+	char *listname, *listfqdn, *verpfrom, *maxverprecipsstr;
 	char strindex[32], *reply, *strport, *smtphelo, *requeuefilename;
 	ssize_t memmailsize = 0;
 	DIR *subddir;
 	struct dirent *dp;
 	struct stat st;
-	struct hostent *relayent;
 	uid_t uid;
 	struct strlist stl;
 	unsigned short smtpport = 25;
@@ -1080,22 +1079,11 @@ int main(int argc, char **argv)
 
 	itoa(mindex, strindex);
 
-	if(!relayhost) {
+	if(!relayhost)
 		relayhost = ctrlvalue(listdir, "relayhost");
-	}
 	if(!relayhost)
-		strncpy(relay, RELAYHOST, sizeof(relay));
-	else {
-		relayent = gethostbyname(relayhost);
-		if(relayent == NULL) {
-			strncpy(relay, RELAYHOST, sizeof(relay));
-		} else {
-			if(inet_ntop(relayent->h_addrtype,
-				     relayent->h_addr_list[0],
-				     relay, sizeof(relay)) == NULL)
-				strncpy(relay, RELAYHOST, sizeof(relay));
-		}
-	}
+		relayhost = mystrdup(RELAYHOST);
+
 	strport = ctrlvalue(listdir, "smtpport");
 	if(strport)
 		smtpport = (unsigned short)atol(strport);
@@ -1107,7 +1095,7 @@ int main(int argc, char **argv)
 	switch(listctrl[0]) {
 	case '1': /* A single mail is to be sent */
 	case '6':
-		initsmtp(&sockfd, relay, smtpport, smtphelo);
+		initsmtp(&sockfd, relayhost, smtpport, smtphelo);
 		if(send_mail(sockfd, bounceaddr, to_addr, replyto,
 				mailmap, st.st_size, listdir, NULL,
 				hdrs, hdrslen, body, bodylen)) {
@@ -1165,7 +1153,7 @@ int main(int argc, char **argv)
 		}
 		break;
 	case '2': /* Moderators */
-		initsmtp(&sockfd, relay, smtpport, smtphelo);
+		initsmtp(&sockfd, relayhost, smtpport, smtphelo);
 		if(send_mail_many_fd(sockfd, bounceaddr, NULL, mailmap,
 				     st.st_size, subfd, NULL, NULL, NULL,
 				     listdir, NULL, hdrs, hdrslen,
@@ -1177,7 +1165,7 @@ int main(int argc, char **argv)
 		}
 		break;
 	case '3': /* resending earlier failed mails */
-		initsmtp(&sockfd, relay, smtpport, smtphelo);
+		initsmtp(&sockfd, relayhost, smtpport, smtphelo);
 		if(send_mail_many_fd(sockfd, NULL, NULL, mailmap, st.st_size,
 				subfd, listaddr, listdelim, mailfilename,
 				listdir, mlmmjbounce, hdrs, hdrslen,
@@ -1190,7 +1178,7 @@ int main(int argc, char **argv)
 		unlink(subfilename);
 		break;
 	case '4': /* send mails to owner */
-		initsmtp(&sockfd, relay, smtpport, smtphelo);
+		initsmtp(&sockfd, relayhost, smtpport, smtphelo);
 		if(send_mail_many_fd(sockfd, bounceaddr, NULL, mailmap,
 				st.st_size, subfd, listaddr, listdelim,
 				mailfilename, listdir, mlmmjbounce,
@@ -1202,7 +1190,7 @@ int main(int argc, char **argv)
 		}
 		break;
 	case '5': /* bounceprobe - handle relayhost local users bouncing*/
-		initsmtp(&sockfd, relay, smtpport, smtphelo);
+		initsmtp(&sockfd, relayhost, smtpport, smtphelo);
 		if(send_mail(sockfd, bounceaddr, to_addr, replyto,
 				mailmap, st.st_size, listdir, NULL,
 				hdrs, hdrslen, body, bodylen)) {
@@ -1267,7 +1255,7 @@ int main(int argc, char **argv)
 		}
 		
 		if(verp) {
-			initsmtp(&sockfd, relay, smtpport, smtphelo);
+			initsmtp(&sockfd, relayhost, smtpport, smtphelo);
 			if(sockfd > -1) {
 			    if(write_mail_from(sockfd, verpfrom, verp)) {
 				log_error(LOG_ARGS,
@@ -1331,7 +1319,7 @@ int main(int argc, char **argv)
 					}
 				}
 				if(stl.count == maxverprecips) {
-					initsmtp(&sockfd, relay, smtpport, smtphelo);
+					initsmtp(&sockfd, relayhost, smtpport, smtphelo);
 					if(verp) {
 						sendres = send_mail_verp(
 								sockfd, &stl,
@@ -1375,7 +1363,7 @@ int main(int argc, char **argv)
 
 		}
 		if(stl.count) {
-			initsmtp(&sockfd, relay, smtpport, smtphelo);
+			initsmtp(&sockfd, relayhost, smtpport, smtphelo);
 			if(verp) {
 				sendres = send_mail_verp(sockfd, &stl, mailmap,
 						st.st_size, verpfrom, listdir,
