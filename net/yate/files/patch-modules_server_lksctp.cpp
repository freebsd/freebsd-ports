--- modules/server/lksctp.cpp.orig	2018-08-30 14:23:27 UTC
+++ modules/server/lksctp.cpp
@@ -521,9 +521,10 @@ bool LKSocket::alive() const
 		    status.sstat_primary.spinfo_state);
 	    }
     }
-    static int s_lastSstatState = SCTP_EMPTY;
+    //static int s_lastSstatState = SCTP_EMPTY;
+    static int s_lastSstatState = SCTP_CLOSED;
     switch (status.sstat_state) {
-	MAKE_CASE(EMPTY,Association);
+	//MAKE_CASE(EMPTY,Association);
 	MAKE_CASE(CLOSED,Association);
 	MAKE_CASE(COOKIE_WAIT,Association);
 	MAKE_CASE(COOKIE_ECHOED,Association);
