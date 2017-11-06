--- plugins/check_http.c.orig	2017-04-19 16:03:12 UTC
+++ plugins/check_http.c
@@ -1026,11 +1026,9 @@ check_http (void)
     elapsed_time_ssl = (double)microsec_ssl / 1.0e6;
     if (check_cert == TRUE) {
 			result = np_net_ssl_check_cert(days_till_exp_warn, days_till_exp_crit);
-			if (result != STATE_OK) {
-				np_net_ssl_cleanup();
-				if (sd) close(sd);
-				return result;
-			}
+			np_net_ssl_cleanup();
+			if (sd) close(sd);
+			return result;
     }
   }
 #endif /* HAVE_SSL */
