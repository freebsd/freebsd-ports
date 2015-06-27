--- src/xmlrpc_decode.erl.orig	2003-04-23 19:06:45 UTC
+++ src/xmlrpc_decode.erl
@@ -28,7 +28,7 @@
 -author('jocke@gleipnir.com').
 -export([payload/1]).
 
--include("xmerl.hrl").
+-include_lib("xmerl/include/xmerl.hrl").
 
 payload(Payload) ->
     case xmerl_scan:string(Payload) of
