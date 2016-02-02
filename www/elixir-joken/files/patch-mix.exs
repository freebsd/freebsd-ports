--- mix.exs.orig	2016-02-01 23:55:46 UTC
+++ mix.exs
@@ -7,7 +7,6 @@ defmodule Joken.Mixfile do
      elixir: "~> 1.0",
      description: description,
      package: package,
-     deps: deps,
      consolidate_protocols: Mix.env != :test]
   end
 
