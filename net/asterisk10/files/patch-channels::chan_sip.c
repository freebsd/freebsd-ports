
$FreeBSD$

--- channels/chan_sip.c.orig	Wed Jan 14 08:10:53 2004
+++ channels/chan_sip.c	Fri Jan 30 01:47:34 2004
@@ -124,7 +124,7 @@
 static int restart_monitor(void);
 
 /* Codecs that we support by default: */
-static int capability = AST_FORMAT_ULAW | AST_FORMAT_ALAW | AST_FORMAT_GSM | AST_FORMAT_H263;
+static int capability = AST_FORMAT_ULAW | AST_FORMAT_ALAW | AST_FORMAT_GSM | AST_FORMAT_H263 | AST_FORMAT_G723_1 | AST_FORMAT_G729A;
 static int noncodeccapability = AST_RTP_DTMF;
 
 static char ourhost[256];
@@ -176,6 +176,7 @@
 struct sip_route {
 	struct sip_route *next;
 	char hop[0];
+	int lr;
 };
 
 static struct sip_pvt {
@@ -3417,6 +3418,10 @@
 			/* Make a struct route */
 			thishop = (struct sip_route *)malloc(sizeof(struct sip_route)+len+1);
 			if (thishop) {
+				if (strnstr(rr, ";lr", len) != NULL)
+					thishop->lr = 1;
+				else
+					thishop->lr = 0;
 				strncpy(thishop->hop, rr, len);
 				thishop->hop[len] = '\0';
 				ast_log(LOG_DEBUG, "build_route: Record-Route hop: <%s>\n", thishop->hop);
@@ -3440,31 +3445,41 @@
 			rr += len+1;
 		}
 	}
-	/* 2nd append the Contact: if there is one */
-	/* Can be multiple Contact headers, comma separated values - we just take the first */
-	contact = get_header(req, "Contact");
-	if (strlen(contact)) {
-		ast_log(LOG_DEBUG, "build_route: Contact hop: %s\n", contact);
-		/* Look for <: delimited address */
-		c = strchr(contact, '<');
-		if (c) {
-			/* Take to > */
-			++c;
-			len = strcspn(c, ">");
-		} else {
-			/* No <> - just take the lot */
-			c = contact; len = strlen(contact);
-		}
-		thishop = (struct sip_route *)malloc(sizeof(struct sip_route)+len+1);
+	/* Duplicate first route from the list */
+	if (head && head->lr) {
+		thishop = (struct sip_route *)malloc(sizeof(struct sip_route)+strlen(head->hop)+1);
 		if (thishop) {
-			strncpy(thishop->hop, c, len);
-			thishop->hop[len] = '\0';
-			thishop->next = NULL;
-			/* Goes at the end */
-			if (tail)
-				tail->next = thishop;
-			else
-				head = thishop;
+			memcpy(thishop, head, sizeof(struct sip_route)+strlen(head->hop)+1);
+			thishop->next = head;
+			head = thishop;
+		}
+	} else {
+		/* Append the Contact: if there is one and first route is w/o `lr' param */
+		/* Can be multiple Contact headers, comma separated values - we just take the first */
+		contact = get_header(req, "Contact");
+		if (strlen(contact)) {
+			ast_log(LOG_DEBUG, "build_route: Contact hop: %s\n", contact);
+			/* Look for <: delimited address */
+			c = strchr(contact, '<');
+			if (c) {
+				/* Take to > */
+				++c;
+				len = strcspn(c, ">");
+			} else {
+				/* No <> - just take the lot */
+				c = contact; len = strlen(contact);
+			}
+			thishop = (struct sip_route *)malloc(sizeof(struct sip_route)+len+1);
+			if (thishop) {
+				strncpy(thishop->hop, c, len);
+				thishop->hop[len] = '\0';
+				thishop->next = NULL;
+				/* Goes at the end */
+				if (tail)
+					tail->next = thishop;
+				else
+					head = thishop;
+			}
 		}
 	}
 	/* Store as new route */
@@ -5143,7 +5158,11 @@
 			/* Get destination right away */
 			gotdest = get_destination(p, NULL);
 			get_rdnis(p, NULL);
-			extract_uri(p, req);
+			build_route(p, req, 0);
+			if (!p->route->lr)
+				strncpy(p->uri, p->route->hop, sizeof(p->uri) - 1);
+			else
+				extract_uri(p, req);
 			build_contact(p);
 
 			if (gotdest) {
@@ -5165,7 +5184,6 @@
 				c = sip_new(p, AST_STATE_DOWN, strlen(p->username) ? p->username : NULL);
 				*recount = 1;
 				/* Save Record-Route for any later requests we make on this dialogue */
-				build_route(p, req, 0);
 				if (c) {
 					/* Pre-lock the call */
 					ast_mutex_lock(&c->lock);
