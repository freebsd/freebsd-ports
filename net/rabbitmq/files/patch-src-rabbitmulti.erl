--- src/rabbit_multi.erl.orig	2010-08-31 18:06:58.000000000 -0400
+++ src/rabbit_multi.erl	2010-08-31 18:07:09.000000000 -0400
@@ -303,7 +303,7 @@
 is_dead(Pid) ->
     PidS = integer_to_list(Pid),
     with_os([{unix, fun () ->
-                            Res = os:cmd("ps --no-headers --pid " ++ PidS),
+                            Res = os:cmd("ps " ++ PidS ++ " |grep -v PID"),
                             Res == ""
                     end},
              {win32, fun () ->
