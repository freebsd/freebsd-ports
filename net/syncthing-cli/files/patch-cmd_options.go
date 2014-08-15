--- cmd_options.go.orig	2014-08-14 20:00:24.000000000 +0000
+++ cmd_options.go	2014-08-14 20:00:35.000000000 +0000
@@ -46,7 +46,6 @@
 	fmt.Fprintln(writer, "Local discovery port:\t", cfg.LocalAnnPort, "\t(localannport)")
 
 	fmt.Fprintln(writer, "Maximum outstanding requests:\t", cfg.ParallelRequests, "\t(requests)")
-	fmt.Fprintln(writer, "Maximum file change rate in KiB/s:\t", cfg.MaxChangeKbps, "\t(maxchange)")
 	fmt.Fprintln(writer, "Outgoing rate limit in KiB/s:\t", cfg.MaxSendKbps, "\t(maxsend)")
 	fmt.Fprintln(writer, "Rescan interval in seconds:\t", cfg.RescanIntervalS, "\t(rescan)")
 	fmt.Fprintln(writer, "Reconnect interval in seconds:\t", cfg.ReconnectIntervalS, "\t(reconnect)")
@@ -85,8 +84,6 @@
 		fmt.Println(cfg.ParallelRequests)
 	case "maxsend":
 		fmt.Println(cfg.MaxSendKbps)
-	case "maxchange":
-		fmt.Println(cfg.MaxChangeKbps)
 	case "rescan":
 		fmt.Println(cfg.RescanIntervalS)
 	case "reconnect":
@@ -134,8 +131,6 @@
 		config.Options.ParallelRequests = parseUint(val)
 	case "maxsend":
 		config.Options.MaxSendKbps = parseUint(val)
-	case "maxchange":
-		config.Options.MaxChangeKbps = parseUint(val)
 	case "rescan":
 		config.Options.RescanIntervalS = parseUint(val)
 	case "reconnect":
