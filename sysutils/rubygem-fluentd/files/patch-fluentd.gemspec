--- fluentd.gemspec.orig	2025-08-04 14:45:32.893843000 +0200
+++ fluentd.gemspec	2025-08-04 14:45:43.993159000 +0200
@@ -36,8 +36,6 @@
   s.add_runtime_dependency(%q<zstd-ruby>.freeze, ["~> 1.5".freeze])
   s.add_runtime_dependency(%q<uri>.freeze, ["~> 1.0".freeze])
   s.add_runtime_dependency(%q<async-http>.freeze, ["~> 0.86".freeze])
-  s.add_runtime_dependency(%q<io-event>.freeze, ["< 1.11.0".freeze])
-  s.add_runtime_dependency(%q<io-stream>.freeze, ["< 0.8.0".freeze])
   s.add_runtime_dependency(%q<base64>.freeze, ["~> 0.2".freeze])
   s.add_runtime_dependency(%q<csv>.freeze, ["~> 3.2".freeze])
   s.add_runtime_dependency(%q<drb>.freeze, ["~> 2.2".freeze])
