--- ./src/daemon/common/commonSwarming.ml.orig	Mon Apr 10 14:06:20 2006
+++ ./src/daemon/common/commonSwarming.ml	Thu Apr 20 11:04:03 2006
@@ -38,7 +38,7 @@
 exception VerifierNotReady
 
 type chunks =
-  AvailableRanges of (int64 * int64) list
+  AvailableIntervals of (int64 * int64) list
 (* A bitmap is encoded with '0' for empty, '1' for present '2' complete '3' verified *)
 | AvailableCharBitmap of string 
 (* A bitmap encoded as a bit vector *)
@@ -54,18 +54,17 @@
 let exit_on_error = ref false
 
 (* prints a new logline with date, module and starts newline *)
-let lprintf_nl () =
-  lprintf "%s[cSw2] "
-    (log_time ()); lprintf_nl2
+let lprintf_nl = (fun fmt ->
+  lprintf "%s[cSw2] " (log_time ()); 
+  lprintf_nl2 fmt)
 
 (* prints a new logline with date, module and does not start newline *)
-let lprintf_n () =
-  lprintf "%s[cSw2] "
-    (log_time ()); lprintf
+let lprintf_n = (fun fmt ->
+  lprintf "%s[cSw2] " (log_time ()); 
+  lprintf fmt)
 
 open CommonTypes
 
-open Int64ops
 open CommonFile
 open CommonTypes
 open CommonClient
@@ -93,6 +92,8 @@
 
 *)
 
+(* only used in code (currently disabled) for finding duplicate chunks *)
+
 type chunk = {
     chunk_uid : uid_type;
     chunk_size : int64;
@@ -102,20 +103,27 @@
 (* glossary:
    network frontend use "chunks" of data,
    swarmer use "blocks" of data *)
+(* frontends are compared using physical equality (==) *)
 type t = {
     mutable t_primary : bool;
     t_file : file;
     mutable t_s : swarmer;
-    t_block_size : int64;
+    t_chunk_size : int64;
 
     t_nchunks : int;
     mutable t_converted_verified_bitmap : string;
     mutable t_last_seen : int array;
-    mutable t_ncomplete_blocks : int;
-    mutable t_nverified_blocks : int;
+    mutable t_ncomplete_chunks : int;
+    mutable t_nverified_chunks : int;
 
-    mutable t_verifier : verification;
-    mutable t_verified : (int -> int -> unit);
+    mutable t_verifier : verification; (* information available to
+					  check data correctness *)
+    mutable t_verified : (int -> int -> unit); (* function to call
+						  when a chunk is verified;
+						  receives the number
+						  of verified chunks,
+						  and the index of the
+						  chunk just verified *)
 
 (* mapping from network chunks to swarmer blocks *)
     mutable t_blocks_of_chunk : int list array;
@@ -124,12 +132,12 @@
   }
 
 and swarmer = {
-    mutable s_num : int;
-    mutable s_filename : string;
+    s_num : int;
+    s_filename : string;
 
     mutable s_networks : t list; (** list of frontends, primary at head 
 				     t.t_s = s <=> t in s.s_networks *)
-    mutable s_size : int64;
+    s_size : int64;
     mutable s_range_size : int64;
     mutable s_strategy : strategy;
 
@@ -156,8 +164,11 @@
     mutable block_end : Int64.t;
     mutable block_ranges : range; (** [range] of the double-linked
 				      list of ranges associated to the
-				      [block] *)
-    mutable block_remaining : int64; (* unused ? *)
+				      [block] 
+				      what about using a standard list
+				      instead ? 
+				      or a balanced tree ? *)
+    mutable block_remaining : int64; (* amount of bytes missing. *)
   }
 
 and range = {
@@ -167,9 +178,8 @@
     mutable range_prev : range option;
     mutable range_next : range option;
     mutable range_current_begin : Int64.t; (* current begin pos *)
-(*        mutable range_verified : bool; *)
-    mutable range_nuploading : int; (* current number of clients
-				       filling that range ? *)
+    mutable range_nuploading : int; (* number of uploaders currently
+				       referencing that range *)
   }
 
 and uploader = {
@@ -193,11 +203,14 @@
     mutable up_block_begin : int64;
     mutable up_block_end : int64;
 
-    mutable up_ranges : (int64 * int64 * range) list;
+    mutable up_ranges : (int64 * int64 * range) list; (* ranges referenced by
+							 that uploader, see
+							 range_nuploading *)
   }
 
 (* range invariants: 
-   Ranges represent "holes" of missing data in a block.
+   Ranges represent "holes" of missing data in a block; Data is
+   missing between offsets range_current_begin and range_end.
 
    [block]'s [block_ranges] reference the first (smallest offsets) of
    the [range]s associated with it. 
@@ -218,10 +231,45 @@
    b.block_begin <= b.block_ranges.block_begin ... <=
    r.range_prev.range_end <= r.range_begin <= r.range_current_begin <=
    r.range_end <= r.range_next.range_begin <= ...
-   <= b.block_end
+   <= b.block_end *)
    
-   Role played by r.range_current_begin is unclear for now. *)
+(* Role played by r.range_begin is unclear for now. One beginning
+   offset is probably enough for an interval ;)
 
+   range owners are only used thru uploaders.up_ranges. blocks could be
+   saved in [uploaders]' [up_ranges] along range, but would
+   need uploading when the swarmer is splitted.
+
+   Removing [range] from [up_ranges] and [range_nuploading] from
+   [range] could be good too, because they're not correctly updated
+   when the swarmer is splitted. Again, getting rid of them is a
+   problem of performance.
+*)
+
+(* block invariants
+   Data missing for a block is the sum of the "sizes" of its ranges.
+
+   b.block_remaining = sum (r.range_end - r.range_current_begin) b.block_ranges
+*)
+
+(* swarmer invariants ?
+   s.s_verified_bitmap.[i] = 0 <=> s_blocks.[i] = EmptyBlock
+   s.s_verified_bitmap.[i] = 1 <=> s_blocks.[i] = PartialBlock _
+   s.s_verified_bitmap.[i] = 2 <=> s_blocks.[i] = CompletedBlock
+   s.s_verified_bitmap.[i] = 3 <=> s_blocks.[i] = VerifiedBlock
+   If so, why not drop s_verified_bitmap, and replace it by
+   verified_bitmap s i and verified_bitmap_all s functions ?
+*)
+
+(* frontend invariants ?
+   t_ncomplete_chunks = 
+   List.length (List.filter (fun x -> x >= '2') t_converted_verified_bitmap)
+   t_nverified_chunks = 
+   List.length (List.filter (fun x -> x = '3') t_converted_verified_bitmap)
+
+   All chunks are [t_chunk_size] bytes in size, and first start at
+   offset 0. This is assumed in [associate], [verify_chunk], maybe more.
+*)
 
 (*************************************************************************)
 (*                                                                       *)
@@ -251,8 +299,6 @@
 
 let swarmer_counter = ref 0
 
-let has_multinet = true
-
 (*************************************************************************)
 (*                                                                       *)
 (*                         dummy_swarmer                                 *)
@@ -276,10 +322,10 @@
 (** (debug) output an [uploader] to current log *)
 
 let print_uploader up =
-  lprintf_n () "  interesting complete_blocks: %d\n     " up.up_ncomplete;
+  lprintf_n "  interesting complete_blocks: %d\n     " up.up_ncomplete;
   Array.iter (fun i -> lprintf " %d " i) up.up_complete_blocks;
   lprint_newline ();
-  lprintf_n () "  interesting partial_blocks: %d\n     " up.up_npartial;
+  lprintf_n "  interesting partial_blocks: %d\n     " up.up_npartial;
   Array.iter (fun (i, begin_pos, end_pos) ->
       lprintf " %d[%Ld...%Ld] " i begin_pos end_pos
   ) up.up_partial_blocks;
@@ -301,10 +347,10 @@
   t.t_last_seen
 
 (** if a swarmer is already associated with that [file_name], return it;
-    Otherwise create a new one with default values (including a default
-    [range_size] instead of the provided value ??) *)
+    Otherwise create a new one with default values, that will be fixed
+    by the first frontend association *)
 
-let create_swarmer file_name file_size range_size =
+let create_swarmer file_name file_size =
 
   try
     HS.find swarmers_by_name
@@ -314,9 +360,7 @@
   with Not_found ->
       incr swarmer_counter;
 
-(* Let be VERY conservative... *)
-      let range_size = edonkey_range_size in
-
+      let range_size = edonkey_range_size in (* yuck ? *)
       let nchunks = 1 in
       let rec s = {
 
@@ -357,6 +401,43 @@
   let b = s.s_block_pos in
   b.(i)
 
+(** Finds the number of the block containing [chunk_pos] offset, using
+    dichotomy *)
+
+(* 0 <= chunk_pos < s.s_size *)
+let compute_block_num s chunk_pos =
+  assert (0L <= chunk_pos && chunk_pos < s.s_size);
+  let b = s.s_block_pos in
+(* invariants:
+   0 <= min <= max <= Array.length b - 1
+   compute_block_begin s min <= chunk_pos < compute_block_end s max *)
+
+  let rec iter min max =
+    if min = max then min
+    else (* from now on, min < max *)
+      let medium = (min + max) / 2 in
+      (* Euclide        => 2*medium <= min + max <= 2*medium + 1 *)
+      (* min < max      => 2*min < min + max < 2*max
+                        => min <= medium < max                   *)
+      if min < medium then
+        if chunk_pos < b.(medium) then
+          iter min (medium - 1)
+        else
+          iter medium max
+      else
+        (* min = medium < max  => 2*min < min + max <= 2*min + 1
+                              <=>   min <       max <=   min + 1
+                              <=> min + 1 = max                  *)
+        if chunk_pos < b.(max) then
+          min else max
+  in
+  let i = iter 0 (Array.length b - 1) in
+  if debug_all then
+    lprintf_nl "%Ld is block %d [%Ld-%Ld]" chunk_pos i
+      (compute_block_begin s i) (compute_block_end s i);
+  i
+
+
 (** (internal) return a 0 sized range at offset [pos], and assigned to
     block [b] *)
 
@@ -426,7 +507,7 @@
       r.range_current_begin <- min r.range_current_begin cut_pos;
 
       if r.range_nuploading <> 0 then
-	lprintf_n () "WARNING: Splitting a range currently being uploaded, don't know what to do with range_nuploaders :/\n";
+	lprintf_n "WARNING: Splitting a range currently being uploaded, don't know what to do with range_nuploaders :/\n";
 
       split_r in
   let cut_ranges = iter r in
@@ -554,9 +635,9 @@
     aux 0 in
 
   if array_exist ((<>) 0) s.s_availability then
-    lprintf_nl () "WARNING: splitting swarmer discarded availability counters\n";
+    lprintf_nl "WARNING: splitting swarmer discarded availability counters";
   if array_exist ((<>) 0) s.s_nuploading then
-    lprintf_nl () "WARNING: splitting a swarmer beging uploaded to\n";
+    lprintf_nl "WARNING: splitting a swarmer beging uploaded to";
 
   s.s_blocks <- Array.create nblocks EmptyBlock;
   s.s_verified_bitmap <- String.make nblocks '0';
@@ -617,7 +698,7 @@
 in smaller blocks depending on the block_size of this network, and compute
 the t_chunk_of_block and t_blocks_of_chunk fields. *)
 
-  let chunk_size = t.t_block_size in
+  let chunk_size = t.t_chunk_size in
 
   split_blocks s chunk_size;
 
@@ -628,7 +709,7 @@
       t.t_chunk_of_block <- Array.create nblocks 0;
       t.t_blocks_of_chunk <- Array.create nchunks [];
 
-      let chunk_size = t.t_block_size in
+      let chunk_size = t.t_chunk_size in
       for i = 0 to nblocks - 1 do
         let block_begin = compute_block_begin s i in
         let chunk = Int64.to_int (block_begin // chunk_size) in
@@ -663,21 +744,21 @@
 let create ss file chunk_size =
 
   let size = file_size file in
-  (* wrong if size is a multiple of chunk_size ? *)
+  (* wrong if size is a multiple of chunk_size, or on purpose ? *)
   let nchunks =
     1 + Int64.to_int (Int64.pred size // chunk_size) in
 
-  let rec t = {
+  let t = {
 
       t_s = ss;
       t_primary = true;
       t_file = file;
 
       t_nchunks = nchunks;
-      t_block_size = chunk_size;
+      t_chunk_size = chunk_size;
 
-      t_ncomplete_blocks = 0;
-      t_nverified_blocks = 0;
+      t_ncomplete_chunks = 0;
+      t_nverified_chunks = 0;
 
       t_converted_verified_bitmap = String.make nchunks '0';
       t_last_seen = Array.create nchunks 0;
@@ -721,91 +802,59 @@
       let s = t.t_s in
       s.s_nuploading.(num) <- s.s_nuploading.(num) - 1
 
-(** Finds the number of the block containing [chunk_pos] offset, using
-    dichotomy *)
+(** iter function f over all the blocks contained in the list of [intervals]
 
-let compute_block_num s chunk_pos =
-  let b = s.s_block_pos in
-  let rec iter min max =
-    if min = max then min 
-    else
-      let medium = (min + max + 1) / 2 in
-      if chunk_pos < b.(medium) then
-	iter min (medium - 1)
-      else
-	let medium1 = medium + 1 in
-	if chunk_pos >= b.(medium1) then
-	  iter medium1 max
-	else
-	  medium
-  in
-  let i = iter 0 (Array.length b - 1) in
-  if debug_all then
-    lprintf_nl () "%Ld is block %d [%Ld-%Ld]" chunk_pos i
-      (compute_block_begin s i) (compute_block_end s i);
-  i
+    f with receive block number, block beginning and ending offsets,
+    and overlapping interval beginning and ending offsets.
 
+    If an interval starts halfway of a block, iteration starts on the
+    next block, with interval_begin < block_begin indicating where the
+    interval really started.
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         apply_intervals (internal)                    *)
-(*                                                                       *)
-(*************************************************************************)
+    If an interval ends halfway of a block, iteration ends on that
+    block, with interval_end < block_end indicating where the interval
+    really ended.
+*)
 
-let apply_intervals s f chunks =
+let iter_intervals s f intervals =
   let nchunks = Array.length s.s_blocks in
-  let rec iter chunks =
-    match chunks with
-      [] -> ()
-    | (chunk_begin, chunk_end) :: tail ->
-        let chunk_begin = min chunk_begin s.s_size in
-        let chunk_end = min chunk_end s.s_size in
-(*        lprintf "apply on %Ld-%Ld\n" chunk_begin chunk_end; *)
-        if chunk_begin < chunk_end then begin
-            let i0 = compute_block_num s chunk_begin in
-            let block_begin = compute_block_begin s i0 in
-            let rec iter_blocks i block_begin chunk_begin =
-
-(*              lprintf "iter_blocks %d %Ld %Ld\n" i block_begin chunk_begin; *)
-              if i < nchunks && block_begin < chunk_end then
-                let block_end = compute_block_end s i in
-
-                let current_end =  min block_end chunk_end in
-
-                if debug_all then
-                  lprintf_nl () "Apply: %d %Ld-%Ld %Ld-%Ld"
-                    i block_begin block_end chunk_begin current_end;
-
-                f i block_begin block_end chunk_begin current_end;
-
-                iter_blocks (i+1) block_end block_end
-            in
-            iter_blocks i0 block_begin chunk_begin;
-          end;
-        iter tail
-  in
-  iter chunks
-
+  List.iter (fun (interval_begin, interval_end) ->
+    let interval_begin = min interval_begin s.s_size in
+    let interval_end = min interval_end s.s_size in
+(*  lprintf "apply on %Ld-%Ld\n" interval_begin interval_end; *)
+    if interval_begin < interval_end then
+      let i0 = compute_block_num s interval_begin in
+      let block_begin = compute_block_begin s i0 in
+      let rec iter_blocks i block_begin interval_begin =
+(*      lprintf "iter_blocks %d %Ld %Ld\n" i block_begin interval_begin; *)
+        if i < nchunks && block_begin < interval_end then
+          let block_end = compute_block_end s i in
+          let current_end =  min block_end interval_end in
+	  
+          if debug_all then
+            lprintf_nl "Apply: %d %Ld-%Ld %Ld-%Ld"
+              i block_begin block_end interval_begin current_end;
+	  
+          f i block_begin block_end interval_begin current_end;
+          iter_blocks (i+1) block_end block_end
+      in
+      iter_blocks i0 block_begin interval_begin
+  ) intervals
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         print_s                                       *)
-(*                                                                       *)
-(*************************************************************************)
+(** (debug) output a [swarmer] to current log *)
 
 let print_s str s =
-  lprintf_nl () "Ranges after %s:" str;
+  lprintf_nl "Ranges after %s:" str;
 
   let rec iter r =
-    lprintf_n () " %Ld(%Ld)-%Ld(%d)"
+    lprintf_n " %Ld(%Ld)-%Ld(%d)"
       r.range_begin r.range_current_begin r.range_end r.range_nuploading;
     match r.range_next with
       None -> lprint_newline()
-    | Some r -> iter r
-  in
+    | Some r -> iter r in
 
   Array.iteri (fun i b ->
-      lprintf_n () "   %d: " i;
+      lprintf_n "   %d: " i;
       let block_begin = compute_block_begin s i in
       let block_end = compute_block_end s i in
       lprintf "%Ld - %Ld [%Ld] %c " block_begin block_end
@@ -818,7 +867,7 @@
       ) s.s_networks;
 
       match b with
-        PartialBlock b ->
+      | PartialBlock b ->
           lprintf " [%Ld .. %Ld] --> "
             b.block_begin b.block_end;
           iter b.block_ranges
@@ -827,19 +876,15 @@
       | VerifiedBlock -> lprintf_nl2 "V"
   ) s.s_blocks;
 
-  lprintf_nl () "Files:";
+  lprintf_nl "Files:";
   List.iter (fun t ->
-      lprintf_nl () "  File num: %d" (file_num t.t_file);
-      lprintf_nl () "  %s" (if t.t_primary then "primary" else "secondary");
-      lprintf_nl () "  Downloaded: %Ld" (file_downloaded t.t_file);
-      lprintf_nl () "  Bitmap: %s" t.t_converted_verified_bitmap
+      lprintf_nl "  File num: %d" (file_num t.t_file);
+      lprintf_nl "  %s" (if t.t_primary then "primary" else "secondary");
+      lprintf_nl "  Downloaded: %Ld" (file_downloaded t.t_file);
+      lprintf_nl "  Bitmap: %s" t.t_converted_verified_bitmap
   ) s.s_networks
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         iter_block_ranges                             *)
-(*                                                                       *)
-(*************************************************************************)
+(** iter function f over all the ranges of a block *)
 
 let iter_block_ranges f b =
   let rec iter_range f r =
@@ -850,96 +895,50 @@
   in
   iter_range f b.block_ranges
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         print_block                                   *)
-(*                                                                       *)
-(*************************************************************************)
+(** (debug) output a [block] to current log *)
 
 let print_block b =
-  lprintf_n () "Block %d: %Ld-%Ld"
+  lprintf_n "Block %d: %Ld-%Ld"
     b.block_num b.block_begin b.block_end;
   lprint_newline ();
-  lprintf_nl () "  ranges:";
-  let rec iter_range r =
-    lprintf_nl () "   %Ld-%Ld" r.range_current_begin r.range_end;
-    match r.range_next with
-      None -> ()
-    | Some rr -> iter_range rr
-  in
-  iter_range b.block_ranges;
+  lprintf_nl "  ranges:";
+  iter_block_ranges (fun r ->
+    lprintf_nl "   %Ld-%Ld" r.range_current_begin r.range_end) b;
   lprint_newline ()
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         add_file_downloaded                           *)
-(*                                                                       *)
-(*************************************************************************)
+(** (shadows CommonFile.add_file_downloaded) 
+    increments amount downloaded of the primary frontend of the swarmer,
+    and of maybe_t, if provided, and if it's different from the primary. *)
 
 let add_file_downloaded maybe_t s size =
 (*  lprintf "add_file_downloaded %Ld\n" size; *)
   match s.s_networks with
-    t :: _ when t.t_primary ->
+  | t :: _ ->
+      assert(t.t_primary);
       add_file_downloaded t.t_file size;
-      begin
-        match maybe_t with
-          None -> ()
-        | Some tt when t != tt ->
-            add_file_downloaded tt.t_file size;
-        | _ -> ()
-      end;
+      (match maybe_t with
+        | None -> ()
+        | Some tt ->
+	    if t != tt then
+              add_file_downloaded tt.t_file size);
       if file_downloaded t.t_file < zero then
-          lprintf_nl () "ERROR: file_downloaded < zero!";
-
-  | _ -> ()
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         close_ranges (internal)                       *)
-(*                                                                       *)
-(*************************************************************************)
-
-let rec close_ranges maybe_t s r =
-
-  let added = r.range_end -- r.range_current_begin in
-  add_file_downloaded maybe_t s added;
-  let b = r.range_block in
-  b.block_remaining <- b.block_remaining -- added;
-
-  r.range_current_begin <- r.range_end;
-  match r.range_next with
-    None -> ()
-  | Some rr ->
-      r.range_prev <- None;
-      r.range_next <- None;
-      close_ranges maybe_t s rr
-
+        lprintf_nl "ERROR: file_downloaded < zero!";
+      
+  | _ -> assert false
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         set_downloaded_block                          *)
-(*                                                                       *)
-(*************************************************************************)
+(** Close all the ranges of a block, adding their size to the
+    downloaded amount *)
 
-let set_downloaded_block maybe_t s i =
-  match s.s_blocks.(i) with
-    EmptyBlock ->
-      let block_begin = compute_block_begin s i in
-      let block_end = compute_block_end s i in
-      add_file_downloaded maybe_t s (block_end -- block_begin)
-  | PartialBlock b ->
-      let rec iter r =
-        add_file_downloaded maybe_t s (r.range_end -- r.range_current_begin);
-        r.range_current_begin <- r.range_end;
-        match r.range_next with
-          None -> r.range_prev <- None; r
-        | Some rr ->
-            r.range_prev <- None;
-            r.range_next <- None;
-            iter rr
-      in
-      b.block_ranges <- iter b.block_ranges
-  | _ -> ()
+let close_block_ranges maybe_t s b =
+  iter_block_ranges (fun r ->
+    let added = r.range_end -- r.range_current_begin in
+    add_file_downloaded maybe_t s added;
+    b.block_remaining <- b.block_remaining -- added;
+    r.range_current_begin <- r.range_end;
+    r.range_prev <- None;
+    r.range_next <- None) b;
+  if b.block_remaining <> 0L then
+    lprintf_nl "WARNING: block_remaining should be 0 after close_block_ranges"
 
 (*************************************************************************)
 (*                                                                       *)
@@ -947,146 +946,243 @@
 (*                                                                       *)
 (*************************************************************************)
 
-(* For every swarmer, there is a "primary" verifier, and secondary verifiers.
-When a block is downloaded, it is tagged '2' in the verified_bitmap, and
-this '2' is propagated to the primary bitmap if possible (if all sub-blocks
-are also '2'). If the primary chunk becomes '2', then a verification is
-needed on the primary. If the verification works, the verified_bitmap
-becomes '3', and the secondary verifiers are tagged with '2' (if they use
-a different verification scheme) or '3' (if no verification scheme or
-a verification scheme that has already been used). *)
+(* For every swarmer, there is a "primary" verifier, and secondary
+   verifiers.  When a block is downloaded, it is tagged '2' in the
+   verified_bitmap, and this '2' is propagated to the primary bitmap if
+   possible (if all sub-blocks are also '2'). If the primary chunk
+   becomes '2', then a verification is needed on the primary. If the
+   verification works, the verified_bitmap becomes '3', and the secondary
+   verifiers are tagged with '2' (if they use a different verification
+   scheme) or '3' (if no verification scheme or a verification scheme
+   that has already been used). *)
 
 (* corruption has been detected, and the block has been reset to 0 *)
-let set_bitmap_0 s i =
+let set_swarmer_bitmap_0 s i =
+  (* shouldn't it be > '0' ? *)
   if s.s_verified_bitmap.[i] > '1' then begin
       s.s_verified_bitmap.[i] <- '0';
       List.iter (fun t ->
           let j = t.t_chunk_of_block.(i) in
-          if List.for_all (fun i -> s.s_verified_bitmap.[i] = '0')
-            t.t_blocks_of_chunk.(j) then
-            t.t_converted_verified_bitmap.[j] <- '0'
+	  match t.t_converted_verified_bitmap.[j] with
+	    | '0' -> ()
+	    | '1' ->
+		if List.for_all (fun i -> s.s_verified_bitmap.[i] = '0')
+		  t.t_blocks_of_chunk.(j) then
+		    t.t_converted_verified_bitmap.[j] <- '0'
+	    | '2' -> lprintf_nl "set_swarmer_bitmap_0: invalidating a block within a completed chunk?"
+	    | '3' -> lprintf_nl "set_swarmer_bitmap_0: invalidating a block within a verified chunk?"
+	    | _ -> assert false
       ) s.s_networks
     end
 
 (* we have started downloading this block, so mark all containing blocks
   also as started. *)
-let set_bitmap_1 s i =
-  if s.s_verified_bitmap.[i] = '0' then begin
-      s.s_verified_bitmap.[i] <- '1';
-      List.iter (fun t ->
-          let j = t.t_chunk_of_block.(i) in
-          if t.t_converted_verified_bitmap.[j] = '0' then
-            t.t_converted_verified_bitmap.[j] <- '1'
-      ) s.s_networks
-    end
-
-(* we finished this block, we need know to verify it *)
-let set_bitmap_2 s i =
-  if s.s_verified_bitmap.[i] < '2' then begin
-      s.s_verified_bitmap.[i] <- '2';
-      match s.s_networks with
-      | t :: _ when t.t_primary ->
+let set_swarmer_bitmap_1 s i =
+  match s.s_verified_bitmap.[i] with
+    | '0' ->
+       s.s_verified_bitmap.[i] <- '1';
+	List.iter (fun t ->
           let j = t.t_chunk_of_block.(i) in
-          if List.for_all (fun i -> s.s_verified_bitmap.[i] = '2')
-            t.t_blocks_of_chunk.(j) &&
-            t.t_converted_verified_bitmap.[j] <> '3' then begin
-              t.t_ncomplete_blocks <- t.t_ncomplete_blocks + 1;
-              t.t_converted_verified_bitmap.[j] <- '2'
-            end
-      | [] -> assert false
-      | _ -> ()
-    end
+          match t.t_converted_verified_bitmap.[j] with
+	    | '0' -> t.t_converted_verified_bitmap.[j] <- '1'
+	    | '1' -> ()
+	    | '2' -> lprintf_nl "set_bitmap1: partial block within a completed chunk?"
+	    | '3' -> lprintf_nl "set_bitmap1: partial block within a verified chunk?"
+	    | _ -> assert false
+	) s.s_networks
+    | '1' -> ()
+    | '2' -> lprintf_nl "set_swarmer_bitmap_1: trying to demote a completed block?"
+    | '3' -> lprintf_nl "set_swarmer_bitmap_1: trying to demote a verified block?"
+    | _ -> assert false
+	
 
-(* the primary verifier has worked, so let ask secondary ones for
-verification too *)
-let set_bitmap_3 s i =
-  if s.s_verified_bitmap.[i] < '3' then begin
-      s.s_verified_bitmap.[i] <- '3';
-(*      lprintf "set_bitmap_3 %d done\n" i; *)
-      match s.s_networks with
-        [] -> assert false
-      | tprim :: tail ->
-          List.iter (fun t ->
+(* we finished this block, trying to escalate to primary frontend
+   verification bitmap *)
+let set_swarmer_bitmap_2 s i =
+  match s.s_verified_bitmap.[i] with
+    | '0' | '1' ->
+	(s.s_verified_bitmap.[i] <- '2';
+	match s.s_networks with
+	  | t :: _ ->
+	      assert (t.t_primary);
               let j = t.t_chunk_of_block.(i) in
-              if List.for_all (fun i -> s.s_verified_bitmap.[i] = '3')
-                t.t_blocks_of_chunk.(j) then
-                match t.t_verifier with
-                  NoVerification ->
-                    t.t_converted_verified_bitmap.[j] <- '3'
-                | _ ->
-                    t.t_ncomplete_blocks <- t.t_ncomplete_blocks + 1;
-                    t.t_converted_verified_bitmap.[j] <- '2'
-          ) tail
-    end
+	      (match t.t_converted_verified_bitmap.[j] with
+		| '0' | '1' -> 
+		    if List.for_all (fun i -> s.s_verified_bitmap.[i] = '2')
+		      t.t_blocks_of_chunk.(j) then begin
+			t.t_ncomplete_chunks <- t.t_ncomplete_chunks + 1;
+			t.t_converted_verified_bitmap.[j] <- '2'
+		      end
+		| '2' -> ()
+		| '3' -> lprintf_nl "set_swarmer_bitmap_2: trying to demote a verified block? (1)"
+		| _ -> assert false)
+	  | [] -> assert false)
+    | '2' -> ()
+    | '3' -> lprintf_nl "set_swarmer_bitmap_2: trying to demote a verified block? (2)"
+    | _ -> assert false
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         set_toverify_block (internal)                 *)
-(*                                                                       *)
-(*************************************************************************)
+(* the primary verifier has worked, so let ask secondary ones for
+   verification too *)
+let set_swarmer_bitmap_3 s i =
+  match s.s_verified_bitmap.[i] with
+    | '0' | '1' | '2' ->
+	(s.s_verified_bitmap.[i] <- '3';
+(*      lprintf "set_swarmer_bitmap_3 %d done\n" i; *)
+	match s.s_networks with
+	  | tprim :: secondaries ->
+	      assert (tprim.t_primary);
+	      let jprim = tprim.t_chunk_of_block.(i) in
+	      assert (tprim.t_converted_verified_bitmap.[jprim] = '3');
+              List.iter (fun t ->
+		assert (not t.t_primary);
+		let j = t.t_chunk_of_block.(i) in
+		if List.for_all (fun i -> s.s_verified_bitmap.[i] = '3')
+                  t.t_blocks_of_chunk.(j) then
+                    match t.t_verifier with
+		      | NoVerification ->
+			  (* we have no way to check data integrity
+			     for this network, assume other(s) know
+			     better *)
+			  (match t.t_converted_verified_bitmap.[j] with
+			    | '0' | '1' ->
+				t.t_converted_verified_bitmap.[j] <- '3';
+				t.t_ncomplete_chunks <- t.t_ncomplete_chunks + 1;
+				t.t_nverified_chunks <- t.t_nverified_chunks + 1
+			    | '2' ->
+				t.t_converted_verified_bitmap.[j] <- '3';
+				t.t_nverified_chunks <- t.t_nverified_chunks + 1
+			    | '3' -> ()
+			    | _ -> assert false)
+                      | VerificationNotAvailable 
+		      | ForceVerification
+		      | Verification _ ->
+			  (* all chunks are verified, so set
+			     converted_verified_bitmap to '2',
+			     probably to trigger data verification later.
 
-    (*
-let set_toverify_block s i = set_bitmap_2 s i
-    *)
+			     Is that code necessary at all ? *)
+			  (match t.t_converted_verified_bitmap.[j] with
+			    | '0' | '1' ->
+				t.t_converted_verified_bitmap.[j] <- '2';
+				t.t_ncomplete_chunks <- t.t_ncomplete_chunks + 1
+			    | '2' -> ()
+			    | '3' -> lprintf_nl "set_swarmer_bitmap_3: trying to demote a verified block in another frontend?"
+			    | _ -> assert false)
+              ) secondaries
+	  | [] -> assert false)
+    | '3' -> ()
+    | _ -> assert false
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         set_completed_block (internal)                *)
-(*                                                                       *)
-(*************************************************************************)
+(** set block as completed, closing all remaining ranges, and
+    incrementing amount downloaded by their total size.
+    If the block was empty its whole size is added *)
 
 let set_completed_block maybe_t s i =
-  begin
-    match s.s_blocks.(i) with
-      PartialBlock b -> close_ranges maybe_t s b.block_ranges
-    | _ -> ()
-  end;
+  let mark_completed () =
+    set_swarmer_bitmap_2 s i;
+    s.s_blocks.(i) <- CompleteBlock in
   match s.s_blocks.(i) with
-    CompleteBlock | VerifiedBlock -> ()
-  | _ ->
-      set_downloaded_block maybe_t s i;
-      set_bitmap_2 s i;
-      s.s_blocks.(i) <- CompleteBlock
+  | CompleteBlock | VerifiedBlock -> ()
+  | EmptyBlock ->
+      let block_begin = compute_block_begin s i in
+      let block_end = compute_block_end s i in
+      add_file_downloaded maybe_t s (block_end -- block_begin);
+      mark_completed ()
+  | PartialBlock b ->
+      close_block_ranges maybe_t s b;
+      mark_completed ()
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         set_verified_block (internal)                 *)
-(*                                                                       *)
-(*************************************************************************)
+(** set block as verified, closing all remaining ranges, and
+    incrementing amount downloaded by their total size.
+    If the block was empty its whole size is added 
+
+    (is it normal that no maybe_t can be provided ? my guess is that
+    this function is always called on behalf of a primary frontend) *)
 
 let set_verified_block s j =
   match s.s_blocks.(j) with
-    VerifiedBlock -> ()
+  | VerifiedBlock -> ()
   | _ ->
       set_completed_block None s j;
       s.s_blocks.(j) <- VerifiedBlock;
-      set_bitmap_3 s j
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         set_verified_chunk (internal)                 *)
-(*                                                                       *)
-(*************************************************************************)
+      set_swarmer_bitmap_3 s j
 
-let set_verified_chunk t i =
-  t.t_nverified_blocks <- t.t_nverified_blocks + 1;
-  t.t_converted_verified_bitmap.[i] <- '3';
+(* We've seen how swarmer verification propagates to the frontend(s)
+   verifications, now let's see the reverse *)
+	
+let set_frontend_bitmap_0 t j =
+  assert(t.t_converted_verified_bitmap.[j] = '2');
   let s = t.t_s in
-  if t.t_primary then begin
-    (* The primary is supposed to propagate verified chunks to the file *)
-      List.iter (fun j -> set_verified_block s j) t.t_blocks_of_chunk.(i);
-      if !verbose_swarming then
-        print_s "VERIFIED" s
+  assert(List.for_all (fun i -> s.s_verified_bitmap.[i] <> '3') t.t_blocks_of_chunk.(j));
+  t.t_ncomplete_chunks <- t.t_ncomplete_chunks - 1;
+  if List.for_all (fun i -> s.s_verified_bitmap.[i] = '2') t.t_blocks_of_chunk.(j) then begin
+      if !verbose_swarming || !verbose then
+        lprintf_nl "Complete block %d/%d of %s failed verification, reloading..."
+          (j + 1) t.t_nchunks (file_best_name t.t_file);
+      
+      t.t_converted_verified_bitmap.[j] <- '0';
+      List.iter (fun i ->
+        match s.s_blocks.(i) with
+	  | EmptyBlock -> set_swarmer_bitmap_0 s i
+          | PartialBlock _ ->  set_swarmer_bitmap_1 s i
+          | CompleteBlock ->
+              let block_begin = compute_block_begin s i in
+              let block_end = compute_block_end s i in
+	      (* negative *)
+              add_file_downloaded None s (block_begin -- block_end);
+	      
+              s.s_blocks.(i) <- EmptyBlock;
+              set_swarmer_bitmap_0 s i
+		
+          | VerifiedBlock -> assert false
+      ) t.t_blocks_of_chunk.(j)
     end
+  else begin
+    (* afaiu not supposed to happen, so this code is for debugging ? *)
+    if !verbose_swarming then begin
+      let nsub = ref 0 in
+      lprintf_n "  Swarmer was incomplete: ";
+      List.iter (fun i ->
+        lprintf "%c" s.s_verified_bitmap.[i];
+        if s.s_verified_bitmap.[i] = '2' then incr nsub;
+      ) t.t_blocks_of_chunk.(j);
+      lprintf_nl2 "   = %d/%d" !nsub (List.length t.t_blocks_of_chunk.(j))
+    end;
+    t.t_converted_verified_bitmap.[j] <- '1'
+  end
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         verify (internal)                             *)
-(*                                                                       *)
-(*************************************************************************)
+(* aka set_verified_chunk (internal) *)
 
-let verify t chunks num begin_pos end_pos =
-  file_verify t.t_file chunks.(num) begin_pos end_pos
+let set_frontend_bitmap_3 t j =
+  let mark_verified () =
+    t.t_converted_verified_bitmap.[j] <- '3';
+    if !verbose_swarming || !verbose then
+      lprintf_nl "Completed block %d/%d of %s"
+        (j + 1) t.t_nchunks (file_best_name t.t_file);
+    if t.t_primary then begin
+      let s = t.t_s in
+      (* The primary is supposed to propagate verified chunks to the file *)
+      List.iter (fun i -> set_verified_block s i) t.t_blocks_of_chunk.(j);
+      if !verbose_swarming then
+	print_s "VERIFIED" s
+    end;
+    t.t_verified t.t_nverified_chunks j in
+  match t.t_converted_verified_bitmap.[j] with
+    | '0' | '1' ->
+	t.t_ncomplete_chunks <- t.t_ncomplete_chunks + 1;
+	t.t_nverified_chunks <- t.t_nverified_chunks + 1;
+	mark_verified ();
+    | '2' ->
+	t.t_nverified_chunks <- t.t_nverified_chunks + 1;
+	mark_verified ();
+    | '3' -> ()
+    | _ -> assert false
+
+(** Check the equality of the hash of [t]'s data between offsets
+    [begin_pos] and [end_pos] against the value of [uid] *)
+
+let verify t uid begin_pos end_pos =
+  file_verify t.t_file uid begin_pos end_pos
 
 (*************************************************************************)
 (*                                                                       *)
@@ -1094,163 +1190,62 @@
 (*                                                                       *)
 (*************************************************************************)
 
-let verify_chunk t i =
-  if t.t_converted_verified_bitmap.[i] = '2' then
-    let nblocks = String.length t.t_converted_verified_bitmap in
+let string_for_all p s =
+  let l = String.length s in
+  let rec aux i =
+    i >= l || p s.[i] && aux (i+1) in
+  aux 0
+
+let string_iter f s =
+  let l = String.length s in
+  let rec aux i =
+    if i < l then begin
+      f i s.[i];
+      aux (i+1)
+    end in 
+  aux 0
+
+let verify_chunk t j =
+  if t.t_converted_verified_bitmap.[j] = '2' then
+    let nchunks = String.length t.t_converted_verified_bitmap in
     match t.t_verifier with
-      NoVerification
+    | NoVerification
     | VerificationNotAvailable -> ()
 
     | ForceVerification ->
-        set_verified_chunk t i;
-        t.t_verified t.t_nverified_blocks i
-
-    | Verification chunks when Array.length chunks = nblocks ->
-
-        begin try
-            let s = t.t_s in
-            let block_begin = t.t_block_size *.. i in
-            let block_end = block_begin ++ t.t_block_size in
-            let block_end = min block_end s.s_size in
-            if verify t chunks i block_begin block_end then
-	      begin
-                set_verified_chunk t i;
-                t.t_verified t.t_nverified_blocks i;
-                if !verbose_swarming || !verbose then
-		  lprintf_nl () "Completed block %d/%d of %s"
-                    (i + 1) t.t_nchunks (file_best_name t.t_file)
-              end
-	    else
-	      begin
-                t.t_ncomplete_blocks <- t.t_ncomplete_blocks - 1;
-
-                if List.for_all (fun i ->
-                      s.s_verified_bitmap.[i] = '2'
-                  ) t.t_blocks_of_chunk.(i)
-		then
-		  begin
-		    if !verbose_swarming || !verbose then
-                      lprintf_nl () "Complete block %d/%d of %s failed verification, reloading..."
-                            (i + 1) t.t_nchunks (file_best_name t.t_file);
-
-                    t.t_converted_verified_bitmap.[i] <- '0';
-
-                    List.iter (fun i ->
-                        match s.s_blocks.(i) with
-                          EmptyBlock -> set_bitmap_0 s i
-                        | PartialBlock _ ->  set_bitmap_1 s i
-                        | CompleteBlock ->
-                            let block_begin = compute_block_begin s i in
-                            let block_end = compute_block_end s i in
-                            add_file_downloaded None s (block_begin -- block_end);
+        set_frontend_bitmap_3 t j
 
-                            s.s_blocks.(i) <- EmptyBlock;
-                            set_bitmap_0 s i
+    | Verification uids when Array.length uids = nchunks ->
 
-                        | VerifiedBlock -> assert false
-                    ) t.t_blocks_of_chunk.(i)
-                  end
-		else
-		  begin
-		    if !verbose_swarming then begin
-                      let nsub = ref 0 in
-                        lprintf_n () "  Swarmer was incomplete: ";
-                        List.iter (fun i ->
-                          lprintf "%c" s.s_verified_bitmap.[i];
-                          if s.s_verified_bitmap.[i] = '2' then incr nsub;
-                        ) t.t_blocks_of_chunk.(i);
-                        lprintf_nl2 "   = %d/%d" !nsub (List.length t.t_blocks_of_chunk.(i))
-		    end;
-                    t.t_converted_verified_bitmap.[i] <- '1'
-                  end;
-              end
-          with VerifierNotReady -> ()
-        end
+        (try
+          let s = t.t_s in
+          let chunk_begin = t.t_chunk_size *.. j in
+          let chunk_end = chunk_begin ++ t.t_chunk_size in
+          let chunk_end = min chunk_end s.s_size in
+          if verify t uids.(j) chunk_begin chunk_end then
+            set_frontend_bitmap_3 t j
+	  else
+	    set_frontend_bitmap_0 t j
+        with VerifierNotReady -> ())
 
     | Verification chunks ->
+	(* network only provides a hash for the whole file ? *)
         assert (Array.length chunks = 1);
-        let can_verify = ref true in
-        let nblocks= String.length t.t_converted_verified_bitmap in
-        for i = 0 to nblocks - 1 do
-          if t.t_converted_verified_bitmap.[i] < '2' then
-            can_verify := false
-        done;
-        if !can_verify then begin
-            try
-              let s = t.t_s in
-              if verify t chunks 0 zero s.s_size then begin
-                  for i = 0 to nblocks - 1 do
-                    if t.t_converted_verified_bitmap.[i] = '2' then begin
-
-                        set_verified_chunk t i;
-                        t.t_verified t.t_nverified_blocks i;
-                      end
-                  done
-
-              end else begin
-
-                lprintf_nl () "Verification of blocks for file %s FAILED\n"
-                    (file_best_name t.t_file);
-
-                  for i = 0 to nblocks - 1 do
-                    if t.t_converted_verified_bitmap.[i] = '2' then begin
-
-                        t.t_ncomplete_blocks <- t.t_ncomplete_blocks - 1;
-                        if List.for_all (fun i ->
-                              s.s_verified_bitmap.[i] = '2'
-                          ) t.t_blocks_of_chunk.(i) then begin
-
-                            t.t_converted_verified_bitmap.[i] <- '0';
-
-                            List.iter (fun i ->
-                                match s.s_blocks.(i) with
-                                  EmptyBlock -> set_bitmap_0 s i
-                                | PartialBlock _ ->  set_bitmap_1 s i
-                                | CompleteBlock ->
-                                    let block_begin = compute_block_begin s i in
-                                    let block_end = compute_block_end s i in
-                                    add_file_downloaded None s (block_begin -- block_end);
-
-                                    s.s_blocks.(i) <- EmptyBlock;
-                                    set_bitmap_0 s i
-
-                                | VerifiedBlock -> assert false
-                            ) t.t_blocks_of_chunk.(i)
-                          end else begin
-                            let nsub = ref 0 in
-
-                            lprintf_n () "  Swarmer was incomplete: ";
-                            List.iter (fun i ->
-                                lprintf "%c" s.s_verified_bitmap.[i];
-                                if s.s_verified_bitmap.[i] = '2' then incr nsub;
-                                ) t.t_blocks_of_chunk.(i);
-                            lprintf_nl2 "   = %d/%d" !nsub (List.length t.t_blocks_of_chunk.(i));
+(*        let nchunks = String.length t.t_converted_verified_bitmap in *)
 
-                            t.t_converted_verified_bitmap.[i] <- '1'
-                          end;
-                      end
-                  done
-              end
+	if string_for_all (fun x -> x >= '2') t.t_converted_verified_bitmap then
+          try
+            let s = t.t_s in
+            if verify t chunks.(0) zero s.s_size then
+	      string_iter (fun j _ ->
+		set_frontend_bitmap_3 t j
+	      ) t.t_converted_verified_bitmap
+	    else
+	      string_iter (fun j c ->
+		if c = '2' then set_frontend_bitmap_0 t j
+	      ) t.t_converted_verified_bitmap
           with VerifierNotReady -> ()
-        end
-
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         must_verify_chunk (internal)                  *)
-(*                                                                       *)
-(*************************************************************************)
 
-            (*
-let must_verify_chunk t i immediatly =
-  match t.t_verifier with
-    NoVerification -> ()
-  | _ ->
-      if t.t_converted_verified_bitmap.[i] < '2' then
-        set_toverify_chunk t i;
-      if t.t_converted_verified_bitmap.[i] = '2' && immediatly then
-        verify_chunk t i
-          *)
 
 (*************************************************************************)
 (*                                                                       *)
@@ -1259,7 +1254,7 @@
 (*************************************************************************)
 
 let must_verify_block s i immediatly =
-  set_bitmap_2 s i;
+  set_swarmer_bitmap_2 s i;
   if immediatly then
     match s.s_networks with
       [] -> assert false
@@ -1296,7 +1291,7 @@
 
 
 let compute_bitmap t =
-  if t.t_ncomplete_blocks > t.t_nverified_blocks then begin
+  if t.t_ncomplete_chunks > t.t_nverified_chunks then begin
       for i = 0 to String.length t.t_converted_verified_bitmap - 1 do
         if t.t_converted_verified_bitmap.[i] = '2' then
             verify_chunk t i
@@ -1384,38 +1379,10 @@
 
   s.s_blocks.(i) <- PartialBlock b;
   if s.s_verified_bitmap.[i] < '1' then
-    set_bitmap_1 s i;
-  if debug_all then lprintf_nl () "NB[%s]" s.s_verified_bitmap;
+    set_swarmer_bitmap_1 s i;
+  if debug_all then lprintf_nl "NB[%s]" s.s_verified_bitmap;
   b
 
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         next_range (internal)                         *)
-(*                                                                       *)
-(*************************************************************************)
-
-(*
-let next_range f r =
-  match r.range_next with
-    None -> ()
-  | Some rr -> f rr
-        *)
-
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         add_all_downloaded                            *)
-(*                                                                       *)
-(*************************************************************************)
-
-(*
-let add_all_downloaded t old_downloaded =
-  let new_downloaded = t.t_downloaded in
-  if new_downloaded <> old_downloaded then
-    add_file_downloaded t.t_file (new_downloaded -- old_downloaded)
-    *)
-
 (*************************************************************************)
 (*                                                                       *)
 (*                         range_received (internal)                     *)
@@ -1490,7 +1457,7 @@
 (*    lprintf "iter range %Ld-%Ld\n" r.range_begin r.range_end; *)
     (try range_received None r chunk_begin chunk_end
       with e ->
-          lprintf_nl () "EXCEPTION IN range_received: %s"
+          lprintf_nl "EXCEPTION IN range_received: %s"
             (Printexc2.to_string e);
           exit 2);
     match range_next with
@@ -1512,7 +1479,7 @@
 
 let set_present s chunks =
 
-  apply_intervals s (fun i block_begin block_end chunk_begin chunk_end ->
+  iter_intervals s (fun i block_begin block_end chunk_begin chunk_end ->
 (*      lprintf "interval: %Ld-%Ld in block %d [%Ld-%Ld]\n"
       chunk_begin chunk_end i block_begin block_end;  *)
       match s.s_blocks.(i) with
@@ -1584,10 +1551,10 @@
 
 let chunks_to_string s chunks =
   match chunks with
-      AvailableRanges chunks ->
+      AvailableIntervals chunks ->
         begin
           let st = String.make (Array.length s.s_blocks) '0' in
-          apply_intervals s (fun i block_begin block_end chunk_begin chunk_end -> st.[i] <- '1') chunks;
+          iter_intervals s (fun i block_begin block_end chunk_begin chunk_end -> st.[i] <- '1') chunks;
           st
         end
   | AvailableCharBitmap st -> st
@@ -1610,11 +1577,11 @@
 
     begin
       match chunks with
-        AvailableRanges chunks ->
+        AvailableIntervals chunks ->
 
-          apply_intervals s (fun i block_begin block_end
+          iter_intervals s (fun i block_begin block_end
                 chunk_begin chunk_end ->
-(*              lprintf "apply_intervals %d %Ld-%Ld %Ld-%Ld\n"
+(*              lprintf "iter_intervals %d %Ld-%Ld %Ld-%Ld\n"
                 i block_begin block_end chunk_begin chunk_end; *)
               s.s_availability.(i) <- s.s_availability.(i) + 1;
 
@@ -1662,7 +1629,7 @@
     up.up_ncomplete <- Array.length complete_blocks;
 
     if Array.length partial_blocks > 0 then
-      lprintf_nl () "WARNING: partial_blocks = %d" (Array.length partial_blocks);
+      lprintf_nl "WARNING: partial_blocks = %d" (Array.length partial_blocks);
     up.up_partial_blocks <- partial_blocks;
     up.up_npartial <- Array.length partial_blocks;
 
@@ -1826,10 +1793,10 @@
   | PartialBlock b ->
       b, b.block_begin, b.block_end
   | VerifiedBlock ->
-      lprintf_nl () "ERROR: verified block in permute_and_return %d\n" b;
+      lprintf_nl "ERROR: verified block in permute_and_return %d\n" b;
       assert false
   | CompleteBlock ->
-      lprintf_nl () "ERROR: complete block in permute_and_return %d\n" b;
+      lprintf_nl "ERROR: complete block in permute_and_return %d\n" b;
       assert false
 
 (*************************************************************************)
@@ -1917,7 +1884,7 @@
 
 let random_int max =
   let x = Random.int max in
-  if debug_all then lprintf_nl () "(Random %d -> %d)" max x;
+  if debug_all then lprintf_nl "(Random %d -> %d)" max x;
   x
 
 let select_block up =
@@ -1955,7 +1922,7 @@
 (*************   Try to download the movie index and the first minute to
    allow preview of the file as soon as possible *)
 
-                if debug_all then lprintf_nl () "{First}";
+                if debug_all then lprintf_nl "{First}";
 
                 let download_first n b =
 (*                lprintf "download_first %d\n" n; *)
@@ -1989,7 +1956,7 @@
 (************* If the file can be verified, and we don't have a lot of blocks
     yet, try to download the partial ones as soon as possible *)
 
-                if debug_all then lprintf_nl () "{PartialBlock}";
+                if debug_all then lprintf_nl "{PartialBlock}";
 
                 let download_partial max_uploaders =
                   let partial_block = ref (-1) in
@@ -2013,14 +1980,14 @@
                 in
 
                 if t.t_verifier <> NoVerification &&
-                  t.t_nverified_blocks  < 2  then begin
+                  t.t_nverified_chunks  < 2  then begin
                     download_partial max_nuploaders;
                   end;
 
 (************* Download partial chunks from the verification point of view *)
 
                 if List.length s.s_networks > 1 then begin
-                    if debug_all then lprintf_n () "{PartialChunk}";
+                    if debug_all then lprintf_n "{PartialChunk}";
 
                     let my_t = if t.t_verifier <> NoVerification then t
                       else match s.s_networks with t :: _ -> t | _ -> t in
@@ -2058,7 +2025,7 @@
                       done;
                       if !partial_block <> -1 then begin
                           if !verbose_swarming then
-                            lprintf_n () "PartialChunk won for %d waiting blocks"
+                            lprintf_n "PartialChunk won for %d waiting blocks"
                               !partial_remaining;
                           raise (BlockFound !partial_block)
                         end
@@ -2179,7 +2146,7 @@
         if debug_all then lprintf " = %d \n" num;
         b
   with e ->
-      if debug_all then lprintf_nl () "Exception %s" (Printexc2.to_string e);
+      if debug_all then lprintf_nl "Exception %s" (Printexc2.to_string e);
       raise e
 
 (*************************************************************************)
@@ -2274,7 +2241,7 @@
             up.up_ranges <- up.up_ranges @ [key];
             r.range_nuploading <- r.range_nuploading + 1;
             if r.range_current_begin = r.range_end then
-              lprintf_nl () "error: range is empty error";
+              lprintf_nl "error: range is empty error";
             key
           end else
         match r.range_next with
@@ -2309,7 +2276,7 @@
     let file_end = file_begin ++ (Int64.of_int string_len) in
 
     if !verbose_swarming then
-      lprintf_nl () "received on %Ld-%Ld" file_begin file_end;
+      lprintf_nl "received on %Ld-%Ld" file_begin file_end;
 
 (* TODO: check that everything we received has been required *)
     let t = up.up_t in
@@ -2340,13 +2307,13 @@
                       string_len < string_length then begin
                         if !verbose then
                         begin
-                        lprintf_nl () "BAD WRITE in %s for range %Ld-%Ld (string_pos %d)"
+                        lprintf_nl "BAD WRITE in %s for range %Ld-%Ld (string_pos %d)"
                           (file_best_name t.t_file) r.range_begin r.range_end string_pos;
-                        lprintf_nl () "  received: file_pos:%Ld string:%d %d"
+                        lprintf_nl "  received: file_pos:%Ld string:%d %d"
                           file_begin string_begin string_len;
-                        lprintf_nl () "  ranges:";
+                        lprintf_nl "  ranges:";
                         List.iter (fun (_,_,r) ->
-                            lprintf_n () "     range: %Ld-[%Ld]-%Ld"
+                            lprintf_n "     range: %Ld-[%Ld]-%Ld"
                               r.range_begin r.range_current_begin
                               r.range_end;
                             (match r.range_next with
@@ -2359,7 +2326,7 @@
                                   lprintf "  prev: %Ld" rr.range_begin);
                             lprint_newline ();
                             let b = r.range_block in
-                            lprintf_n () "        block: %d[%c] %Ld-%Ld [%s]"
+                            lprintf_n "        block: %d[%c] %Ld-%Ld [%s]"
                               b.block_num
                               s.s_verified_bitmap.[b.block_num]
                               b.block_begin b.block_end
@@ -2408,7 +2375,7 @@
 
   let rec iter_block_out i block_begin list =
     if debug_present_chunks then
-      lprintf_nl () "iter_block_out %d bb: %Ld"
+      lprintf_nl "iter_block_out %d bb: %Ld"
         i block_begin;
 
     if i = nblocks then List.rev list else
@@ -2424,7 +2391,7 @@
 
   and iter_block_in i block_begin chunk_begin list =
     if debug_present_chunks then
-      lprintf_nl () "iter_block_in %d bb: %Ld cb:%Ld"
+      lprintf_nl "iter_block_in %d bb: %Ld cb:%Ld"
         i block_begin chunk_begin
       ;
 
@@ -2444,7 +2411,7 @@
 
   and iter_range_out i block_end block_begin r list =
     if debug_present_chunks then
-      lprintf_nl () "iter_range_out %d nb: %Ld bb:%Ld"
+      lprintf_nl "iter_range_out %d nb: %Ld bb:%Ld"
         i block_end block_begin;
 
     if r.range_begin > block_begin then
@@ -2476,7 +2443,7 @@
 
   and iter_range_in i block_end chunk_begin chunk_end r list =
     if debug_present_chunks then
-      lprintf_nl () "iter_range_in %d bn: %Ld cb:%Ld ce: %Ld"
+      lprintf_nl "iter_range_in %d bn: %Ld cb:%Ld ce: %Ld"
         i block_end chunk_begin chunk_end;
 
     if r.range_current_begin < r.range_end then
@@ -2550,7 +2517,7 @@
           sw := (t, i, pos) :: !sw;
           iter (i+1) len (pos ++ bsize) bsize size
       in
-      iter 0 (Array.length t.t_checksums) zero t.t_block_size t.t_size
+      iter 0 (Array.length t.t_checksums) zero t.t_chunk_size t.t_size
   ) swarmers_by_num;
   Hashtbl.iter (fun c (has, has_not) ->
       match !has, !has_not with
@@ -2600,7 +2567,7 @@
     match bitmap.[i] with
     | '2' ->
         if t.t_converted_verified_bitmap.[i] < '2' then begin
-            t.t_ncomplete_blocks <- t.t_ncomplete_blocks + 1;
+            t.t_ncomplete_chunks <- t.t_ncomplete_chunks + 1;
             t.t_converted_verified_bitmap.[i] <- '2'
           end
 
@@ -2625,7 +2592,7 @@
                   ()
           ) t.t_blocks_of_chunk.(i);
           if t.t_converted_verified_bitmap.[i] <> '3' then
-            lprintf_nl () "FIELD AS BEEN CLEARED"
+            lprintf_nl "FIELD AS BEEN CLEARED"
     | _ -> ()
   done
 
@@ -2794,7 +2761,7 @@
             (get_value  "file_all_chunks" value_to_string)
 
     with e ->
-        lprintf_nl () "Exception %s while loading bitmap"
+        lprintf_nl "Exception %s while loading bitmap"
           (Printexc2.to_string e);
   );
 
@@ -2804,7 +2771,7 @@
 *)
 
   if primary then begin
-      if !verbose_swarming then lprintf_nl () "Loading present...";
+      if !verbose_swarming then lprintf_nl "Loading present...";
       let present = try
           let present =
             (get_value "file_present_chunks"
@@ -2813,46 +2780,46 @@
           set_present t present;
           present
         with e ->
-            lprintf_nl () "Exception %s while set present"
+            lprintf_nl "Exception %s while set present"
               (Printexc2.to_string e);
             []
       in
-      if !verbose_swarming then lprintf_nl () "Downloaded after present %Ld" (downloaded t);
+      if !verbose_swarming then lprintf_nl "Downloaded after present %Ld" (downloaded t);
 
 (*
-      if !verbose then lprintf_nl () "Loading absent...";
+      if !verbose then lprintf_nl "Loading absent...";
       (try
           set_absent t
             (get_value "file_absent_chunks"
               (value_to_list value_to_int64_pair));
         with e ->
-            if !verbose_hidden_errors then lprintf_nl () "Exception %s while set absent"
+            if !verbose_hidden_errors then lprintf_nl "Exception %s while set absent"
               (Printexc2.to_string e);
       );
-      if !verbose then lprintf_nl () "Downloaded after absent %Ld" (downloaded t);
+      if !verbose then lprintf_nl "Downloaded after absent %Ld" (downloaded t);
 *)
       (try
           let d = get_value "file_downloaded" value_to_int64 in
 
           if d <> downloaded t && !verbose then begin
-              lprintf_nl () "ERROR: stored downloaded value not restored  !!! (%Ld/%Ld)" (downloaded t) d;
-              lprintf_nl () "ERROR: present:";
+              lprintf_nl "ERROR: stored downloaded value not restored  !!! (%Ld/%Ld)" (downloaded t) d;
+              lprintf_nl "ERROR: present:";
               List.iter (fun (x,y) ->
-                  lprintf_nl () "     (%Ld,%Ld);" x y
+                  lprintf_nl "     (%Ld,%Ld);" x y
               ) present;
 
               let p = present_chunks t in
-              lprintf_nl () "ERROR: present now:";
+              lprintf_nl "ERROR: present now:";
 
               let total = ref zero in
               List.iter (fun (x,y) ->
-                  lprintf_nl () "     (%Ld,%Ld);" x y;
+                  lprintf_nl "     (%Ld,%Ld);" x y;
                   total := !total ++ (y -- x);
               ) p;
 
-              lprintf_nl () "ERROR: total %Ld" !total;
+              lprintf_nl "ERROR: total %Ld" !total;
               if p = present then begin
-                  lprintf_nl () "ERROR: both appear to be the same!";
+                  lprintf_nl "ERROR: both appear to be the same!";
                 end;
         if !exit_on_error then exit 2
             end
@@ -2955,7 +2922,7 @@
   let s1 = HS.find swarmers_by_name { dummy_swarmer with s_filename = file_disk_name f1 } in
   let s2 = HS.find swarmers_by_name { dummy_swarmer with s_filename = file_disk_name f2 } in
 
-  if s1 == s2 then
+  if s1.s_filename = s2.s_filename then
     failwith "Files are already sharing their swarmer";
 
   if s1.s_size <> s2.s_size then
@@ -2964,7 +2931,7 @@
   let t2 = match s2.s_networks with
       [t] -> t
     | list ->
-        lprintf_nl () "s_networks: %d files" (List.length list);
+        lprintf_nl "s_networks: %d files" (List.length list);
         failwith "Second file is already merged with other files"
   in
 
@@ -3012,7 +2979,7 @@
     None -> () 
   | Some sw -> if not (has_secondaries sw)
                 then HS.remove swarmers_by_name sw.t_s
-                else lprintf_nl () "Tried to remove swarmer with secondaries"
+                else lprintf_nl "Tried to remove swarmer with secondaries"
 
 (*************************************************************************)
 (*                                                                       *)
@@ -3037,7 +3004,7 @@
           let get_value name conv = conv (List.assoc name assocs) in
           let file_size = get_value "file_size" value_to_int64 in
           let file_name = get_value "file_name" value_to_string in
-          let s = create_swarmer file_name file_size edonkey_range_size in
+          let s = create_swarmer file_name file_size in
           let block_sizes = get_value "file_chunk_sizes"
               (value_to_list value_to_int64) in
           List.iter (fun bsize ->
@@ -3053,7 +3020,7 @@
         ("file_name", string_to_value s.s_filename);
         ("file_bitmap", string_to_value s.s_verified_bitmap);
         ("file_chunk_sizes", list_to_value int64_to_value
-            (List.map (fun t -> t.t_block_size) s.s_networks));
+            (List.map (fun t -> t.t_chunk_size) s.s_networks));
         ]
 
     let t =
@@ -3190,7 +3157,7 @@
             List.length up.up_ranges * (12 + 16 + 12 + 12 +  4) +
             Array.length up.up_partial_blocks * (16 + 12 + 12) +
             (8 + match up.up_chunks with
-              AvailableRanges list -> List.length list * (12 + 12 + 12 + 12)
+              AvailableIntervals list -> List.length list * (12 + 12 + 12 + 12)
             | AvailableCharBitmap s -> 8 + String.length s
             | AvailableBitv b -> let ws = Sys.word_size in (ws/8) + ((ws / 8) * (Bitv.length b / (ws - 2))) 
           ) ;
@@ -3211,7 +3178,7 @@
           if bitmap.[i] <> '3' then raise Not_found;
         done;
         if file_size file <> downloaded t then
-          lprintf_nl () "Downloaded size differs after complete verification";
+          lprintf_nl "Downloaded size differs after complete verification";
         true
   with _ -> false
 
