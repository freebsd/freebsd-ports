--- mix.exs.orig	2016-09-21 07:51:15 UTC
+++ mix.exs
@@ -13,8 +13,7 @@ defmodule UUID.Mixfile do
             source_ref: "v#{@version}"],
      source_url: "https://github.com/zyro/elixir-uuid",
      description: description(),
-     package: package(),
-     deps: deps()]
+     package: package()]
   end
 
   # Application configuration.
