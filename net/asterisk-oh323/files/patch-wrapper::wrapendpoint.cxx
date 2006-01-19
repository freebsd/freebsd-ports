--- wrapper/wrapendpoint.cxx.orig	Wed Jan 18 11:11:31 2006
+++ wrapper/wrapendpoint.cxx	Wed Jan 18 11:12:23 2006
@@ -1206,7 +1206,7 @@ WrapH323EndPoint::CreateConnection(unsig
 				WRAPTRACE(2, "Incoming connection with no calling party number in SETUP.");
 				ud.calling_num[0] = '\0';
 			}
-			tmp.MakeEmpty();
+			tmp = PString();
 			/* Get Called party number */
 			(setupPDU->GetQ931()).GetCalledPartyNumber(tmp);
 			if (!tmp.IsEmpty()) {
@@ -1230,7 +1230,7 @@ WrapH323EndPoint::CreateConnection(unsig
 				WRAPTRACE(2, "Incoming connection with no called party number in SETUP.");
 				ud.called_num[0] = '\0';
 			}
-			tmp.MakeEmpty();
+			tmp = PString();
 			/* Get Redirecting number */
 			(setupPDU->GetQ931()).GetRedirectingNumber(tmp);
 			if (!tmp.IsEmpty()) {
