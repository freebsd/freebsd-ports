--- mh/msgchk.c.orig	2022-02-12 15:20:43 UTC
+++ mh/msgchk.c
@@ -274,12 +274,18 @@ checkmail (const char *username, int personal)
 	      break;
 
 	    default:
-	      if (rc != ENOSYS && rc != MU_ERR_INFO_UNAVAILABLE)
-		mu_diag_funcall (MU_DIAG_ERROR, "mu_mailbox_messages_unseen",
-				 mu_url_to_string (url), rc);
+	      mu_diag_funcall (MU_DIAG_ERROR, "mu_mailbox_messages_unseen",
+			       mu_url_to_string (url), rc);
+	      /* FALLTHROUGH */
+	    case EAGAIN:
+	    case EINTR:
+	    case ENOSYS:
+	    case EINPROGRESS:
+	    case MU_ERR_INFO_UNAVAILABLE:
 	      rc = mu_mailbox_messages_recent (mbox, &recent);
 	      if (rc == 0)
 		newmail = recent > 0;
+	      break;
 	    }
 
 	  if (rc)
