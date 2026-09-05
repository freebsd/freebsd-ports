--- plugins/meta/dnsname/config.go.orig	1979-11-30 00:00:00 UTC
+++ plugins/meta/dnsname/config.go
@@ -25,7 +25,7 @@ pid-file={{.PidFile}}
 domain={{.Domain}}
 expand-hosts
 pid-file={{.PidFile}}
-except-interface=lo
+except-interface=lo0
 bind-dynamic
 no-hosts
 interface={{.NetworkInterface}}
