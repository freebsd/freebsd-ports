--- src/dag.ml.orig	2016-11-06 14:21:56 UTC
+++ src/dag.ml
@@ -48,7 +48,7 @@ value tag_dag d =
        })
     d
 ;
-end END;
+end; END;
 
 (* input dag *)
 
@@ -308,7 +308,7 @@ value print_table conf hts =
     end_centered conf;
   }
 ;
-end END;
+end; END;
 
 (*
  * Print without HTML table tags: using <pre>
@@ -837,7 +837,7 @@ value print_html_table conf hts =
     else print_table conf hts
   }
 ;
-end END;
+end; END;
 
 value make_tree_hts conf base elem_txt vbar_txt invert set spl d =
   let no_group = p_getenv conf.env "nogroup" = Some "on" in
@@ -1026,7 +1026,7 @@ value print_dag_page conf base page_title hts next_txt
     Hutil.trailer conf
   }
 ;
-end END;
+end; END;
 
 (* *)
 
@@ -1275,11 +1275,11 @@ value old_print_slices_menu_or_dag_page conf base page
   if p_getenv conf.env "slices" = Some "on" then print_slices_menu conf hts
   else print_dag_page conf base page_title hts next_txt
 ;
-end ELSE declare
+end; ELSE declare
 value old_print_slices_menu_or_dag_page conf base page_title hts next_txt =
   incorrect_request conf
 ;
-end END;
+end; END;
 
 value print_slices_menu_or_dag_page conf base page_title hts next_txt =
 (**)
