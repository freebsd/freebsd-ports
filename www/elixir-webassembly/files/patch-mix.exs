--- mix.exs.orig	2015-10-14 03:03:56 UTC
+++ mix.exs
@@ -5,8 +5,6 @@ defmodule WebAssembly.Mixfile do
     [app: :webassembly,
      docs: [main: WebAssembly],
      version: "0.6.0",
-     elixir: "~> 1.0",
-     deps: deps,
      description: description,
      package: package,
      test_coverage: [tool: ExCoveralls]]
