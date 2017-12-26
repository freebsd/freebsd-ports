--- deps/fs/src/sys/kqueue.erl.orig	2017-12-14 20:07:47 UTC
+++ deps/fs/src/sys/kqueue.erl
@@ -9,4 +9,4 @@ line_to_event(Line) ->
 find_executable() -> fs:find_executable("kqueue", "deps/fs/priv/kqueue").
 start_port(Path, Cwd) ->
     erlang:open_port({spawn_executable, find_executable()},
-        [stream, exit_status, {line, 16384}, {args, Path}, {cd, Cwd}]).
+        [stream, exit_status, {line, 16384}, {args, [Path]}, {cd, Cwd}]).
