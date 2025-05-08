--- froxlor/lib/Froxlor/Cron/Traffic/TrafficCron.php.orig	2025-05-07 03:27:51 UTC
+++ froxlor/lib/Froxlor/Cron/Traffic/TrafficCron.php
@@ -861,7 +861,7 @@ class TrafficCron extends FroxlorCron
 			// the default selection is 'current',
 			// so link the latest dir to it
 			$new_current = FileDir::makeCorrectFile($outputdir . '/current');
-			FileDir::safe_exec('ln -fTs ' . escapeshellarg($staticOutputdir) . ' ' . escapeshellarg($new_current));
+			FileDir::safe_exec('ln -fFs ' . escapeshellarg($staticOutputdir) . ' ' . escapeshellarg($new_current));
 
 			// statistics file looks like: 'awstats[month][year].[domain].txt'
 			$file = FileDir::makeCorrectFile($outputdir . '/awstats' . date('mY', time()) . '.' . $domain . '.txt');
