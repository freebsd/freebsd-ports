--- dpinger.c.orig	2015-11-30 00:12:21 UTC
+++ dpinger.c
@@ -497,7 +497,7 @@ alert_thread(
     unsigned int		latency_alarm_decay = 0;
     unsigned int		loss_alarm_decay = 0;
     unsigned int		alert = 0;
-    unsigned int		alarm;
+    unsigned int		alarm_on;
     int				r;
 
     // Set up the timespec for nanosleep
@@ -599,12 +599,12 @@ alert_thread(
 	{
 	    alert = 0;
 
-	    alarm = latency_alarm_decay || loss_alarm_decay;
-	    logger("%s: latency %luus loss %lus\n", alarm ? "Alarm" : "Clear", average_latency, average_loss);
+	    alarm_on = latency_alarm_decay || loss_alarm_decay;
+	    logger("%s: latency %luus loss %lus\n", alarm_on ? "Alarm" : "Clear", average_latency, average_loss);
 
 	    if (alert_cmd)
 	    {
-		r = snprintf(alert_cmd + alert_cmd_offset, ALERT_CMD_OUTPUT_MAX, " %u %lu %lu", alarm, average_latency, average_loss);
+		r = snprintf(alert_cmd + alert_cmd_offset, ALERT_CMD_OUTPUT_MAX, " %u %lu %lu", alarm_on, average_latency, average_loss);
 		if (r < 0 || r >= (int) ALERT_CMD_OUTPUT_MAX)
 		{
 		    logger("error formatting alert command\n");
@@ -891,9 +891,9 @@ parse_args(
 		fatal("Invalid bind IP address %s\n", bind_arg);
 	    }
 
-	    struct sockaddr_in * bind = (struct sockaddr_in *) &bind_addr;
-	    bind->sin_family = AF_INET;
-	    bind->sin_addr = addr;
+	    struct sockaddr_in * bind4 = (struct sockaddr_in *) &bind_addr;
+	    bind4->sin_family = AF_INET;
+	    bind4->sin_addr = addr;
 	    bind_addr_len = sizeof(struct sockaddr_in);
 	}
     }
