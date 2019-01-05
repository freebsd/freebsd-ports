--- mix.exs.orig	2018-12-31 15:47:40 UTC
+++ mix.exs
@@ -9,7 +9,6 @@ defmodule JOSE.Mixfile do
       erlc_options: erlc_options(),
       build_embedded: Mix.env() == :prod,
       start_permanent: Mix.env() == :prod,
-      deps: deps(),
       name: "JOSE",
       source_url: "https://github.com/potatosalad/erlang-jose",
       docs: fn ->
