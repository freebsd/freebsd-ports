--- src/gtk2/gui/guiHtml.ml.orig	2006-05-19 20:43:31.000000000 -0300
+++ src/gtk2/gui/guiHtml.ml	2010-09-21 00:37:03.000000000 -0300
@@ -50,9 +50,13 @@
 
 let make_request url =
   let module H = Http_client in
+  let auth = match !!O.gtk_connection_http_proxy_login with
+  | "" -> None
+  | _ -> Some (!!O.gtk_connection_http_proxy_login, !!O.gtk_connection_http_proxy_password)
+  in
   let proxy =
     if !!O.gtk_connection_http_use_proxy
-      then Some (!!O.gtk_connection_http_proxy_server, !!O.gtk_connection_http_proxy_port)
+      then Some (!!O.gtk_connection_http_proxy_server, !!O.gtk_connection_http_proxy_port, auth)
       else None
   in
   let r = {
