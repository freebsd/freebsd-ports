--- mix.exs.orig	2015-12-17 02:11:33 UTC
+++ mix.exs
@@ -120,7 +120,6 @@ defmodule Comeonin.Mixfile do
       package: package,
       source_url: "https://github.com/elixircnx/comeonin",
       compilers: [:comeonin] ++ Mix.compilers,
-      deps: deps
     ]
   end
 
