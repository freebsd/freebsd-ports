--- mix.exs.orig	2015-07-13 13:00:06 UTC
+++ mix.exs
@@ -4,10 +4,8 @@ defmodule Joken.Mixfile do
   def project do
     [app: :joken,
      version: "0.15.0",
-     elixir: "~> 1.0.0",
      description: description,
-     package: package,
-     deps: deps]
+     package: package]
   end
 
   def application do
