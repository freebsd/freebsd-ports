--- mix.exs.orig	2015-07-02 15:30:23 UTC
+++ mix.exs
@@ -20,10 +20,6 @@ defmodule PhoenixHtml.Mixfile do
   end
 
   defp deps do
-    [{:plug, ">= 0.12.2 and < 2.0.0"},
-
-     # Docs dependencies
-     {:earmark, "~> 0.1", only: :docs},
-     {:ex_doc, "~> 0.7.1", only: :docs}]
+    []
   end
 end
