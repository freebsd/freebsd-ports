--- go.mod.orig	2026-10-30 16:43:29 UTC
+++ go.mod
@@ -98,9 +98,8 @@ replace github.com/urfave/cli/v2 => github.com/ipostel
 
 replace github.com/urfave/cli/v2 => github.com/ipostelnik/cli/v2 v2.3.1-0.20210324024421-b6ea8234fe3d
 
-// Avoid 'CVE-2022-21698'
-replace github.com/prometheus/golang_client => github.com/prometheus/golang_client v1.12.1
-
 replace gopkg.in/yaml.v3 => gopkg.in/yaml.v3 v3.0.1
 
 replace github.com/quic-go/quic-go => github.com/chungthuang/quic-go v0.45.1-0.20260529212404-a9fddf436fc4 // This fork is based on quic-go v0.59.1
+
+replace nhooyr.io/websocket => github.com/coder/websocket v1.8.7
