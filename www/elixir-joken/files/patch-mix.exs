--- mix.exs.orig	2016-03-28 15:07:12 UTC
+++ mix.exs
@@ -9,7 +9,6 @@ defmodule Joken.Mixfile do
      elixir: "~> 1.0",
      description: description,
      package: package,
-     deps: deps,
      consolidate_protocols: Mix.env != :test,
      test_coverage: [tool: ExCoveralls],
      name: "Joken",
