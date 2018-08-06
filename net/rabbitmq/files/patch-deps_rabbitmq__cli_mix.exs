--- deps/rabbitmq_cli/mix.exs.orig	2018-06-14 08:10:14 UTC
+++ deps/rabbitmq_cli/mix.exs
@@ -19,8 +19,8 @@ defmodule RabbitMQCtl.MixfileBase do
   def project do
     [
       app: :rabbitmqctl,
-      version: "3.7.5",
-      elixir: "~> 1.6.0",
+      version: "3.7.8",
+      elixir: ">= 1.6.6 and < 1.8.0",
       build_embedded: Mix.env == :prod,
       start_permanent: Mix.env == :prod,
       escript: [main_module: RabbitMQCtl,
