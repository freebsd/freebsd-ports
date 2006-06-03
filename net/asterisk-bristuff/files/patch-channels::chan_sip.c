--- channels/chan_sip.c.orig	Sat Jun  3 21:41:59 2006
+++ channels/chan_sip.c	Sat Jun  3 21:43:40 2006
@@ -337,7 +337,7 @@
 
 static char default_language[MAX_LANGUAGE] = "";
 
-#define DEFAULT_CALLERID "asterisk"
+#define DEFAULT_CALLERID "Unknown"
 static char default_callerid[AST_MAX_EXTENSION] = DEFAULT_CALLERID;
 
 static char default_fromdomain[AST_MAX_EXTENSION] = "";
@@ -475,6 +475,7 @@
 
 struct sip_route {
 	struct sip_route *next;
+	int lr;
 	char hop[0];
 };
 
@@ -6048,6 +6049,7 @@
 			/* Make a struct route */
 			thishop = malloc(sizeof(*thishop) + len);
 			if (thishop) {
+				thishop->lr = (strnstr(rr, ";lr", len) != NULL ? 1 : 0);
 				ast_copy_string(thishop->hop, rr, len);
 				ast_log(LOG_DEBUG, "build_route: Record-Route hop: <%s>\n", thishop->hop);
 				/* Link in */
@@ -6073,31 +6075,41 @@
 
 	/* Only append the contact if we are dealing with a strict router */
 	if (!head || (!ast_strlen_zero(head->hop) && strstr(head->hop,";lr") == NULL) ) {
-		/* 2nd append the Contact: if there is one */
-		/* Can be multiple Contact headers, comma separated values - we just take the first */
-		contact = get_header(req, "Contact");
-		if (!ast_strlen_zero(contact)) {
-			ast_log(LOG_DEBUG, "build_route: Contact hop: %s\n", contact);
-			/* Look for <: delimited address */
-			c = strchr(contact, '<');
-			if (c) {
-				/* Take to > */
-				++c;
-				len = strcspn(c, ">") + 1;
-			} else {
-				/* No <> - just take the lot */
-				c = contact;
-				len = strlen(contact) + 1;
-			}
-			thishop = malloc(sizeof(*thishop) + len);
+		/* Duplicate first route from the list */
+		if (head && head->lr) {
+			thishop = (struct sip_route *)malloc(sizeof(struct sip_route)+strlen(head->hop)+1);
 			if (thishop) {
-				ast_copy_string(thishop->hop, c, len);
-				thishop->next = NULL;
-				/* Goes at the end */
-				if (tail)
-					tail->next = thishop;
-				else
-					head = thishop;
+				memcpy(thishop, head, sizeof(struct sip_route)+strlen(head->hop)+1);
+				thishop->next = head;
+				head = thishop;
+			}
+		} else {
+			/* Append the Contact: if there is one and first route is w/o `lr' param */
+			/* Can be multiple Contact headers, comma separated values - we just take the first */
+			contact = get_header(req, "Contact");
+			if (!ast_strlen_zero(contact)) {
+				ast_log(LOG_DEBUG, "build_route: Contact hop: %s\n", contact);
+				/* Look for <: delimited address */
+				c = strchr(contact, '<');
+				if (c) {
+					/* Take to > */
+					++c;
+					len = strcspn(c, ">") + 1;
+				} else {
+					/* No <> - just take the lot */
+					c = contact;
+					len = strlen(contact) + 1;
+				}
+				thishop = malloc(sizeof(*thishop) + len);
+				if (thishop) {
+					ast_copy_string(thishop->hop, c, len);
+					thishop->next = NULL;
+					/* Goes at the end */
+					if (tail)
+						tail->next = thishop;
+					else
+						head = thishop;
+				}
 			}
 		}
 	}
@@ -10440,7 +10452,11 @@
 		gotdest = get_destination(p, NULL);
 
 		get_rdnis(p, NULL);
-		extract_uri(p, req);
+		build_route(p, req, 0);
+		if (!p->route->lr)
+			strncpy(p->uri, p->route->hop, sizeof(p->uri) - 1);
+		else
+			extract_uri(p, req);
 		build_contact(p);
 
 		if (gotdest) {
@@ -10468,7 +10484,6 @@
 			c = sip_new(p, AST_STATE_DOWN, ast_strlen_zero(p->username) ? NULL : p->username );
 			*recount = 1;
 			/* Save Record-Route for any later requests we make on this dialogue */
-			build_route(p, req, 0);
 			if (c) {
 				/* Pre-lock the call */
 				ast_mutex_lock(&c->lock);
@@ -10554,6 +10569,12 @@
 			transmit_response(p, "180 Ringing", req);
 			break;
 		case AST_STATE_UP:
+			/* Assuming this to be reinvite, process new SDP portion */
+			if (!ast_strlen_zero(get_header(req, "Content-Type"))) {
+				process_sdp(p, req);
+			} else {
+				ast_log(LOG_DEBUG, "Hm....  No sdp for the moment\n");
+			}
 			transmit_response_with_sdp(p, "200 OK", req, 1);
 			break;
 		default:
