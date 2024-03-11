--- src/date.ml.orig	2024-02-11 18:32:01 UTC
+++ src/date.ml
@@ -1185,7 +1185,7 @@ value old_print_calendar conf base =
     trailer conf;
   }
 ;
-end END;
+end; END;
 
 (* *)
 
@@ -1241,7 +1241,7 @@ value print_calendar conf base =
     (fun _ -> Templ.eval_transl conf) (fun _ -> raise Not_found)
     get_vother set_vother (print_foreach conf) [] (eval_julian_day conf)
 ;
-end ELSE declare
+end; ELSE declare
 value print_calendar conf base =
   Hutil.interp conf base "calendar"
     {Templ.eval_var = eval_var conf;
@@ -1251,4 +1251,4 @@ value print_calendar conf base =
      Templ.print_foreach = print_foreach conf}
     [] (eval_julian_day conf)
 ;
-end END;
+end; END;
