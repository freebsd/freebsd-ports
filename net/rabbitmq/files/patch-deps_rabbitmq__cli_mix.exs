--- deps/rabbitmq_cli/mix.exs.orig	2021-06-23 10:54:40 UTC
+++ deps/rabbitmq_cli/mix.exs
@@ -20,7 +20,7 @@ defmodule RabbitMQCtl.MixfileBase do
     [
       app: :rabbitmqctl,
       version: "3.8.0-dev",
-      elixir: ">= 1.7.0 and < 1.11.0",
+      elixir: ">= 1.7.0",
       build_embedded: Mix.env == :prod,
       start_permanent: Mix.env == :prod,
       escript: [main_module: RabbitMQCtl,
