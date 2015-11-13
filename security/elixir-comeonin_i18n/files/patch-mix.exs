--- mix.exs.orig	2015-11-12 14:00:09 UTC
+++ mix.exs
@@ -15,8 +15,7 @@ defmodule ComeoninI18n.Mixfile do
      description: @description,
      package: package,
      source_url: "https://github.com/riverrun/comeonin_i18n",
-     compilers: [:gettext] ++ Mix.compilers,
-     deps: deps]
+     compilers: [:gettext] ++ Mix.compilers]
   end
 
   def application do
