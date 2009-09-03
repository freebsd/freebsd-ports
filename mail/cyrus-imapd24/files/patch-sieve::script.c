Index: sieve/script.c
diff -u -p sieve/script.c.orig sieve/script.c
--- sieve/script.c.orig	2008-03-25 05:08:46.000000000 +0900
+++ sieve/script.c	2009-09-03 10:58:13.498715559 +0900
@@ -688,7 +688,7 @@ static int do_sieve_error(int ret,
 	ret |= keep_ret;
         if (keep_ret == SIEVE_OK)
             snprintf(actions_string+strlen(actions_string),
-		     sizeof(actions_string)-strlen(actions_string),
+		     ACTIONS_STRING_LEN-strlen(actions_string),
 		     "Kept\n");
 	else {
 	    implicit_keep = 0;	/* don't try an implicit keep again */
@@ -742,7 +742,7 @@ static int do_action_list(sieve_interp_t
 	    
 	    if (ret == SIEVE_OK)
 		snprintf(actions_string+strlen(actions_string),
-			 sizeof(actions_string)-strlen(actions_string), 
+			 ACTIONS_STRING_LEN-strlen(actions_string), 
 			 "Rejected with: %s\n", a->u.rej.msg);
 
 	    break;
@@ -757,7 +757,7 @@ static int do_action_list(sieve_interp_t
 
 	    if (ret == SIEVE_OK)
 		snprintf(actions_string+strlen(actions_string),
-			 sizeof(actions_string)-strlen(actions_string),
+			 ACTIONS_STRING_LEN-strlen(actions_string),
 			 "Filed into: %s\n",a->u.fil.mailbox);
 	    break;
 	case ACTION_KEEP:
@@ -770,7 +770,7 @@ static int do_action_list(sieve_interp_t
 			       &errmsg);
 	    if (ret == SIEVE_OK)
 		snprintf(actions_string+strlen(actions_string),
-			 sizeof(actions_string)-strlen(actions_string),
+			 ACTIONS_STRING_LEN-strlen(actions_string),
 			 "Kept\n");
 	    break;
 	case ACTION_REDIRECT:
@@ -783,7 +783,7 @@ static int do_action_list(sieve_interp_t
 				   &errmsg);
 	    if (ret == SIEVE_OK)
 		snprintf(actions_string+strlen(actions_string),
-			 sizeof(actions_string)-strlen(actions_string),
+			 ACTIONS_STRING_LEN-strlen(actions_string),
 			 "Redirected to %s\n", a->u.red.addr);
 	    break;
 	case ACTION_DISCARD:
@@ -794,7 +794,7 @@ static int do_action_list(sieve_interp_t
 				      &errmsg);
 	    if (ret == SIEVE_OK)
 		snprintf(actions_string+strlen(actions_string),
-			 sizeof(actions_string)-strlen(actions_string),
+			 ACTIONS_STRING_LEN-strlen(actions_string),
 			 "Discarded\n");
 	    break;
 
@@ -820,12 +820,12 @@ static int do_action_list(sieve_interp_t
 
 		    if (ret == SIEVE_OK)
 			snprintf(actions_string+strlen(actions_string),
-				 sizeof(actions_string)-strlen(actions_string),
+				 ACTIONS_STRING_LEN-strlen(actions_string),
 				 "Sent vacation reply\n");
 
 		} else if (ret == SIEVE_DONE) {
 		    snprintf(actions_string+strlen(actions_string),
-			     sizeof(actions_string)-strlen(actions_string),
+			     ACTIONS_STRING_LEN-strlen(actions_string),
 			     "Vacation reply suppressed\n");
 
 		    ret = SIEVE_OK;
