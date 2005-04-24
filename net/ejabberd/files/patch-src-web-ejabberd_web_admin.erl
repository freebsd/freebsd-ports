--- web/ejabberd_web_admin.erl	Mon Apr 18 20:03:07 2005
+++ web/ejabberd_web_admin.erl	Sat Apr 23 19:28:48 2005
@@ -3,7 +3,7 @@
 %%% Author  : Alexey Shchepin <alexey@sevcom.net>
 %%% Purpose : Administration web interface
 %%% Created :  9 Apr 2004 by Alexey Shchepin <alexey@sevcom.net>
-%%% Id      : $Id: ejabberd_web_admin.erl 316 2005-04-18 20:03:07Z alexey $
+%%% Id      : $Id: ejabberd_web_admin.erl 323 2005-04-19 23:10:22Z alexey $
 %%%----------------------------------------------------------------------
 %%% Copyright (c) 2004-2005 Alexey Shchepin
 %%% Copyright (c) 2004-2005 Process One
@@ -11,7 +11,7 @@
 
 -module(ejabberd_web_admin).
 -author('alexey@sevcom.net').
--vsn('$Revision$ ').
+-vsn('$Revision: 323 $ ').
 
 %% External exports
 -export([process_admin/1]).
@@ -1143,23 +1143,26 @@
 list_users_parse_query(Query) ->
     case lists:keysearch("addnewuser", 1, Query) of
 	{value, _} ->
-	    {value, {_, User}} =
+	    {value, {_, JIDString}} =
 		lists:keysearch("newusername", 1, Query),
 	    {value, {_, Password}} =
 		lists:keysearch("newuserpassword", 1, Query),
-	    case jlib:nodeprep(User) of
+	    case jlib:string_to_jid(JIDString) of
 		error ->
 		    error;
-		"" ->
-		    error;
-		_ ->
-		    ejabberd_auth:try_register(User, Password),
-		    ok
+		#jid{user = User, server = Server} ->
+		    case ejabberd_auth:try_register(User, Server, Password) of
+			{error, _Reason} ->
+			    error;
+			_ ->
+			    ok
+		    end
 	    end;
 	false ->
 	    nothing
     end.
 
+
 list_users_in_diapason(Diap, Lang) ->
     Users = ejabberd_auth:dirty_get_registered_users(),
     SUsers = lists:sort([{S, U} || {U, S} <- Users]),
@@ -1181,7 +1184,8 @@
 	       fun(SU = {Server, User}) ->
 		       US = {User, Server},
 		       QueueLen = length(mnesia:dirty_read({offline_msg, US})),
-		       FQueueLen = [?AC(Prefix ++ "user/" ++ User ++ "/queue/",
+		       FQueueLen = [?AC(Prefix ++ "user/" ++
+					User ++ "@" ++ Server ++ "/queue/",
 					integer_to_list(QueueLen))],
 		       FLast =
 			   case ejabberd_sm:get_user_resources(User, Server) of
