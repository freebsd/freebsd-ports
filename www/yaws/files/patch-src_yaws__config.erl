
$FreeBSD$

--- src/yaws_config.erl.orig	Fri Apr 25 10:02:59 2003
+++ src/yaws_config.erl	Fri May 30 12:31:50 2003
@@ -9,6 +9,7 @@
 -author('klacke@bluetail.com').
 
 
+-define(CONFIGURATION_FILE, "!!PREFIX!!/etc/yaws.conf").
 
 
 -include_lib("yaws/include/yaws.hrl").
@@ -29,11 +30,11 @@
 paths() ->
     case yaws:getuid() of
 	{ok, "0"} ->    %% root 
-	    ["/etc/yaws.conf"];
+	    [?CONFIGURATION_FILE];
 	_ -> %% developer
 	    [filename:join([os:getenv("HOME"), "yaws.conf"]),
 	     "./yaws.conf", 
-	     "/etc/yaws.conf"]
+	     ?CONFIGURATION_FILE]
     end.
 
 
