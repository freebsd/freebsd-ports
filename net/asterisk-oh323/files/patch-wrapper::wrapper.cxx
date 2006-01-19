--- wrapper/wrapper.cxx.orig	Wed Jan 18 11:15:33 2006
+++ wrapper/wrapper.cxx	Wed Jan 18 11:15:36 2006
@@ -570,7 +570,7 @@ extern "C" {
 		{ H323Connection::EndedByTemporaryFailure, OH323END_TEMP_FAILURE, "Temporary failure" },
 		{ H323Connection::EndedByQ931Cause, OH323END_Q931CAUSE, "Call ended with Q.931 cause" },
 		{ H323Connection::EndedByDurationLimit, OH323END_DURATION_LIMIT, "Call ended due to enforced duration limit" },
-		{ H323Connection::EndedByInvalidConferenceID, OH323END_INVALIDCID, "Call cleared due to invalid conference ID" },
+//		{ H323Connection::EndedByInvalidConferenceID, OH323END_INVALIDCID, "Call cleared due to invalid conference ID" },
 		{ -1, -1, "Unknown reason" },
 	};
 
