--- mix.exs.orig	2015-07-03 10:57:27 UTC
+++ mix.exs
@@ -18,9 +18,6 @@ defmodule WebAssembly.Mixfile do
   end
 
   defp deps, do: [
-    {:excoveralls,  "== 0.3.6",   only: :test},
-    {:ex_doc,       "~> 0.7.1",   only: :dev},
-    {:dialyze,      "== 0.1.3",   only: :dev},
   ]
 
   defp description do
