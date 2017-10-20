--- mix.exs.orig	2017-10-11 12:57:07 UTC
+++ mix.exs
@@ -10,7 +10,6 @@ defmodule Phoenix.Mixfile do
       app: :phoenix,
       version: @version,
       elixir: "~> 1.3",
-      deps: deps(),
       package: package(),
       preferred_cli_env: [docs: :docs],
 
