--- mix.exs.orig	2017-01-20 23:39:44 UTC
+++ mix.exs
@@ -9,7 +9,6 @@ defmodule Joken.Mixfile do
      elixir: "~> 1.2.3 or ~> 1.3",
      description: description(),
      package: package(),
-     deps: deps(),
      consolidate_protocols: Mix.env != :test,
      test_coverage: [tool: ExCoveralls],
      name: "Joken",
