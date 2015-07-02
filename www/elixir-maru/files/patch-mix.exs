--- mix.exs.orig	2015-07-02 12:23:34 UTC
+++ mix.exs
@@ -19,10 +19,7 @@ defmodule Maru.Mixfile do
   end
 
   defp deps do
-    [ { :cowboy, "~> 1.0.0" },
-      { :plug,   "~> 0.12.2" },
-      { :poison, "~> 1.4.0" },
-    ]
+    []
   end
 
   defp package do
