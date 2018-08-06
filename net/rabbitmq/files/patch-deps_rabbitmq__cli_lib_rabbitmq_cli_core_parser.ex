--- deps/rabbitmq_cli/lib/rabbitmq/cli/core/parser.ex.orig	2018-06-14 08:10:14 UTC
+++ deps/rabbitmq_cli/lib/rabbitmq/cli/core/parser.ex
@@ -142,7 +142,12 @@ defmodule RabbitMQ.CLI.Core.Parser do
     switches = default_switches()
     aliases = default_aliases()
     {options, tail, invalid} =
-      OptionParser.parse_head(input, strict: switches, aliases: aliases)
+      OptionParser.parse_head(
+        input,
+        strict: switches,
+        aliases: aliases,
+        allow_nonexistent_atoms: true,
+      )
     norm_options = normalize_options(options, switches) |> Map.new
     {norm_options, tail, invalid}
   end
@@ -157,7 +162,8 @@ defmodule RabbitMQ.CLI.Core.Parser do
     {options, args, invalid} = OptionParser.parse(
       input,
       strict: switches,
-      aliases: aliases
+      aliases: aliases,
+      allow_nonexistent_atoms: true,
     )
     norm_options = normalize_options(options, switches) |> Map.new
     {args, norm_options, invalid}
