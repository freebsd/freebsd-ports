--- mix.exs.orig	2021-08-16 02:01:52 UTC
+++ mix.exs
@@ -15,7 +15,6 @@ defmodule Joken.Mixfile do
       consolidate_protocols: Mix.env() != :test,
       description: description(),
       package: package(),
-      deps: deps(),
       docs: docs(),
       dialyzer: [plt_add_deps: :apps_direct, plt_add_apps: [:jason]],
       test_coverage: [tool: ExCoveralls],
