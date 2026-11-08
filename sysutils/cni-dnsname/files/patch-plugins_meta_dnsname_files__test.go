--- plugins/meta/dnsname/files_test.go.orig	1979-11-30 00:00:00 UTC
+++ plugins/meta/dnsname/files_test.go
@@ -14,7 +14,7 @@ pid-file=/run/containers/cni/dnsname/cni0/pidfile
 domain=foobar.org
 expand-hosts
 pid-file=/run/containers/cni/dnsname/cni0/pidfile
-except-interface=lo
+except-interface=lo0
 bind-dynamic
 no-hosts
 interface=cni0
