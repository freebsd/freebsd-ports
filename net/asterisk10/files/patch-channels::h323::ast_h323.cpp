
$FreeBSD$

--- channels/h323/ast_h323.cpp.orig
+++ channels/h323/ast_h323.cpp
@@ -722,7 +722,7 @@
 	if (h323debug) {
 		cout << "	-- Sending user input tone (" << tone << ") to remote" << endl;
 	}
-	on_send_digit(GetCallReference(), tone);	
+	on_send_digit(GetCallReference(), &tone);	
 	H323Connection::SendUserInputTone(tone, duration);
 }
 
@@ -732,18 +732,20 @@
 		if (h323debug) {
 			cout << "	-- Received user input tone (" << tone << ") from remote" << endl;
 		}
-		on_send_digit(GetCallReference(), tone);
+		on_send_digit(GetCallReference(), &tone);
 	}
 	H323Connection::OnUserInputTone(tone, duration, logicalChannel, rtpTimestamp);
 }
 
 void MyH323Connection::OnUserInputString(const PString &value)
 {
+	char val;
 	if (mode == H323_DTMF_RFC2833) {
 		if (h323debug) {
 			cout <<  "	-- Received user input string (" << value << ") from remote." << endl;
 		}
-		on_send_digit(GetCallReference(), value[0]);
+		val = value[0];
+		on_send_digit(GetCallReference(), &val);
 	}	
 }
 
