--- mix.exs.orig	2015-07-01 12:43:24 UTC
+++ mix.exs
@@ -29,18 +29,7 @@ defmodule Phoenix.Mixfile do
   end
 
   defp deps do
-    [{:cowboy, "~> 1.0", optional: true},
-     {:plug, "~> 0.13 or ~> 1.0"},
-     {:poison, "~> 1.3"},
-
-     # Docs dependencies
-     {:earmark, "~> 0.1", only: :docs},
-     {:ex_doc, "~> 0.7.1", only: :docs},
-     {:inch_ex, "~> 0.2", only: :docs},
-
-     # Test dependencies
-     {:phoenix_html, "~> 1.2", only: :test},
-     {:websocket_client, github: "jeremyong/websocket_client", only: :test}]
+    []
   end
 
   defp package do
