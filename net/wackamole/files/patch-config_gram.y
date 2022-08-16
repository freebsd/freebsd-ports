--- config_gram.y.orig	2005-11-14 17:17:53 UTC
+++ config_gram.y
@@ -106,7 +106,7 @@ Setting		:	W_SPREAD W_EQUALS W_STRING
 			  SPIT("Setting Group: %s\n", Spread_group); }
 		|	W_LOG     W_EQUALS W_STRING
 		|	W_CONTROL W_EQUALS W_STRING
-			{ snprintf(control_socket, MAXPATHLEN, $3.string); }
+			{ snprintf(control_socket, MAXPATHLEN, "%s", $3.string); }
 		|	W_MATURE W_EQUALS W_TIMEINTERVAL
 			{ Maturity_timeout.sec = $3.tv.tv_sec;
 			  Maturity_timeout.usec = 0;
