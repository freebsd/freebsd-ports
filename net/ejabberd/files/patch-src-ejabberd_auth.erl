--- ejabberd_auth.erl	Sun Apr 17 18:08:34 2005
+++ ejabberd_auth.erl	Sat Apr 23 19:28:48 2005
@@ -3,12 +3,12 @@
 %%% Author  : Alexey Shchepin <alexey@sevcom.net>
 %%% Purpose : Authentification
 %%% Created : 23 Nov 2002 by Alexey Shchepin <alexey@sevcom.net>
-%%% Id      : $Id: ejabberd_auth.erl 307 2005-04-17 18:08:34Z tmallard $
+%%% Id      : $Id: ejabberd_auth.erl 323 2005-04-19 23:10:22Z alexey $
 %%%----------------------------------------------------------------------
 
 -module(ejabberd_auth).
 -author('alexey@sevcom.net').
--vsn('$Revision$ ').
+-vsn('$Revision: 323 $ ').
 
 %% External exports
 -export([start/0,
@@ -26,6 +26,8 @@
 	 plain_password_required/0
 	]).
 
+-include("ejabberd.hrl").
+
 %%%----------------------------------------------------------------------
 %%% API
 %%%----------------------------------------------------------------------
@@ -45,7 +47,12 @@
     (auth_module()):set_password(User, Server, Password).
 
 try_register(User, Server, Password) ->
-    (auth_module()):try_register(User, Server, Password).
+    case lists:member(jlib:nameprep(Server), ?MYHOSTS) of
+	true ->
+	    (auth_module()):try_register(User, Server, Password);
+	false ->
+	    {error, not_allowed}
+    end.
 
 dirty_get_registered_users() ->
     (auth_module()):dirty_get_registered_users().
