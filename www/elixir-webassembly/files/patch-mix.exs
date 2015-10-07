--- mix.exs.orig	2015-09-26 08:21:42 UTC
+++ mix.exs
@@ -5,8 +5,6 @@ defmodule WebAssembly.Mixfile do
     [app: :webassembly,
      docs: [main: WebAssembly],
      version: "0.5.1",
-     elixir: "~> 1.0.0",
-     deps: deps,
      description: description,
      package: package,
      test_coverage: [tool: ExCoveralls]]
