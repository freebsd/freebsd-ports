--- config_gram.y.orig	2011-05-12 02:54:26.000000000 +0200
+++ config_gram.y	2011-05-12 02:55:18.000000000 +0200
@@ -106,7 +106,7 @@
 			  SPIT("Setting Group: %s\n", Spread_group); }
 		|	W_LOG     W_EQUALS W_STRING
 		|	W_CONTROL W_EQUALS W_STRING
-			{ snprintf(control_socket, MAXPATHLEN, $3.string); }
+			{ snprintf(control_socket, MAXPATHLEN, "%s", $3.string); }
 		|	W_MATURE W_EQUALS W_TIMEINTERVAL
 			{ Maturity_timeout.sec = $3.tv.tv_sec;
 			  Maturity_timeout.usec = 0;
