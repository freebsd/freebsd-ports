
$FreeBSD$

--- channels/chan_sip.c.orig
+++ channels/chan_sip.c
@@ -139,7 +139,7 @@
 
 static char default_language[MAX_LANGUAGE] = "";
 
-static char default_callerid[AST_MAX_EXTENSION] = "asterisk";
+static char default_callerid[AST_MAX_EXTENSION] = "Unknown";
 
 static char default_fromdomain[AST_MAX_EXTENSION] = "";
 
@@ -244,6 +244,7 @@
 struct sip_route {
 	struct sip_route *next;
 	char hop[0];
+	int lr;
 };
 
 struct sip_history {
@@ -4573,6 +4574,10 @@
 			/* Make a struct route */
 			thishop = (struct sip_route *)malloc(sizeof(struct sip_route)+len+1);
 			if (thishop) {
+				if (strnstr(rr, ";lr", len) != NULL)
+					thishop->lr = 1;
+				else
+					thishop->lr = 0;
 				strncpy(thishop->hop, rr, len); /* safe */
 				thishop->hop[len] = '\0';
 				ast_log(LOG_DEBUG, "build_route: Record-Route hop: <%s>\n", thishop->hop);
@@ -4596,31 +4601,41 @@
 			rr += len+1;
 		}
 	}
-	/* 2nd append the Contact: if there is one */
-	/* Can be multiple Contact headers, comma separated values - we just take the first */
-	contact = get_header(req, "Contact");
-	if (!ast_strlen_zero(contact)) {
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
-			strncpy(thishop->hop, c, len); /* safe */
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
+		if (!ast_strlen_zero(contact)) {
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
+				strncpy(thishop->hop, c, len); /* safe */
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
@@ -7197,7 +7212,11 @@
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
@@ -7225,7 +7244,6 @@
 				c = sip_new(p, AST_STATE_DOWN, ast_strlen_zero(p->username) ? NULL : p->username );
 				*recount = 1;
 				/* Save Record-Route for any later requests we make on this dialogue */
-				build_route(p, req, 0);
 				if (c) {
 					/* Pre-lock the call */
 					ast_mutex_lock(&c->lock);
