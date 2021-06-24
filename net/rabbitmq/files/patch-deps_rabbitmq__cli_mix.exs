--- deps/rabbitmq_cli/mix.exs.orig	2021-06-24 22:46:46 UTC
+++ deps/rabbitmq_cli/mix.exs
@@ -11,7 +11,7 @@ defmodule RabbitMQCtl.MixfileBase do
     [
       app: :rabbitmqctl,
       version: "3.8.0-dev",
-      elixir: ">= 1.10.4 and < 1.13.0",
+      elixir: ">= 1.10.4",
       build_embedded: Mix.env == :prod,
       start_permanent: Mix.env == :prod,
       escript: [main_module: RabbitMQCtl,
