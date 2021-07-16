--- src/main/state.c.orig
+++ src/main/state.c
@@ -311,15 +311,30 @@ static state_entry_t *fr_state_cleanup_find(fr_state_t *state)
 			continue;
 		}
 
+		/*
+		 *	Not yet time to clean it up.
+		 */
+		if (entry->cleanup > now) {
+			continue;
+		}
+
+		/*
+		 *	We're not running the "client lost" section.
+		 *	Just nuke the entry now.
+		 */
+		if (!main_config.postauth_client_lost) {
+			state_entry_free(state, entry);
+			continue;
+		}
+
 		/*
 		 *	Old enough that the request has been removed.
 		 *	We can add it to the cleanup list.
 		 */
-		if (entry->cleanup < now) {
-			(*tail) = entry;
-			state_entry_unlink(state, entry);
-			tail = &entry->next;
-		}
+		state_entry_unlink(state, entry);
+		entry->next = NULL;
+		(*tail) = entry;
+		tail = &entry->next;
 	}
 
 	return head;
@@ -335,30 +349,28 @@ static void fr_state_cleanup(state_entry_t *head)
 	if (!head) return;
 
 	for (entry = head; entry != NULL; entry = next) {
-		next = entry->next;
+		REQUEST *request;
 
-		if (main_config.postauth_client_lost) {
-			REQUEST *request;
+		next = entry->next;
 
-			request = fr_state_cleanup_request(entry);
-			if (request) {
-				RDEBUG2("No response from client, cleaning up expired state");
-				RDEBUG2("Restoring &session-state");
+		request = fr_state_cleanup_request(entry);
+		if (request) {
+			RDEBUG2("No response from client, cleaning up expired state");
+			RDEBUG2("Restoring &session-state");
 
-				/*
-				 *	@todo - print out message
-				 *	saying where the handler was
-				 *	in the process?  i.e. "sent
-				 *	server cert", etc.  This will
-				 *	require updating the EAP code
-				 *	to put a new attribute into
-				 *	the session state list.
-				 */
+			/*
+			 *	@todo - print out message
+			 *	saying where the handler was
+			 *	in the process?  i.e. "sent
+			 *	server cert", etc.  This will
+			 *	require updating the EAP code
+			 *	to put a new attribute into
+			 *	the session state list.
+			 */
 
-				rdebug_pair_list(L_DBG_LVL_2, request, request->state, "&session-state:");
+			rdebug_pair_list(L_DBG_LVL_2, request, request->state, "&session-state:");
 
-				request_inject(request);
-			}
+			request_inject(request);
 		}
 
 		talloc_free(entry);
