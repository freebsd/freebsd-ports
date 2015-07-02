--- mix.exs.orig	2015-07-02 21:09:21 UTC
+++ mix.exs
@@ -11,8 +11,7 @@ defmodule ExDoc.Mixfile do
   end
 
   defp deps do
-    [{:earmark, "~> 0.1.17 or ~> 0.2", optional: true},
-     {:markdown, github: "devinus/markdown", only: [:test]}]
+    []
   end
 
   defp aliases do
