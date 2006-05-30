--- tools/zoggy/pa_zog.ml.orig	Wed Aug  4 20:39:32 2004
+++ tools/zoggy/pa_zog.ml	Thu Apr 20 02:41:38 2006
@@ -49,7 +49,7 @@
 let parse_string loc =
   function
     "false" -> 
-      let loc = 
+      let _loc = 
 	(
 	 { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	 { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -57,7 +57,7 @@
       in
       <:expr< False >>
   | "true" ->
-      let loc = 
+      let _loc = 
 	(
 	 { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	 { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -108,7 +108,7 @@
     parse_prop_value p
   with
     Not_found -> 
-      	let loc = 
+      	let _loc = 
 	  (
 	   { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	   { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -242,7 +242,7 @@
       (_, n, _, _) -> n
 
 let ast_of_creation_options_code loc ele f =
-  let loc = 
+  let _loc = 
     (
      { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
      { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -286,7 +286,7 @@
     match prop.prop_kind with
       Expand | Fill | Padding ->
         if must_gen prop then
-	  let loc = 
+	  let _loc = 
 	    (
 	     { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	     { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -306,7 +306,7 @@
       No_pack -> f
     | Insert_page ->
         let g = 
-	  let loc = 
+	  let _loc = 
 	    (
 	     { Lexing.dummy_pos with Lexing.pos_cnum = fst parent.name_loc } ,
 	     { Lexing.dummy_pos with Lexing.pos_cnum = snd parent.name_loc }
@@ -315,7 +315,7 @@
 	  <:expr< $lid:parent.name$ >> 
 	in
 	let loc1 = loc in
-	let loc = 
+	let _loc = 
 	  (
 	   { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	   { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -332,7 +332,7 @@
         >>
     | _ ->
         let g = 
-	  let loc = 
+	  let _loc = 
 	    (
 	     { Lexing.dummy_pos with Lexing.pos_cnum = fst parent.name_loc } ,
 	     { Lexing.dummy_pos with Lexing.pos_cnum = snd parent.name_loc }
@@ -341,7 +341,7 @@
 	  <:expr< $lid:parent.name$ >> 
 	in
 	let loc1 = loc in
-	let loc = 
+	let _loc = 
 	  (
 	   { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	   { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -358,7 +358,7 @@
         | Insert_page | No_pack -> f
   with
     Failure s -> 
-      	let loc = 
+      	let _loc = 
 	  (
 	   { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	   { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -375,7 +375,7 @@
     | Insert_page ->
 
 	let g = 
-	  let loc = 
+	  let _loc = 
 	    (
 	     { Lexing.dummy_pos with Lexing.pos_cnum = fst parent.name_loc } ,
 	     { Lexing.dummy_pos with Lexing.pos_cnum = snd parent.name_loc }
@@ -384,7 +384,7 @@
 	  <:expr< $lid:parent.name$>> 
 	in
         let n = 
-	  let loc = 
+	  let _loc = 
 	    (
 	     { Lexing.dummy_pos with Lexing.pos_cnum = fst ele.name_loc } ,
 	     { Lexing.dummy_pos with Lexing.pos_cnum = snd ele.name_loc }
@@ -393,7 +393,7 @@
 	  <:expr< $lid:ele.name$ >> 
 	in
 	let loc1 = loc in
-	let loc = 
+	let _loc = 
 	  (
 	   { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	   { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -412,7 +412,7 @@
     | _ ->
 
         let g = 
-	  let loc = 
+	  let _loc = 
 	    (
 	     { Lexing.dummy_pos with Lexing.pos_cnum = fst parent.name_loc } ,
 	     { Lexing.dummy_pos with Lexing.pos_cnum = snd parent.name_loc }
@@ -421,7 +421,7 @@
 	  <:expr< $lid:parent.name$ >> 
 	in
 	let loc1 = loc in
-	let loc = 
+	let _loc = 
 	  (
 	   { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	   { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -438,7 +438,7 @@
           | Insert_page | No_pack -> g
         in
         let n = 
-	  let loc = 
+	  let _loc = 
 	    (
 	     { Lexing.dummy_pos with Lexing.pos_cnum = fst ele.name_loc } ,
 	     { Lexing.dummy_pos with Lexing.pos_cnum = snd ele.name_loc }
@@ -449,7 +449,7 @@
         <:class_expr< let _ = $r$ $n$ # coerce in $ce$ >>
   with
     Failure s -> 
-      let loc = 
+      let _loc = 
 	(
 	 { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	 { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -485,7 +485,7 @@
           remove_blanks (Zog_types.get_prop_value ele.props Accel_modifier)
         with
           "" -> 
-	    let loc = 
+	    let _loc = 
 	    (
 	     { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	     { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -499,7 +499,7 @@
           remove_blanks (Zog_types.get_prop_value ele.props Accel_flags)
         with
           "" ->
-	    let loc = 
+	    let _loc = 
 	    (
 	     { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	     { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -509,7 +509,7 @@
         | s -> parse_string loc s
       in
       let loc1 = loc in
-      let loc = 
+      let _loc = 
 	(
 	 { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	 { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -529,7 +529,7 @@
         List.fold_right (ast_of_post_menu_item_creation_code loc accel_name)
           ele.children ce
       in
-      let loc = 
+      let _loc = 
 	(
 	 { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	 { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -553,7 +553,7 @@
 	 match win with
 	   None -> ce
 	 | Some w -> 
-	     let loc = 
+	     let _loc = 
 	       (
 		{ Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 		{ Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -564,7 +564,7 @@
 	     >>
 	)      
       in
-      let loc = 
+      let _loc = 
 	(
 	 { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	 { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -597,7 +597,7 @@
       let f =
         match ele.classe, previous_opt with
           Radio_menu_item, Some e when e.classe = Radio_menu_item ->
-	    let loc = 
+	    let _loc = 
 	      (
 	       { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	       { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -620,7 +620,7 @@
 (* BEGIN CDK *)
   gen_anonynous_name ele;
   if ele.name = "_" then  
-      	let loc = 
+      	let _loc = 
 	  (
 	   { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	   { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -630,14 +630,14 @@
     else
     (* END CDK *)
   let n = 
-    let loc = 
+    let _loc = 
       (
        { Lexing.dummy_pos with Lexing.pos_cnum = fst ele.name_loc } ,
        { Lexing.dummy_pos with Lexing.pos_cnum = snd ele.name_loc }
 	  )	
     in <:patt< $lid:ele.name$ >> 
   in
-  let loc = 
+  let _loc = 
     (
      { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
      { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -649,7 +649,7 @@
     let cil =
       if ele.classe = Menubar then
 	let accel_name = accel_group_name ele in
-	let loc = 
+	let _loc = 
 	  (
 	   { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	   { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -662,7 +662,7 @@
     gen_anonynous_name ele;
     let cil = if ele.name.[0] <> '_' then 
       let n = 
-	let loc = 
+	let _loc = 
 	  (
 	   { Lexing.dummy_pos with Lexing.pos_cnum = fst ele.name_loc } ,
 	   { Lexing.dummy_pos with Lexing.pos_cnum = snd ele.name_loc }
@@ -670,7 +670,7 @@
 	in
 	<:expr< $lid:ele.name$ >> 
       in
-      let loc = 
+      let _loc = 
 	(
 	 { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	 { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -685,7 +685,7 @@
   let cil =
     if ele.classe = Menubar then
       let accel_name = accel_group_name ele in
-      let loc = 
+      let _loc = 
 	(
 	 { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 	 { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -697,7 +697,7 @@
 (* BEGIN CDK *)
   gen_anonynous_name ele;
   let n = 
-    let loc = 
+    let _loc = 
       (
        { Lexing.dummy_pos with Lexing.pos_cnum = fst ele.name_loc } ,
        { Lexing.dummy_pos with Lexing.pos_cnum = snd ele.name_loc }
@@ -706,7 +706,7 @@
     <:expr< $lid:ele.name$ >> 
   in
   let cil = if ele.name.[0] <> '_' then 
-    let loc = 
+    let _loc = 
       (
        { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
        { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -730,14 +730,14 @@
             Window -> cil
           | _ ->
               let n = 
-		let loc = 
+		let _loc = 
 		  (
 		   { Lexing.dummy_pos with Lexing.pos_cnum = fst e.name_loc } ,
 		   { Lexing.dummy_pos with Lexing.pos_cnum = snd e.name_loc }
 		  )	
 		in <:expr< $lid:e.name$ >> 
 	      in
-	      let loc = 
+	      let _loc = 
 		(
 		 { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
 		 { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -746,7 +746,7 @@
               let ci = <:class_str_item< method coerce = $n$ # coerce >> in
               cil @ [ci]
     in
-    let loc = 
+    let _loc = 
       (
        { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
        { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -765,7 +765,7 @@
 	in
 	ast_of_ele_creations ?win: win_opt loc None None ele ce
   in
-  let loc = 
+  let _loc = 
     (
      { Lexing.dummy_pos with Lexing.pos_cnum = fst loc } ,
      { Lexing.dummy_pos with Lexing.pos_cnum = snd loc }
@@ -798,9 +798,9 @@
 	    try
               let entity = {en_name = name; en_params = pl; en_ele = w} in
 	      (
-	       let loc = ((fst loc).Lexing.pos_cnum, (snd loc).Lexing.pos_cnum) in
+	       let loc = ((fst _loc).Lexing.pos_cnum, (snd _loc).Lexing.pos_cnum) in
 	       ast_of_entity loc entity
-	      ), loc
+	      ), _loc
             with Field_error m ->
               field_error m;
 	      exit 1
@@ -824,7 +824,7 @@
 		     prop_value_loc = ((fst vloc).Lexing.pos_cnum, (snd vloc).Lexing.pos_cnum)})
                 proplist
             in
-	    let nloc = ((fst loc).Lexing.pos_cnum, (snd loc).Lexing.pos_cnum) in
+	    let nloc = ((fst _loc).Lexing.pos_cnum, (snd _loc).Lexing.pos_cnum) in
             { name = name; name_loc = nloc;
               classe = Zog_misc.class_of_class_name tag; 
 	      props = proplist;
@@ -833,16 +833,16 @@
 	    } ] ]
     ;
     tag_end:
-      [ [ "</"; tag = LIDENT; ">" -> tag, loc ] ]
+      [ [ "</"; tag = LIDENT; ">" -> tag, _loc ] ]
     ;
     property:
       [ [ x = LIDENT; "="; (v, vloc) = string -> x, v, vloc ] ]
     ;
     string:
-      [ [ v = STRING -> v,  loc ] ]
+      [ [ v = STRING -> v,  _loc ] ]
     ;
     ident:
-      [ [ v = LIDENT -> v, loc ] ]
+      [ [ v = LIDENT -> v, _loc ] ]
     ;
   END
 
