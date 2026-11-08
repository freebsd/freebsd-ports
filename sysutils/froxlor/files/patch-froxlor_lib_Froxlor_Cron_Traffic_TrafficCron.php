--- froxlor/lib/Froxlor/Cron/Traffic/TrafficCron.php.orig	2026-10-04 07:11:11 UTC
+++ froxlor/lib/Froxlor/Cron/Traffic/TrafficCron.php
@@ -901,7 +901,7 @@ class TrafficCron extends FroxlorCron
 				FroxlorLogger::getInstanceOf()->logAction(FroxlorLogger::CRON_ACTION, LOG_ERR, 'traffic::awstats: outputdir for domain "' . $domain . '" is unsafe, skipping: ' . $e->getMessage());
 				return $returnval;
 			}
-			FileDir::safe_exec('ln -fTs ' . escapeshellarg($staticOutputdir) . ' ' . escapeshellarg($new_current));
+			FileDir::safe_exec('ln -fFs ' . escapeshellarg($staticOutputdir) . ' ' . escapeshellarg($new_current));
 
 			// statistics file looks like: 'awstats[month][year].[domain].txt'
 			try {
