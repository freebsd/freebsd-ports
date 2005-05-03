
$FreeBSD$

--- channels/chan_sip.c.orig	Sun Feb 17 18:01:43 2002
+++ channels/chan_sip.c	Sun Feb 17 18:10:52 2002
@@ -141,7 +141,7 @@
 
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
@@ -2218,7 +2219,7 @@
 	if (p->owner) {
 		/* We already hold the channel lock */
 		if (f->frametype == AST_FRAME_VOICE) {
-			if (f->subclass != p->owner->nativeformats) {
+			if (!(f->subclass & p->owner->nativeformats)) {
 				ast_log(LOG_DEBUG, "Oooh, format changed to %d\n", f->subclass);
 				p->owner->nativeformats = f->subclass;
 				ast_set_read_format(p->owner, p->owner->readformat);
@@ -4620,6 +4621,10 @@
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
@@ -4643,31 +4648,41 @@
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
@@ -7338,7 +7353,11 @@
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
@@ -7366,7 +7385,6 @@
 				c = sip_new(p, AST_STATE_DOWN, ast_strlen_zero(p->username) ? NULL : p->username );
 				*recount = 1;
 				/* Save Record-Route for any later requests we make on this dialogue */
-				build_route(p, req, 0);
 				if (c) {
 					/* Pre-lock the call */
 					ast_mutex_lock(&c->lock);
@@ -7426,6 +7444,14 @@
 				transmit_response(p, "180 Ringing", req);
 				break;
 			case AST_STATE_UP:
+				/* Assuming this to be reinvite, process new SDP portion */
+				if (!ast_strlen_zero(get_header(req, "Content-Type"))) {
+					process_sdp(p, req);
+				} else {
+					p->jointcapability = p->capability;
+					ast_log(LOG_DEBUG, "Hm....  No sdp for the moment\n");
+				}
+
 				transmit_response_with_sdp(p, "200 OK", req, 1);
 				break;
 			default:
