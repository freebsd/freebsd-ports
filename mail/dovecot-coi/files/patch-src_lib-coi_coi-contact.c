--- src/lib-coi/coi-contact.c.orig	2019-12-04 09:11:06 UTC
+++ src/lib-coi/coi-contact.c
@@ -500,7 +500,7 @@ static int lmtp_coi_mail_bodies_equal(struct mail *mai
 	if (mail_get_stream(mail1, &hdr_size, NULL, &input1) < 0) {
 		errstr = mailbox_get_last_error(mail1->box, &error);
 		if (error != MAIL_ERROR_EXPUNGED)
-			e_error(mail1->event, "Contact merge failed: "
+			e_error(mail_event(mail1), "Contact merge failed: "
 				"Failed to read mail: %s", errstr);
 		return -1;
 	}
@@ -509,7 +509,7 @@ static int lmtp_coi_mail_bodies_equal(struct mail *mai
 	if (mail_get_stream(mail2, &hdr_size, NULL, &input2) < 0) {
 		errstr = mailbox_get_last_error(mail2->box, &error);
 		if (error != MAIL_ERROR_EXPUNGED)
-			e_error(mail2->event, "Contact merge failed: "
+			e_error(mail_event(mail2), "Contact merge failed: "
 				"Failed to read mail: %s", errstr);
 		return -1;
 	}
@@ -534,12 +534,12 @@ static int lmtp_coi_mail_bodies_equal(struct mail *mai
 	i_assert(input1->eof && input2->eof);
 
 	if (input1->stream_errno != 0) {
-		e_error(mail1->event, "Contact merge failed: "
+		e_error(mail_event(mail1), "Contact merge failed: "
 			"Failed to read mail: %s", i_stream_get_error(input1));
 		return -1;
 	}
 	if (input2->stream_errno != 0) {
-		e_error(mail2->event, "Contact merge failed: "
+		e_error(mail_event(mail2), "Contact merge failed: "
 			"Failed to read mail: %s", i_stream_get_error(input2));
 		return -1;
 	}
