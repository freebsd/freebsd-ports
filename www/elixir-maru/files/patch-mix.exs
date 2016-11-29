--- mix.exs.orig	2015-09-20 11:27:01 UTC
+++ mix.exs
@@ -7,7 +7,6 @@ defmodule Maru.Mixfile do
       elixir: "~> 1.0",
       build_embedded: Mix.env == :prod,
       start_permanent: Mix.env == :prod,
-      deps: deps(),
       description: "REST-like API micro-framework for elixir inspired by grape.",
       source_url: "https://github.com/falood/maru",
       package: package,
