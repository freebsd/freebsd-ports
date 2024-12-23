--- LibreNMS/Validations/WebServer.php.orig	2024-12-17 23:55:13 UTC
+++ LibreNMS/Validations/WebServer.php
@@ -45,22 +45,28 @@ class WebServer extends BaseValidation
     {
         if (! app()->runningInConsole()) {
             $url = $this->removeStandardPorts(request()->url());
-            $expected = $this->removeStandardPorts(Str::finish(Config::get('base_url'), '/') . 'validate/results');
+            $base_url = Config::get('base_url');
+            $expected = $this->removeStandardPorts(Str::finish($base_url, '/') . 'validate/results');
+            $correct_base = str_replace('/validate/results', '', $url);
 
             if ($url !== $expected) {
                 preg_match($this->host_regex, $url, $actual_host_match);
                 preg_match($this->host_regex, $expected, $expected_host_match);
                 $actual_host = $actual_host_match[1] ?? '';
                 $expected_host = $expected_host_match[1] ?? "parse failure ($expected)";
-                if ($actual_host != $expected_host) {
+
+                if ($base_url == '/' && ! str_contains($actual_host, '/')) {
+                    $validator->warn('base_url could be more specific', "lnms config:set base_url $correct_base");
+                } elseif ($actual_host != $expected_host) {
                     $nginx = Str::startsWith(request()->server->get('SERVER_SOFTWARE'), 'nginx');
                     $server_name = $nginx ? 'server_name' : 'ServerName';
                     $fix = $nginx ? "server_name $actual_host;" : "ServerName $actual_host";
                     $validator->fail("$server_name is set incorrectly for your webserver, update your webserver config. $actual_host $expected_host", $fix);
                 } else {
-                    $correct_base = str_replace('validate/results', '', $url);
                     $validator->fail('base_url is not set correctly', "lnms config:set base_url $correct_base");
                 }
+            } elseif (preg_replace('#/$#', '', \config('app.url')) !== $correct_base) {
+                $validator->fail("APP_URL is not set correctly. It should be set to $correct_base");
             }
 
             if (request()->secure() && ! \config('session.secure')) {
