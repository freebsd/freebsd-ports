--- src/gwd.ml.orig	2024-02-11 19:03:33 UTC
+++ src/gwd.ml
@@ -27,7 +27,7 @@ IFDEF UNIX THEN
   [Open_wronly; Open_append; Open_creat; Open_text; Open_nonblock]
 ;
 IFDEF UNIX THEN
-value max_clients = ref None
+value max_clients = ref None;
 END;
 value robot_xcl = ref None;
 value auth_file = ref "";
@@ -1749,7 +1749,7 @@ IFDEF SYS_COMMAND THEN
 ;
 
 IFDEF SYS_COMMAND THEN
-value wserver_auto_call = ref False
+value wserver_auto_call = ref False;
 END;
 
 value geneweb_server () =
@@ -1809,7 +1809,7 @@ value cgi_timeout tmout _ =
     Wserver.wprint "</body>\n";
     Wserver.wflush ();
     exit 0;
-  }
+  };
 END;
 
 IFDEF UNIX THEN
@@ -1818,7 +1818,7 @@ value manage_cgi_timeout tmout =
     let _ = Sys.signal Sys.sigalrm (Sys.Signal_handle (cgi_timeout tmout)) in
     let _ = Unix.alarm tmout in
     ()
-  else ()
+  else ();
 END;
 
 value geneweb_cgi addr script_name contents =
