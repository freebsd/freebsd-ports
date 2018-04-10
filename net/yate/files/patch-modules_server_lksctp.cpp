--- modules/server/lksctp.cpp.orig	2018-03-28 11:56:42 UTC
+++ modules/server/lksctp.cpp
@@ -529,9 +529,10 @@ bool LKSocket::alive() const
 		    status.sstat_primary.spinfo_state);
 	    }
     }
-    static int s_lastSstatState = SCTP_EMPTY;
+    //static int s_lastSstatState = SCTP_EMPTY;
+    static int s_lastSstatState = SCTP_CLOSED;
     switch (status.sstat_state) {
-	MAKE_CASE(EMPTY,Local);
+	//MAKE_CASE(EMPTY,Local);
 	MAKE_CASE(CLOSED,Local);
 	MAKE_CASE(COOKIE_WAIT,Local);
 	MAKE_CASE(COOKIE_ECHOED,Local);
