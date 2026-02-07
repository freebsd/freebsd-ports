--- src/csv.ml.orig	2010-06-14 11:17:06 UTC
+++ src/csv.ml
@@ -50,13 +50,13 @@ let max i j = if (i:int) < j then j else i
 
 class type in_obj_channel =
 object
-  method input : string -> int -> int -> int
+  method input : bytes -> int -> int -> int
   method close_in : unit -> unit
 end
 
 class type out_obj_channel =
 object
-  method output : string -> int -> int -> int
+  method output : bytes -> int -> int -> int
   method close_out : unit -> unit
 end
 
@@ -81,7 +81,7 @@ let buffer_len = 0x1FFF
    FIXME: This is not made for non-blocking channels.  Can we fix it? *)
 type in_channel = {
   in_chan : in_obj_channel;
-  in_buf : string;
+  in_buf : bytes;
   (* The data in the in_buf is at indexes i s.t. in0 <= i < in1.
      Invariant: 0 <= in0 ; in1 <= buffer_len in1 < 0 indicates a
      closed channel. *)
@@ -156,12 +156,12 @@ object
   val ic = ic
 
   method input buf ofs len =
-    if ofs < 0 || len < 0 || ofs + len > String.length buf
+    if ofs < 0 || len < 0 || ofs + len > Bytes.length buf
     then invalid_arg "Csv.to_in_obj#input";
     if ic.in1 < 0 then raise(Sys_error "Bad file descriptor");
     fill_in_buf ic;
     let r = min len (ic.in1 - ic.in0) in
-    String.blit ic.in_buf ic.in0 buf ofs r;
+    Bytes.blit ic.in_buf ic.in0 buf ofs r;
     ic.in0 <- ic.in0 + r;
     r
 
@@ -185,8 +185,8 @@ let strip_contents buf =
    assumed the substring parameters are valid. *)
 let strip_substring buf ofs len =
   let n = ref(ofs + len - 1) in
-  while !n >= ofs && is_space(String.unsafe_get buf !n) do decr n done;
-  String.sub buf ofs (!n - ofs + 1)
+  while !n >= ofs && is_space(Bytes.unsafe_get buf !n) do decr n done;
+  Bytes.sub_string buf ofs (!n - ofs + 1)
 
 
 (* Skip the possible '\n' following a '\r'.  Reaching End_of_file is
@@ -194,7 +194,7 @@ let strip_substring buf ofs len =
 let skip_CR ic =
   try
     fill_in_buf ic;
-    if String.unsafe_get ic.in_buf ic.in0 = '\n' then ic.in0 <- ic.in0 + 1
+    if Bytes.unsafe_get ic.in_buf ic.in0 = '\n' then ic.in0 <- ic.in0 + 1
   with End_of_file -> ()
 
 
@@ -205,19 +205,19 @@ let skip_CR ic =
 let rec seek_unquoted_separator ic i =
   if i >= ic.in1 then (
     (* End not found, need to look at the next chunk *)
-    Buffer.add_substring ic.current_field ic.in_buf ic.in0 (i - ic.in0);
+    Buffer.add_subbytes ic.current_field ic.in_buf ic.in0 (i - ic.in0);
     ic.in0 <- i;
     fill_in_buf ic; (* or raise End_of_file *)
     seek_unquoted_separator ic 0
   )
   else
-    let c = String.unsafe_get ic.in_buf i in
+    let c = Bytes.unsafe_get ic.in_buf i in
     if c = ic.separator || c = '\n' || c = '\r' then (
       if Buffer.length ic.current_field = 0 then
         (* Avoid copying the string to the buffer if unnecessary *)
         ic.record <- strip_substring ic.in_buf ic.in0 (i - ic.in0) :: ic.record
       else (
-        Buffer.add_substring ic.current_field ic.in_buf ic.in0 (i - ic.in0);
+        Buffer.add_subbytes ic.current_field ic.in_buf ic.in0 (i - ic.in0);
         ic.record <- strip_contents ic.current_field :: ic.record;
       );
       ic.in0 <- i + 1;
@@ -236,7 +236,7 @@ let add_unquoted_field ic =
    follow, [false] if the record is complete. *)
 let rec seek_quoted_separator ic field_no =
   fill_in_buf ic; (* or raise End_of_file *)
-  let c = String.unsafe_get ic.in_buf ic.in0 in
+  let c = Bytes.unsafe_get ic.in_buf ic.in0 in
   ic.in0 <- ic.in0 + 1;
   if c = ic.separator || c = '\n' || c = '\r' then (
     ic.record <- Buffer.contents ic.current_field :: ic.record;
@@ -249,13 +249,13 @@ let rec seek_quoted_separator ic field_no =
 let rec examine_quoted_field ic field_no after_quote i =
   if i >= ic.in1 then (
     (* End of field not found, need to look at the next chunk *)
-    Buffer.add_substring ic.current_field ic.in_buf ic.in0 (i - ic.in0);
+    Buffer.add_subbytes ic.current_field ic.in_buf ic.in0 (i - ic.in0);
     ic.in0 <- i;
     fill_in_buf ic; (* or raise End_of_file *)
     examine_quoted_field ic field_no after_quote 0
   )
   else
-    let c = String.unsafe_get ic.in_buf i in
+    let c = Bytes.unsafe_get ic.in_buf i in
     if !after_quote then (
       if c = '\"' then (
         after_quote := false;
@@ -278,7 +278,7 @@ let rec examine_quoted_field ic field_no after_quote i
     else if c = '\"' then (
       after_quote := true;
       (* Save the field so far, without the quote *)
-      Buffer.add_substring ic.current_field ic.in_buf ic.in0 (i - ic.in0);
+      Buffer.add_subbytes ic.current_field ic.in_buf ic.in0 (i - ic.in0);
       ic.in0 <- i + 1; (* skip the quote *)
       examine_quoted_field ic field_no after_quote ic.in0
     )
@@ -298,12 +298,12 @@ let add_quoted_field ic field_no =
 let skip_spaces ic =
   let is_space = if ic.separator = '\t' then is_real_space else is_space in
   (* Skip spaces: after this [in0] is a non-space char. *)
-  while ic.in0 < ic.in1 && is_space(String.unsafe_get ic.in_buf ic.in0) do
+  while ic.in0 < ic.in1 && is_space(Bytes.unsafe_get ic.in_buf ic.in0) do
     ic.in0 <- ic.in0 + 1
   done;
   while ic.in0 >= ic.in1 do
     fill_in_buf ic;
-    while ic.in0 < ic.in1 && is_space(String.unsafe_get ic.in_buf ic.in0) do
+    while ic.in0 < ic.in1 && is_space(Bytes.unsafe_get ic.in_buf ic.in0) do
       ic.in0 <- ic.in0 + 1
     done;
   done
@@ -320,7 +320,7 @@ let add_next_field ic field_no =
   try
     skip_spaces ic;
     (* Now, in0 < in1 or End_of_file was raised *)
-    let c = String.unsafe_get ic.in_buf ic.in0 in
+    let c = Bytes.unsafe_get ic.in_buf ic.in0 in
     if c = '\"' then (
       ic.in0 <- ic.in0 + 1;
       add_quoted_field ic field_no
@@ -329,7 +329,7 @@ let add_next_field ic field_no =
       ic.in0 <- ic.in0 + 1; (* mark '=' as read *)
       try
         fill_in_buf ic;
-        if String.unsafe_get ic.in_buf ic.in0 = '\"' then (
+        if Bytes.unsafe_get ic.in_buf ic.in0 = '\"' then (
           (* Excel trick ="..." to prevent spaces around the field
              to be removed. *)
           ic.in0 <- ic.in0 + 1; (* skip '"' *)
@@ -414,14 +414,14 @@ let load_rows ?separator ?excel_tricks f ch =
 type out_channel = {
   out_chan : out_obj_channel;
   out_separator : char;
-  out_separator_string : string;
+  out_separator_bytes : bytes;
   out_excel_tricks : bool;
 }
 
 let to_out_obj ?(separator=',') ?(excel_tricks=false) out_chan = {
   out_chan = out_chan;
   out_separator = separator;
-  out_separator_string = String.make 1 separator;
+  out_separator_bytes = Bytes.make 1 separator;
   out_excel_tricks = excel_tricks;
 }
 
@@ -437,6 +437,16 @@ let rec really_output oc s ofs len =
   let w = oc.out_chan#output s ofs len in
   if w < len then really_output oc s (ofs+w) (len-w)
 
+let quote_bytes = Bytes.make 1 '\"'
+let output_quote oc = really_output oc quote_bytes 0 1
+
+let equal_quote_bytes = Bytes.make 2 '='
+let () = Bytes.unsafe_set equal_quote_bytes 1 '\"'
+let output_equal_quote oc = really_output oc equal_quote_bytes 0 2
+
+let newline_bytes = Bytes.make 1 '\n'
+let output_newline oc = really_output oc newline_bytes 0 1
+
 (* Determine whether the string s must be quoted and how many chars it
    must be extended to contain the escaped values.  Return -1 if there
    is no need to quote.  It is assumed that the string length [len]
@@ -466,10 +476,11 @@ let write_escaped oc field =
     let use_excel_trick = oc.out_excel_tricks && need_excel_trick field len
     and n = must_quote oc.out_separator oc.out_excel_tricks field len in
     if n < 0 && not use_excel_trick then
-      really_output oc field 0 len
+      (* [really_output] does not mutate the [bytes] argument. *)
+      really_output oc (Bytes.unsafe_of_string field) 0 len
     else (
       let field =
-        if n = 0 then field
+        if n = 0 then Bytes.unsafe_of_string field
         else (* There are some quotes to escape *)
           let s = String.create (len + n) in
           let j = ref 0 in
@@ -487,26 +498,26 @@ let write_escaped oc field =
           done;
           s
       in
-      if use_excel_trick then really_output oc "=\"" 0 2
-      else really_output oc "\"" 0 1;
-      really_output oc field 0 (String.length field);
-      really_output oc "\"" 0 1
+      if use_excel_trick then output_equal_quote oc
+      else output_quote oc;
+      really_output oc field 0 (Bytes.length field);
+      output_quote oc
     )
   end
 
 let output_record oc = function
   | [] ->
-      really_output oc "\n" 0 1
+      output_newline oc
   | [f] ->
       write_escaped oc f;
-      really_output oc "\n" 0 1
+      output_newline oc
   | f :: tl ->
       write_escaped oc f;
       List.iter (fun f ->
-                   really_output oc oc.out_separator_string 0 1;
+                   really_output oc oc.out_separator_bytes 0 1;
                    write_escaped oc f;
                 ) tl;
-      really_output oc "\n" 0 1
+      output_newline oc
 
 let output_all oc t =
   List.iter (fun r -> output_record oc r) t
