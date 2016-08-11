--- mix.exs.orig	2016-07-07 13:08:02 UTC
+++ mix.exs
@@ -7,7 +7,6 @@ defmodule Phoenix.Mixfile do
     [app: :phoenix,
      version: @version,
      elixir: "~> 1.2",
-     deps: deps(),
      package: package(),
 
      # Because we define protocols on the fly to test
