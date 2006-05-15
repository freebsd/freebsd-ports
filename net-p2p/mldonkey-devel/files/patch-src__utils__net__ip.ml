--- src/utils/net/ip.ml.orig	Wed Mar 29 12:41:10 2006
+++ src/utils/net/ip.ml	Sun May 14 17:24:09 2006
@@ -17,52 +17,56 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *)
 
+(* This module uses 2 ints to save IPv4 numbers. *)
+
 open Int64ops
 open Printf2
-type t =  int * int * int * int
+type t = { hi: int; lo: int }
 
-external of_string : string -> t  = "ml_ints_of_string"
+let of_ints (a,b,c,d) =
+  { hi = (a lsl 8) lor b;
+    lo = (c lsl 8) lor d; }
 
-let allow_local_network = ref false
+let to_ints t =
+  t.hi lsr 8, t.hi land 255,
+  t.lo lsr 8, t.lo land 255
 
-let of_inet_addr t =
-  of_string (Unix.string_of_inet_addr t)
+external ints_of_string : string -> (int*int*int*int)  = "ml_ints_of_string"
 
-let any = of_inet_addr Unix.inet_addr_any
+let of_string s =
+  of_ints (ints_of_string s)
 
-let null = (0,0,0,0)
+let to_string t =
+  let (a4, a3, a2, a1) = to_ints t in
+  Printf.sprintf "%d.%d.%d.%d" a4 a3 a2 a1
 
-let of_ints t = t
+let allow_local_network = ref false
 
-let to_ints t = t
-let to_string (a4, a3, a2, a1) =
-  Printf.sprintf "%d.%d.%d.%d" a4 a3 a2 a1
+let of_inet_addr ia =
+  of_string (Unix.string_of_inet_addr ia)
+
+let any = of_inet_addr Unix.inet_addr_any
+
+let null = { hi = 0; lo = 0; }
 
 let to_inet_addr t =
   Unix.inet_addr_of_string (to_string t)
 
 let hostname_table = Hashtbl.create 997
 
-let to_fixed_string ((a4, a3, a2, a1) as t)=
+let to_fixed_string t =
+  let (a4, a3, a2, a1) = to_ints t in
   try
     Hashtbl.find hostname_table t
   with _ ->
       Printf.sprintf "%03d.%03d.%03d.%03d" a4 a3 a2 a1
 
-let to_int64 (a4, a3, a2, a1) =
-  let small = a1 lor (a2 lsl 8) lor (a3 lsl 16) in
-  (Int64.of_int small) ++ (Int64.shift_left (Int64.of_int a4) 24)
+let to_int64 t =
+  Int64.logor (Int64.shift_left (Int64.of_int t.hi) 16) (Int64.of_int t.lo)
 
 let of_int64 i =
-  let a4 = Int64.to_int (Int64.logand (Int64.shift_right i 24) 0xffL)
-  in
-  let a3 = Int64.to_int (Int64.logand (Int64.shift_right i 16) 0xffL)
-  in
-  let a2 = Int64.to_int (Int64.logand (Int64.shift_right i 8) 0xffL)
-  in
-  let a1 = Int64.to_int (Int64.logand i 0xffL)
-  in
-  (a4, a3, a2, a1)
+  { hi = Int64.to_int (Int64.shift_right i 16);
+    lo = Int64.to_int (Int64.logand i 65535L); }
 
 let resolve_one t =
   try
@@ -79,13 +83,15 @@
       end;
       to_fixed_string t
 
-let valid (j,k,l,i) =
+let valid t =
+  let (j,k,l,i) = to_ints t in
   j > 0 && j < 224 &&
   k >= 0 && k <= 255 &&
   l >= 0 && l <= 255 &&
   i >= 0 && i <= 255
 
-let local_ip ip =
+let local_ip t =
+  let ip = to_ints t in
   match ip with
     192, 168,_,_ -> true
   | 10, _, _, _ | 127, _,_,_ -> true
@@ -98,48 +104,38 @@
 let usable ip =
   reachable ip && valid ip
 
-let rec matches ((a4,a3,a2,a1) as a) ips =
-  match ips with
-    [] -> false
-  | (b4,b3,b2,b1) :: tail ->
-      ( (a4 = b4 || b4 = 255) &&
-        (a3 = b3 || b3 = 255) &&
-        (a2 = b2 || b2 = 255) &&
-        (a1 = b1 || b1 = 255))
-      || (matches a tail)
+let matches t ips =
+  let (a4,a3,a2,a1) = to_ints t in
+  let rec matches_aux ips =
+    match ips with
+      [] -> false
+    | b :: tail ->
+       let (b4,b3,b2,b1) = to_ints b in
+       ( (a4 = b4 || b4 = 255) &&
+          (a3 = b3 || b3 = 255) &&
+          (a2 = b2 || b2 = 255) &&
+          (a1 = b1 || b1 = 255))
+      || (matches_aux tail) in
+  matches_aux ips
 
-let compare (a4,a3,a2,a1) (b4,b3,b2,b1) =
-  let c4 = compare a4 b4 in
-  if c4 <> 0 then c4 else
-  let c3 = compare a3 b3 in
-  if c3 <> 0 then c3 else
-  let c2 = compare a2 b2 in
-  if c2 <> 0 then c2 else
-  compare a1 b1
+let compare a b =
+  let hicompare = compare a.hi b.hi in
+  if hicompare <> 0 then
+       hicompare
+  else
+       compare a.lo b.lo
 
-let succ (a4,a3,a2,a1) =
-  if a1 < 255 then
-    (a4,a3,a2,a1+1)
-  else if a2 < 255 then
-    (a4,a3,a2+1,0)
-  else if a3 < 255 then
-    (a4,a3+1,0,0)
-  else if a4 < 255 then
-    (a4+1,0,0,0)
+let succ t =
+  if t.lo < 65535 then
+       { t with lo = t.lo+1 }
   else
-    (0,0,0,0) (* or exception ? *)
+       { hi = t.hi+1; lo = 0; }
 
-let pred (a4,a3,a2,a1) =
-  if a1 > 0 then
-    (a4,a3,a2,a1-1)
-  else if a2 > 0 then
-    (a4,a3,a2-1,255)
-  else if a3 > 0 then
-    (a4,a3-1,255,255)
-  else if a4 > 0 then
-    (a4-1,255,255,255)
+let pred t =
+  if t.lo > 0 then
+    { t with lo = t.lo-1 }
   else
-    (255,255,255,255) (* or exception ? *)
+    { hi = t.hi-1; lo = 65535; }
 
 let banned = ref (fun (ip:t) -> None)
 
@@ -154,7 +150,7 @@
       [] -> raise Not_found
     | ip :: tail ->
         let ip = of_inet_addr ip in
-        if ip = (127,0,0,1) then
+        if ip = localhost then
           iter tail
         else ip
   in
@@ -225,12 +221,12 @@
 
 let option = define_option_class "Ip" value_to_ip ip_to_value
 
-let rev (a1,a2,a3,a4) = (a4,a3,a2,a1)
+let rev t =
+  let (a4,a3,a2,a1) = to_ints t in
+  of_ints (a1,a2,a3,a4)
 
 let equal a b = 
-  let (a1,a2,a3,a4) = a in
-  let (b1,b2,b3,b4) = b in
-    ( a1=b1 &&  a2=b2 &&  a3=b3 && a4=b4)
+  a = b
 
 type job = {
     name : string;
