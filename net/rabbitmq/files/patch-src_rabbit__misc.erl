--- src/rabbit_misc.erl.orig	2015-12-15 10:23:52 UTC
+++ src/rabbit_misc.erl
@@ -652,18 +652,7 @@ format_many(List) ->
     lists:flatten([io_lib:format(F ++ "~n", A) || {F, A} <- List]).
 
 format_stderr(Fmt, Args) ->
-    case os:type() of
-        {unix, _} ->
-            Port = open_port({fd, 0, 2}, [out]),
-            port_command(Port, io_lib:format(Fmt, Args)),
-            port_close(Port);
-        {win32, _} ->
-            %% stderr on Windows is buffered and I can't figure out a
-            %% way to trigger a fflush(stderr) in Erlang. So rather
-            %% than risk losing output we write to stdout instead,
-            %% which appears to be unbuffered.
-            io:format(Fmt, Args)
-    end,
+    io:format(standard_error, Fmt, Args),
     ok.
 
 unfold(Fun, Init) ->
