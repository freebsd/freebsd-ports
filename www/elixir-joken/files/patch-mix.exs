--- mix.exs.orig	2019-05-27 14:48:40 UTC
+++ mix.exs
@@ -14,7 +14,6 @@ defmodule Joken.Mixfile do
       consolidate_protocols: Mix.env() != :test,
       description: description(),
       package: package(),
-      deps: deps(),
       source_ref: "v#{@version}",
       source_url: "https://github.com/joken-elixir/joken",
       docs: docs_config(),
