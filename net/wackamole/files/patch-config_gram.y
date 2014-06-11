--- config_gram.y.orig	2014-05-06 16:30:17.040722949 -0700
+++ config_gram.y	2014-05-06 16:32:22.614815187 -0700
@@ -106,7 +106,7 @@
 			  SPIT("Setting Group: %s\n", Spread_group); }
 		|	W_LOG     W_EQUALS W_STRING
 		|	W_CONTROL W_EQUALS W_STRING
-			{ snprintf(control_socket, MAXPATHLEN, $3.string); }
+			{ snprintf(control_socket, MAXPATHLEN, "%s", $3.string); }
 		|	W_MATURE W_EQUALS W_TIMEINTERVAL
 			{ Maturity_timeout.sec = $3.tv.tv_sec;
 			  Maturity_timeout.usec = 0;
