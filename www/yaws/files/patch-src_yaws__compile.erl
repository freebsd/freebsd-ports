
$FreeBSD$

--- src/yaws_compile.erl.orig
+++ src/yaws_compile.erl
@@ -311,7 +311,7 @@
     ?Debug("Writing outout file~s~n", [OutFile]),
     {ok, Out} = file:open(OutFile, [write]),
     ok = io:format(Out, "-module(\'~s\').~n-export([out/1]).~n~n", [Module]),
-    ok = io:format(Out, "-yawsfile('" ++ get(yfile) ++ "').~n",[]),
+    ok = io:format(Out, "-yawsfile(\'~s\').~n",[get(yfile)]),
     io:format(Out, "%%~n%% code at line ~w from file ~s~n%%~n",
               [Line, C#comp.infile]),
     io:format(Out, "-import(yaws_api, [f/2, fl/1, postvar/2, queryvar/2])."
