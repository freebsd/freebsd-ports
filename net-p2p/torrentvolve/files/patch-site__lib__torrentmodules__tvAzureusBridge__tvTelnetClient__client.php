--- ./site/lib/torrentmodules/tvAzureusBridge/tvTelnetClient/client.php.orig	Tue Jan  2 07:14:20 2007
+++ ./site/lib/torrentmodules/tvAzureusBridge/tvTelnetClient/client.php	Sun Apr 22 18:57:45 2007
@@ -74,10 +74,10 @@
 	public function startLocalServer() {
 
 		$path = $this->appPath . '../azureusServer';
-		$command = 'java -Dazureus.config.path="' . $path . '" -jar "' . $path . '/Azureus2.jar" --ui=telnet';
+		$command = 'env JAVA_VERSION=1.5+ java -Dazureus.config.path="' . $path . '" -jar "' . $path . '/Azureus2.jar" --ui=telnet';
 
 		if (strtoupper(substr(PHP_OS, 0, 3) == 'WIN')) popen('start /D"' . $path . '" ' . $command, 'w');
 		else exec("$command > /dev/null 2>&1 &");
 	}
 }
-?>
\ No newline at end of file
+?>
