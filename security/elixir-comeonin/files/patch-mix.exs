--- mix.exs.orig	2016-12-15 12:02:47 UTC
+++ mix.exs
@@ -16,7 +16,6 @@ defmodule Comeonin.Mixfile do
      package: package(),
      source_url: "https://github.com/riverrun/comeonin",
      compilers: [:elixir_make] ++ Mix.compilers,
-     deps: deps(),
      dialyzer: [plt_file: ".dialyzer/local.plt"]]
   end
 
