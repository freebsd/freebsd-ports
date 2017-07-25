--- mix.exs.orig	2017-07-15 13:02:36 UTC
+++ mix.exs
@@ -16,7 +16,6 @@ defmodule Comeonin.Mixfile do
      package: package(),
      source_url: "https://github.com/riverrun/comeonin",
      compilers: [:elixir_make] ++ Mix.compilers,
-     deps: deps(),
      dialyzer: [plt_file: ".dialyzer/local.plt", remove_defaults: [:unknown]]]
   end
 
