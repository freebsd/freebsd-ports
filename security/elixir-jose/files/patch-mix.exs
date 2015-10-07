--- mix.exs.orig	2015-09-29 13:27:51 UTC
+++ mix.exs
@@ -8,7 +8,6 @@ defmodule JOSE.Mixfile do
      erlc_options: erlc_options,
      build_embedded: Mix.env == :prod,
      start_permanent: Mix.env == :prod,
-     deps: deps,
      name: "JOSE",
      source_url: "https://github.com/potatosalad/erlang-jose",
      docs: fn ->
