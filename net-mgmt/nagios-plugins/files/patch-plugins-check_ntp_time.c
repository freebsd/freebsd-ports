Obtained from:
https://github.com/nagios-plugins/nagios-plugins/commit/df485c74f582708d6ce37cdf99880fe75215498a

--- plugins/check_ntp_time.c.orig	2018-01-04 12:59:01.422087000 -0800
+++ plugins/check_ntp_time.c	2018-01-04 13:05:56.317152000 -0800
@@ -415,6 +415,9 @@
 			}
 		}
 		/* lather, rinse, repeat. */
+		/* break if we have one response but other ntp servers doesn't response */
+		/* greater than timeout_interval/2 */
+		if (servers_completed && now_time-start_ts > timeout_interval/2) break;
 	}

 	if (one_read == 0) {
