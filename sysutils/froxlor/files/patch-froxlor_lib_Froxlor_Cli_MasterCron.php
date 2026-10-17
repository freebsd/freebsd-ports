--- froxlor/lib/Froxlor/Cli/MasterCron.php.orig	2026-10-04 07:11:11 UTC
+++ froxlor/lib/Froxlor/Cli/MasterCron.php
@@ -219,7 +219,7 @@ final class MasterCron extends CliCommand
 	private function lockJob(string $job, OutputInterface $output): bool
 	{
 
-		$this->lockFile = '/run/lock/froxlor_' . $job . '.lock';
+		$this->lockFile = '/var/run/froxlor_' . $job . '.lock';
 
 		if (file_exists($this->lockFile)) {
 			$jobinfo = json_decode(file_get_contents($this->lockFile), true);
