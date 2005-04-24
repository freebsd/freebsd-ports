--- jd2ejd.erl	Sun Apr 17 18:08:34 2005
+++ jd2ejd.erl	Sat Apr 23 19:28:48 2005
@@ -3,12 +3,12 @@
 %%% Author  : Alexey Shchepin <alexey@sevcom.net>
 %%% Purpose : Import of jabberd1.4 user spool file
 %%% Created :  2 Feb 2003 by Alexey Shchepin <alexey@sevcom.net>
-%%% Id      : $Id: jd2ejd.erl 307 2005-04-17 18:08:34Z tmallard $
+%%% Id      : $Id: jd2ejd.erl 324 2005-04-21 14:06:15Z alexey $
 %%%----------------------------------------------------------------------
 
 -module(jd2ejd).
 -author('alexey@sevcom.net').
--vsn('$Revision$ ').
+-vsn('$Revision: 324 $ ').
 
 %% External exports
 -export([import_file/1,
@@ -87,8 +87,9 @@
     end.
 
 
-xdb_data(User, Server, El) ->
-    {xmlelement, _Name, Attrs, _Els} = El,
+xdb_data(User, Server, {xmlcdata, _CData}) ->
+    ok;
+xdb_data(User, Server, {xmlelement, _Name, Attrs, _Els} = El) ->
     From = jlib:make_jid(User, Server, ""),
     case xml:get_attr_s("xmlns", Attrs) of
 	?NS_AUTH ->
