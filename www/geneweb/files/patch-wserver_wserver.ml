--- wserver/wserver.ml.orig	2024-02-11 18:29:57 UTC
+++ wserver/wserver.ml
@@ -263,7 +263,7 @@ value timeout tmout spid _ =
     else ();
     let _ = Unix.waitpid [] pid in ();
     exit 2
-  }
+  };
 END;
 
 value get_request_and_content strm =
@@ -363,7 +363,7 @@ value copy_what_necessary t oc =
          })
   in
   let _ = get_request_and_content strm in
-  ()
+  ();
 END;
 
 value rec list_remove x =
@@ -372,13 +372,13 @@ value rec list_remove x =
   | [y :: l] -> if x = y then l else [y :: list_remove x l] ]
 ;
 
-IFDEF NOFORK THEN declare end ELSE
-value pids = ref []
+IFDEF NOFORK THEN declare end; ELSE
+value pids = ref [];
 END;
-IFDEF NOFORK THEN declare end ELSE
-value cleanup_verbose = ref True
+IFDEF NOFORK THEN declare end; ELSE
+value cleanup_verbose = ref True;
 END;
-IFDEF NOFORK THEN declare end ELSE
+IFDEF NOFORK THEN declare end; ELSE
 value cleanup_sons () =
   List.iter
     (fun p ->
@@ -402,10 +402,10 @@ value cleanup_sons () =
        in
        if pid = 0 then ()
        else pids.val := list_remove pid pids.val)
-     pids.val
+     pids.val;
 END;
 
-IFDEF NOFORK THEN declare end ELSE
+IFDEF NOFORK THEN declare end; ELSE
 value wait_available max_clients s =
   match max_clients with
   [ Some m ->
@@ -434,7 +434,7 @@ eprintf "*** %02d/%02d/%4d %02d:%02d:%02d %d process(e
           else ();
         };
       }
-  | None -> () ]
+  | None -> () ];
 END;
 
 value wait_and_compact s =
