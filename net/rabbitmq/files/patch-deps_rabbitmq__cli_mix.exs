--- deps/rabbitmq_cli/mix.exs.orig	2019-05-17 13:13:20 UTC
+++ deps/rabbitmq_cli/mix.exs
@@ -20,7 +20,7 @@ defmodule RabbitMQCtl.MixfileBase do
     [
       app: :rabbitmqctl,
       version: "3.7.0-dev",
-      elixir: ">= 1.6.6 and < 1.9.0",
+      elixir: ">= 1.6.6 and < 1.10.0",
       build_embedded: Mix.env == :prod,
       start_permanent: Mix.env == :prod,
       escript: [main_module: RabbitMQCtl,
