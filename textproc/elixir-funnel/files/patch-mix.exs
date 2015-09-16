--- mix.exs.orig	2014-09-10 19:01:07 UTC
+++ mix.exs
@@ -6,10 +6,9 @@ defmodule Funnel.Mixfile do
       version: "0.4.1",
       compilers: [:elixir, :app],
       compile_path: "tmp/#{Mix.env}/funnel/ebin",
-      elixir: "~> 0.15 or 1.0.0-rc1 or 1.0.0",
+      elixir: "~> 0.15 or ~> 1.0.0",
       description: description,
-      package: package,
-      deps: deps ]
+      package: package]
   end
 
   # Configuration for the OTP application
