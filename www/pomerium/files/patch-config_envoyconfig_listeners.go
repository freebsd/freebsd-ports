--- config/envoyconfig/listeners.go.orig	2026-05-05 05:20:36 UTC
+++ config/envoyconfig/listeners.go
@@ -99,10 +99,10 @@ func newListener(name, statPrefix string) *envoy_confi
 		StatPrefix:                    statPrefix,
 		PerConnectionBufferLimitBytes: wrapperspb.UInt32(listenerBufferLimit),
 
-		// SO_REUSEPORT only works properly on linux and is force-disabled by
-		// envoy on mac and windows, so we disable it explitly to avoid a
-		// noisy log message
-		EnableReusePort: wrapperspb.Bool(runtime.GOOS == "linux"),
+		// SO_REUSEPORT only works properly on linux and FreeBSD, and is
+		// force-disabled by envoy on mac and windows, so we disable it
+		// explicitly to avoid a noisy log message
+		EnableReusePort: wrapperspb.Bool(runtime.GOOS == "linux" || runtime.GOOS == "freebsd"),
 	}
 }
 
