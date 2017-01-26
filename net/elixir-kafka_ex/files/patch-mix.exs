--- mix.exs.orig	2017-01-23 00:24:40 UTC
+++ mix.exs
@@ -17,7 +17,6 @@ defmodule KafkaEx.Mixfile do
       preferred_cli_env: [coveralls: :test],
       description: description(),
       package: package(),
-      deps: deps(),
       docs: [
         main: "README",
         extras: ["README.md"]
