
$FreeBSD$

--- src/yaws_server.erl.orig
+++ src/yaws_server.erl
@@ -497,10 +497,9 @@
 	{'EXIT', Pid, _} ->
 	    case get(top) of
 		Pid -> 
-		    error_logger:format("Top proc died, terminate gserv",[]),
 		    {links, Ls} = process_info(self(), links),
 		    foreach(fun(X) -> unlink(X), exit(X, shutdown) end, Ls),
-		    exit(noserver);
+		    exit(normal);
 		_ ->
 		    gserv_loop(GS, Ready, Rnum, Last)
 	    end;
