--- mix.exs.orig	2015-07-02 15:23:09 UTC
+++ mix.exs
@@ -30,8 +30,6 @@ defmodule PhoenixEcto.Mixfile do
   end
 
   defp deps do
-    [{:phoenix_html, "~> 1.0", optional: true},
-     {:poison, "~> 1.3", optional: true},
-     {:ecto, "~> 0.12"}]
+    []
   end
 end
