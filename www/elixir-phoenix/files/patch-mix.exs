--- mix.exs.orig	2015-12-26 20:08:46 UTC
+++ mix.exs
@@ -7,7 +7,6 @@ defmodule Phoenix.Mixfile do
     [app: :phoenix,
      version: @version,
      elixir: "~> 1.0.2 or ~> 1.1",
-     deps: deps,
      package: package,
 
      # Because we define protocols on the fly to test
