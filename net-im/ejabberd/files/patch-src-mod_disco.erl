--- mod_disco.erl	Sun Apr 17 18:08:34 2005
+++ mod_disco.erl	Sat Apr 23 19:28:48 2005
@@ -3,12 +3,12 @@
 %%% Author  : Alexey Shchepin <alexey@sevcom.net>
 %%% Purpose : Service Discovery (JEP-0030) support
 %%% Created :  1 Jan 2003 by Alexey Shchepin <alexey@sevcom.net>
-%%% Id      : $Id: mod_disco.erl 307 2005-04-17 18:08:34Z tmallard $
+%%% Id      : $Id: mod_disco.erl 322 2005-04-19 22:19:22Z alexey $
 %%%----------------------------------------------------------------------
 
 -module(mod_disco).
 -author('alexey@sevcom.net').
--vsn('$Revision$ ').
+-vsn('$Revision: 322 $ ').
 
 -behaviour(gen_mod).
 
@@ -344,9 +344,17 @@
 
 
 get_vh_services(Host) ->
-    DotHost = "." ++ Host,
+    Hosts = lists:sort(fun(H1, H2) -> length(H1) >= length(H2) end, ?MYHOSTS),
     lists:filter(fun(H) ->
-			 lists:suffix(DotHost, H)
+			 case lists:dropwhile(
+				fun(VH) ->
+					not lists:suffix("." ++ VH, H)
+				end, Hosts) of
+			     [] ->
+				 false;
+			     [VH | _] ->
+				 VH == Host
+			 end
 		 end, ejabberd_router:dirty_get_all_routes()).
 
 get_online_vh_users(Host) ->
