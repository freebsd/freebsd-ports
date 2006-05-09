--- ./src/daemon/common/commonSwarming.ml.orig	Mon Apr 10 14:06:20 2006
+++ ./src/daemon/common/commonSwarming.ml	Sun May  7 06:39:10 2006
@@ -17,6 +17,26 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *)
 
+(*                      OVERALL SCHEMA
+
+Each network frontend can have a different (fixed) chunk size
+t1 +--------+--------+--------+--------+--------+--------+-------- chunks
+t2 +------+------+------+------+------+------+------+------+------ chunks
+
+ each block is contained in at most /\ chunk_of_block
+         one chunk, for any network ||                            mappings 
+                                    \/ blocks_of_chunk
+swarmer
+   +------+-+----+---+--+------+------++-----+--+---+----+-+------ blocks
+    |      | |    |   |  |      |    ...                      variable size
+    v      v v    v   v  v      v
+    r<>r   r r    r   r  r<>r   r<>r                               ranges
+                            ^                      one dbl linked list/block
+                            |                    encoding missing data ranges
+uploaders physically     uploader
+reference ranges
+*)
+
 open Int64ops
 open Options
 open Printf2
@@ -25,7 +45,6 @@
 
   
 let check_swarming = false
-let debug_present_chunks = false
 let debug_all = false
 
 open CommonTypes
@@ -37,11 +56,8 @@
 
 exception VerifierNotReady
 
-type chunks =
-  AvailableRanges of (int64 * int64) list
-(* A bitmap is encoded with '0' for empty, '1' for present '2' complete '3' verified *)
-| AvailableCharBitmap of string 
-(* A bitmap encoded as a bit vector *)
+type intervals =
+  AvailableIntervals of (int64 * int64) list
 | AvailableBitv of Bitv.t
 
 type verification =
@@ -54,18 +70,17 @@
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
@@ -93,6 +108,8 @@
 
 *)
 
+(* only used in code (currently disabled) for finding duplicate chunks *)
+
 type chunk = {
     chunk_uid : uid_type;
     chunk_size : int64;
@@ -102,20 +119,27 @@
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
@@ -124,12 +148,12 @@
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
 
@@ -156,20 +180,21 @@
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
     mutable range_block : block;
-    mutable range_begin : Int64.t; (* official begin int64 *)
+    mutable range_begin : Int64.t;
     mutable range_end : Int64.t;
     mutable range_prev : range option;
     mutable range_next : range option;
-    mutable range_current_begin : Int64.t; (* current begin pos *)
-(*        mutable range_verified : bool; *)
-    mutable range_nuploading : int; (* current number of clients
-				       filling that range ? *)
+    mutable range_nuploading : int; (* number of uploaders currently
+				       referencing that range *)
   }
 
 and uploader = {
@@ -178,7 +203,7 @@
 
     mutable up_declared : bool;
 
-    mutable up_chunks : chunks;
+    mutable up_intervals : intervals;
     mutable up_complete_blocks : int array; (** block numbers *)
     mutable up_ncomplete : int;
 
@@ -193,11 +218,14 @@
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
+   missing between offsets range_begin and range_end.
 
    [block]'s [block_ranges] reference the first (smallest offsets) of
    the [range]s associated with it. 
@@ -216,12 +244,59 @@
    overlap, and are sorted in increasing offsets order:
 
    b.block_begin <= b.block_ranges.block_begin ... <=
-   r.range_prev.range_end <= r.range_begin <= r.range_current_begin <=
+   r.range_prev.range_end <= r.range_begin <=
    r.range_end <= r.range_next.range_begin <= ...
-   <= b.block_end
+   <= b.block_end *)
    
-   Role played by r.range_current_begin is unclear for now. *)
+(* range owners are only used thru uploaders.up_ranges. blocks could be
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
+   b.block_remaining = sum (r.range_end - r.range_begin) b.block_ranges
+*)
+
+(* swarmer invariants ?
+   s.s_verified_bitmap.[i] = 0 <=> s_blocks.[i] = EmptyBlock
+   s.s_verified_bitmap.[i] = 1 <=> s_blocks.[i] = PartialBlock _
+   s.s_verified_bitmap.[i] = 2 <=> s_blocks.[i] = CompletedBlock
+   s.s_verified_bitmap.[i] = 3 <=> s_blocks.[i] = VerifiedBlock
+   If so, why not drop s_verified_bitmap, and replace it by some
+   verified_bitmap s i and verified_bitmap_all s functions ?
+*)
+
+(* frontend invariants ?
+   t_ncomplete_chunks = 
+   List.length (List.filter (fun x -> x >= '2') t_converted_verified_bitmap)
+   t_nverified_chunks = 
+   List.length (List.filter (fun x -> x = '3') t_converted_verified_bitmap)
+
+   hence t_ncomplete_chunks >= t_nverified_chunks
+
+   All chunks are [t_chunk_size] bytes in size, and first start at
+   offset 0. This is assumed in [associate], [verify_chunk], maybe more.
+*)
+
+(* uploaders invariants ?
+   At first, I supposed
+   up_ncomplete = Array.length up_complete_blocks 
+   up.up_npartial = Array.length up_partial_blocks
+   if so, since Array.length complexity is O(1), why keep them ?
 
+   => see permute_and_return, they're used to simulate to removal of 
+   elements without array reallocation
+
+   So the question is now, aren't there better datastructures than
+   arrays for the job ?
+*)
 
 (*************************************************************************)
 (*                                                                       *)
@@ -251,8 +326,6 @@
 
 let swarmer_counter = ref 0
 
-let has_multinet = true
-
 (*************************************************************************)
 (*                                                                       *)
 (*                         dummy_swarmer                                 *)
@@ -276,10 +349,10 @@
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
@@ -289,23 +362,37 @@
     associated file's [t.t_file] last seen value to the oldest of the
     remaining last seen values *)
 
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
 let compute_last_seen t =
   let last_seen_total = ref (BasicSocket.last_time ()) in
-  for i = 0 to String.length t.t_converted_verified_bitmap - 1 do
-    if t.t_converted_verified_bitmap.[i] > '2' then
+  string_iter (fun i c -> 
+    if c > '2' then
       t.t_last_seen.(i) <- BasicSocket.last_time ()
     else
       last_seen_total := min !last_seen_total t.t_last_seen.(i)
-  done;
+  ) t.t_converted_verified_bitmap;
   set_file_last_seen t.t_file !last_seen_total;
   t.t_last_seen
 
 (** if a swarmer is already associated with that [file_name], return it;
-    Otherwise create a new one with default values (including a default
-    [range_size] instead of the provided value ??) *)
-
-let create_swarmer file_name file_size range_size =
+    Otherwise create a new one with default values, that will be fixed
+    by the first frontend association *)
 
+let create_swarmer file_name file_size =
   try
     HS.find swarmers_by_name
       { dummy_swarmer with
@@ -314,9 +401,7 @@
   with Not_found ->
       incr swarmer_counter;
 
-(* Let be VERY conservative... *)
-      let range_size = edonkey_range_size in
-
+      let range_size = edonkey_range_size in (* yuck ? *)
       let nchunks = 1 in
       let rec s = {
 
@@ -357,6 +442,43 @@
   let b = s.s_block_pos in
   b.(i)
 
+(** Finds the number of the block containing [chunk_pos] offset, using
+    dichotomy. Blocks are half opened [block_begin, block_end[ *)
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
 
@@ -368,19 +490,40 @@
       range_end = pos;
       range_block = b;
       range_nuploading = 0;
-      range_current_begin = pos;
     }
   in
   r
 
+let rec ranges_iter f r =
+  f r;
+  match r.range_next with
+  | None -> ()
+  | Some r ->
+      ranges_iter f r
+
+let rec ranges_fold f acc r =
+  let acc = f acc r in
+  match r.range_next with
+  | None -> acc
+  | Some rr -> ranges_fold f acc rr
+
+let rec ranges_for_all p r =
+  p r && 
+    (match r.range_next with
+     | None -> true
+     | Some r -> ranges_for_all p r)
+
+let block_ranges_for_all p b =
+  ranges_for_all p b.block_ranges
+
+let block_ranges_fold f acc b =
+  ranges_fold f acc b.block_ranges
+
 (** (internal) assigns range [r], and all other ranges along
     [range_next] links, to block [b] *)
 
 let rec own_ranges b r =
-  r.range_block <- b;
-  match r.range_next with
-    None -> ()
-  | Some r -> own_ranges b r
+  ranges_iter (fun r -> r.range_block <- b) r
 
 (** (internal) 
     Find ranges that are after [cut_pos] offset, unlink them from r
@@ -392,8 +535,6 @@
     If [cut_pos] is within one of the ranges, that range is cut in
     two at [cut_pos] offset, and link each half to its side.
 
-    What should happen to range_begin is unclear.
-
     Also, what do to if range_nuploaders is not 0 ?
     => [cut_ranges_after] is being called from [split_blocks] that
     does not preserve [s_nuploading] for blocks either
@@ -417,16 +558,15 @@
       (* "right" half *)
       let split_r = { r with
 	range_prev = None;
-	range_begin = cut_pos;
-	range_current_begin = max r.range_current_begin cut_pos
+	range_begin = max r.range_begin cut_pos
       } in
       (* "left" half *)
       r.range_next <- None;
       r.range_end <- cut_pos;
-      r.range_current_begin <- min r.range_current_begin cut_pos;
+      r.range_begin <- min r.range_begin cut_pos;
 
       if r.range_nuploading <> 0 then
-	lprintf_n () "WARNING: Splitting a range currently being uploaded, don't know what to do with range_nuploaders :/\n";
+	lprintf_n "WARNING: Splitting a range currently being uploaded, don't know what to do with range_nuploaders :/\n";
 
       split_r in
   let cut_ranges = iter r in
@@ -438,10 +578,10 @@
 
 let empty_block b =
   let rec iter begin_pos r =
-    r.range_current_begin = begin_pos &&
+    r.range_begin = begin_pos &&
     (match r.range_next with
-        Some rr -> iter r.range_end rr
-      | None -> r.range_end = b.block_end)
+     | Some rr -> iter r.range_end rr
+     | None -> r.range_end = b.block_end)
   in
   iter b.block_begin b.block_ranges
 
@@ -490,7 +630,7 @@
 (* We need to split this block in two parts *)
         s.s_block_pos.(index_s) <- chunk_end;
         match s.s_blocks.(index_s) with
-          EmptyBlock | CompleteBlock | VerifiedBlock ->
+	| EmptyBlock | CompleteBlock | VerifiedBlock ->
 
 (* s.s_blocks.(index_s) will appear twice in the result list *)
             let new_blocks =  (
@@ -501,7 +641,6 @@
             iter index_s chunk_end new_blocks
 
         | PartialBlock b1 ->
-
 	    (* split b1 in two; b2 is the part after [chunk_end] offset *)
             let b2 = {
                 block_s = s;
@@ -535,12 +674,8 @@
                 s.s_verified_bitmap.[index_s] <- '0';
               end else
                 s.s_blocks.(index_s) <- PartialBlock b2;
-
             iter index_s chunk_end new_blocks
-
       end
-
-
   in
   let blocks = iter 0 zero [] in
 
@@ -554,9 +689,9 @@
     aux 0 in
 
   if array_exist ((<>) 0) s.s_availability then
-    lprintf_nl () "WARNING: splitting swarmer discarded availability counters\n";
+    lprintf_nl "WARNING: splitting swarmer discarded availability counters";
   if array_exist ((<>) 0) s.s_nuploading then
-    lprintf_nl () "WARNING: splitting a swarmer beging uploaded to\n";
+    lprintf_nl "WARNING: splitting a swarmer beging uploaded to";
 
   s.s_blocks <- Array.create nblocks EmptyBlock;
   s.s_verified_bitmap <- String.make nblocks '0';
@@ -571,8 +706,8 @@
     | (b, pos, c) :: tail ->
         begin
           match b with
-            PartialBlock b -> b.block_num <- i
-          | _ -> ()
+	  | PartialBlock b -> b.block_num <- i
+          | EmptyBlock | CompleteBlock | VerifiedBlock -> ()
         end;
         s.s_blocks.(i) <- b;
         s.s_verified_bitmap.[i] <- c;
@@ -613,11 +748,18 @@
     (* TODO: transfer data into swarmer instead of discarding it *)
     Unix32.remove (file_fd t.t_file);
   end;
+
+  (match s.s_networks with
+   | t :: tail ->
+       assert(t.t_primary);
+       List.iter (fun tt -> assert(not tt.t_primary)) tail
+   | [] -> assert false);
+
 (* at this point, we are supposed to split the blocks in the swarmer
 in smaller blocks depending on the block_size of this network, and compute
 the t_chunk_of_block and t_blocks_of_chunk fields. *)
 
-  let chunk_size = t.t_block_size in
+  let chunk_size = t.t_chunk_size in
 
   split_blocks s chunk_size;
 
@@ -628,7 +770,7 @@
       t.t_chunk_of_block <- Array.create nblocks 0;
       t.t_blocks_of_chunk <- Array.create nchunks [];
 
-      let chunk_size = t.t_block_size in
+      let chunk_size = t.t_chunk_size in
       for i = 0 to nblocks - 1 do
         let block_begin = compute_block_begin s i in
         let chunk = Int64.to_int (block_begin // chunk_size) in
@@ -642,19 +784,14 @@
     add_file_downloaded t.t_file (zero -- file_downloaded t.t_file);
 
 (* check that all frontends use the primary's file backend *)
-    begin
-      match s.s_networks with
-        t :: tail when is_primary ->
-          List.iter (fun tt ->
-              assert (not tt.t_primary);
-              set_file_fd tt.t_file (file_fd t.t_file)
-          ) tail
-
-      | tt :: tail when tt.t_primary ->
-          assert (not is_primary);
-          set_file_fd t.t_file (file_fd tt.t_file)
-      | _ -> ()
-    end;
+  (match s.s_networks with
+   | t :: tail when is_primary ->
+       List.iter (fun tt ->
+         set_file_fd tt.t_file (file_fd t.t_file)
+       ) tail
+   | tprim :: tail ->
+       set_file_fd t.t_file (file_fd tprim.t_file)
+   | [] -> assert false);
 
   ()
 
@@ -663,21 +800,21 @@
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
@@ -692,120 +829,59 @@
   associate true t ss;
   t
 
+(** iter function f over all the blocks contained in the list of [intervals]
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         clear_uploader_ranges                         *)
-(*                                                                       *)
-(*************************************************************************)
-
-let clear_uploader_ranges up =
-  List.iter (fun (_,_,r) ->
-      r.range_nuploading <- r.range_nuploading - 1
-  ) up.up_ranges;
-  up.up_ranges <- []
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         clear_uploader_block                          *)
-(*                                                                       *)
-(*************************************************************************)
-
-let clear_uploader_block up =
-  match up.up_block with
-    None -> ()
-  | Some b ->
-      up.up_block <- None;
-      let num = b.block_num in
-      let t = up.up_t in
-      let s = t.t_s in
-      s.s_nuploading.(num) <- s.s_nuploading.(num) - 1
-
-(** Finds the number of the block containing [chunk_pos] offset, using
-    dichotomy *)
-
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
-      r.range_begin r.range_current_begin r.range_end r.range_nuploading;
+    lprintf_n " %Ld-%Ld(%d)"
+      r.range_begin r.range_end r.range_nuploading;
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
@@ -818,7 +894,7 @@
       ) s.s_networks;
 
       match b with
-        PartialBlock b ->
+      | PartialBlock b ->
           lprintf " [%Ld .. %Ld] --> "
             b.block_begin b.block_end;
           iter b.block_ranges
@@ -827,119 +903,70 @@
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
+    let next = r.range_next in (* keep next range in case f mutates it *)
     f r;
-    match r.range_next with
-      None -> ()
+    match next with
+    | None -> ()
     | Some rr -> iter_range f rr
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
+    lprintf_nl "   %Ld-%Ld" r.range_begin r.range_end) b;
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
+    let added = r.range_end -- r.range_begin in
+    add_file_downloaded maybe_t s added;
+    b.block_remaining <- b.block_remaining -- added;
+    r.range_begin <- r.range_end;
+    r.range_prev <- None;
+    r.range_next <- None) b;
+  if b.block_remaining <> 0L then
+    lprintf_nl "WARNING: block_remaining should be 0 after close_block_ranges"
 
 (*************************************************************************)
 (*                                                                       *)
@@ -947,146 +974,245 @@
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
+let set_swarmer_bitmap_1 s i =
+  match s.s_verified_bitmap.[i] with
+    | '0' ->
+       s.s_verified_bitmap.[i] <- '1';
+	List.iter (fun t ->
           let j = t.t_chunk_of_block.(i) in
-          if t.t_converted_verified_bitmap.[j] = '0' then
-            t.t_converted_verified_bitmap.[j] <- '1'
-      ) s.s_networks
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
 
-(* we finished this block, we need know to verify it *)
-let set_bitmap_2 s i =
-  if s.s_verified_bitmap.[i] < '2' then begin
-      s.s_verified_bitmap.[i] <- '2';
-      match s.s_networks with
-      | t :: _ when t.t_primary ->
-          let j = t.t_chunk_of_block.(i) in
-          if List.for_all (fun i -> s.s_verified_bitmap.[i] = '2')
-            t.t_blocks_of_chunk.(j) &&
-            t.t_converted_verified_bitmap.[j] <> '3' then begin
-              t.t_ncomplete_blocks <- t.t_ncomplete_blocks + 1;
-              t.t_converted_verified_bitmap.[j] <- '2'
-            end
-      | [] -> assert false
-      | _ -> ()
-    end
+(* we finished this block, trying to escalate to primary frontend
+   verification bitmap *)
+let set_swarmer_bitmap_2 s i =
+  match s.s_verified_bitmap.[i] with
+    | '0' | '1' ->
+	(s.s_verified_bitmap.[i] <- '2';
+	match s.s_networks with
+	  | t :: _ ->
+	      assert (t.t_primary);
+              let j = t.t_chunk_of_block.(i) in
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
 
 (* the primary verifier has worked, so let ask secondary ones for
-verification too *)
-let set_bitmap_3 s i =
-  if s.s_verified_bitmap.[i] < '3' then begin
-      s.s_verified_bitmap.[i] <- '3';
-(*      lprintf "set_bitmap_3 %d done\n" i; *)
+   verification too *)
+let set_swarmer_bitmap_3 s i =
+  match s.s_verified_bitmap.[i] with
+  | '0' | '1' | '2' ->
+      (s.s_verified_bitmap.[i] <- '3';
+(*      lprintf "set_swarmer_bitmap_3 %d done\n" i; *)
       match s.s_networks with
-        [] -> assert false
-      | tprim :: tail ->
-          List.iter (fun t ->
-              let j = t.t_chunk_of_block.(i) in
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
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         set_toverify_block (internal)                 *)
-(*                                                                       *)
-(*************************************************************************)
-
-    (*
-let set_toverify_block s i = set_bitmap_2 s i
-    *)
+      | [] -> assert false
+      | tprim :: secondaries ->
+	  assert (tprim.t_primary);
+	  match tprim.t_verifier with
+	  | NoVerification | VerificationNotAvailable -> ()
+	  | Verification _ | ForceVerification ->
+	      let jprim = tprim.t_chunk_of_block.(i) in
+	      assert (tprim.t_converted_verified_bitmap.[jprim] = '3');
+	      List.iter (fun t ->
+		assert (not t.t_primary);
+		let j = t.t_chunk_of_block.(i) in
+		if List.for_all (fun i -> s.s_verified_bitmap.[i] = '3')
+                  t.t_blocks_of_chunk.(j) then
+		    match t.t_verifier with
+		    | NoVerification | VerificationNotAvailable ->
+			(* we have no way to check data integrity
+			   for this network, assume other(s) know
+			   better *)
+			(match t.t_converted_verified_bitmap.[j] with
+			 | '0' | '1' ->
+			     t.t_converted_verified_bitmap.[j] <- '3';
+			     t.t_ncomplete_chunks <- t.t_ncomplete_chunks + 1;
+			     t.t_nverified_chunks <- t.t_nverified_chunks + 1
+			 | '2' ->
+			     t.t_converted_verified_bitmap.[j] <- '3';
+			     t.t_nverified_chunks <- t.t_nverified_chunks + 1
+			 | '3' -> ()
+			 | _ -> assert false)
+		    | ForceVerification
+		    | Verification _ ->
+			(* all chunks are verified, so set
+			   converted_verified_bitmap to '2',
+			   probably to trigger data verification later.
+			   
+			   Is that code necessary at all ? *)
+			(match t.t_converted_verified_bitmap.[j] with
+			 | '0' | '1' ->
+			     t.t_converted_verified_bitmap.[j] <- '2';
+			     t.t_ncomplete_chunks <- t.t_ncomplete_chunks + 1
+			 | '2' -> ()
+			 | '3' -> lprintf_nl "set_swarmer_bitmap_3: trying to demote a verified block in another frontend?"
+			 | _ -> assert false)
+	      ) secondaries)
+  | '3' -> ()
+  | _ -> assert false
 
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
@@ -1094,258 +1220,107 @@
 (*                                                                       *)
 (*************************************************************************)
 
-let verify_chunk t i =
-  if t.t_converted_verified_bitmap.[i] = '2' then
-    let nblocks = String.length t.t_converted_verified_bitmap in
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
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         must_verify_block                             *)
-(*                                                                       *)
-(*************************************************************************)
+(** mark a block as completed, ready for verification *)
 
-let must_verify_block s i immediatly =
-  set_bitmap_2 s i;
-  if immediatly then
-    match s.s_networks with
-      [] -> assert false
-    | t :: _ when t.t_primary ->
-        let i = t.t_chunk_of_block.(i) in
-        t.t_converted_verified_bitmap.[i] <- '2';
-(*        List.iter (fun j ->
-            if s.s_verified_bitmap.[j] <> '2' then begin
-                lprintf "   block %d not downloaded\n" j;
-                exit_on_error := false;
-              end;
-        ) t.t_blocks_of_chunk.(i);  *)
-        verify_chunk t i;
-(*      exit_on_error := true; *)
-    | _ -> ()
+let must_verify_block s i =
+  set_swarmer_bitmap_2 s i
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         verify_all_blocks                             *)
-(*                                                                       *)
-(*************************************************************************)
+(** mark all blocks as completed, ready for verification *)
 
-let verify_all_chunks t immediatly =
+let verify_all_chunks t =
   let s = t.t_s in
-  for i = 0 to String.length s.s_verified_bitmap - 1 do
-    must_verify_block s i immediatly
-  done
+  string_iter (fun i _ -> must_verify_block s i) s.s_verified_bitmap
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         compute_bitmap                                *)
-(*                                                                       *)
-(*************************************************************************)
+(** same, and synchronously calls the verification of all chunks *)
+
+let verify_all_chunks_immediately t =
+  verify_all_chunks t;
+  string_iter (fun i _ -> verify_chunk t i) t.t_converted_verified_bitmap
+    
 
+(** synchronously verify all completed chunks not yet verified *)
 
 let compute_bitmap t =
-  if t.t_ncomplete_blocks > t.t_nverified_blocks then begin
-      for i = 0 to String.length t.t_converted_verified_bitmap - 1 do
-        if t.t_converted_verified_bitmap.[i] = '2' then
-            verify_chunk t i
-      done
-    end
+  if t.t_ncomplete_chunks > t.t_nverified_chunks then 
+    string_iter (fun i c -> 
+      if c = '2' then verify_chunk t i) t.t_converted_verified_bitmap
 
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         split_range (internal)                        *)
-(*                                                                       *)
-(*************************************************************************)
+(** Replaces the ith block of the swarmer with a PartialBlock
+    ranges are created with s_range_size size *)
 
-let rec split_range r range_size =
-  assert (r.range_current_begin = r.range_begin);
-  let next_range = r.range_begin ++ range_size in
-(*  lprintf "   split_range: next_range %Ld\n" next_range; *)
-  if r.range_end > next_range then
-    let rr = {
-        range_block = r.range_block;
-        range_nuploading = 0;
-        range_next = r.range_next;
-        range_prev = Some r;
-        range_begin = next_range;
-        range_current_begin = next_range;
-        range_end = r.range_end;
+let new_block s i =
+
+  (** Split a range in ranges of at most [range_size] bytes, if needed 
+      ranges stay linked together *)
+
+  let rec split_range r range_size =
+    let cut_pos = r.range_begin ++ range_size in
+(*  lprintf "   split_range: cut_pos %Ld\n" cut_pos; *)
+    if r.range_end > cut_pos then
+      (* "right" half *)
+      let split_r = {
+	range_block = r.range_block;
+	range_nuploading = 0;
+	range_next = r.range_next;
+	range_prev = Some r;
+	range_begin = cut_pos;
+	range_end = r.range_end;
       } in
-    begin
-      match r.range_next with
-        None -> ()
-      | Some rrr ->
+      (match r.range_next with
+	| None -> ()
+	| Some old_next_range ->
 (*          lprintf "Another one ??\n"; *)
-          rrr.range_prev <- Some rr;
-    end;
-    r.range_next <- Some rr;
-    r.range_end <- next_range;
+            old_next_range.range_prev <- Some split_r);
+      (* "left" half *)
+      r.range_next <- Some split_r;
+      r.range_end <- cut_pos;
 (*    lprintf "      NEW RANGE: %Ld- OLD RANGE: %Ld-%Ld\n"
-      rr.range_begin r.range_begin r.range_end; *)
-
-    split_range rr range_size
-
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         new_block (internal)                          *)
-(*                                                                       *)
-(*************************************************************************)
+      split_r.range_begin r.range_begin r.range_end; *)
+      split_range split_r range_size in
 
-let new_block s i =
   let block_begin = compute_block_begin s i in
   let block_end = compute_block_end s i in
   let rec b = {
@@ -1365,348 +1340,227 @@
       range_end = block_end;
       range_block = b;
       range_nuploading = 0;
-      range_current_begin = block_begin;
     }
   in
-
 (*  lprintf "New block %Ld-%Ld\n" block_begin block_end; *)
   split_range range s.s_range_size;
 
-(*
-  let rec iter r =
-    lprintf "  Range %Ld-%Ld\n" r.range_begin r.range_end;
-    match r.range_next with
-      None -> ()
-    | Some r -> iter r
-  in
-  iter b.block_ranges;
-*)
-
   s.s_blocks.(i) <- PartialBlock b;
   if s.s_verified_bitmap.[i] < '1' then
-    set_bitmap_1 s i;
-  if debug_all then lprintf_nl () "NB[%s]" s.s_verified_bitmap;
+    set_swarmer_bitmap_1 s i;
+  if debug_all then lprintf_nl "NB[%s]" s.s_verified_bitmap;
   b
 
+(** Remove an interval from the beginning of a range, adding the size
+    of the removed part to the downloaded amount
+    Closed ranges are removed
+    When last range is removed, mark the block for verification *)
 
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
-(*************************************************************************)
-(*                                                                       *)
-(*                         range_received (internal)                     *)
-(*                                                                       *)
-(*************************************************************************)
-
-let range_received maybe_t r chunk_begin chunk_end =
+let range_received maybe_t r interval_begin interval_end =
 (*  lprintf "   range_received: %Ld-%Ld for %Ld-%Ld\n"
-    chunk_begin chunk_end r.range_begin r.range_end;  *)
-  if r.range_begin < chunk_end && r.range_end > chunk_begin then begin
-
+    interval_begin interval_end r.range_begin r.range_end;  *)
+  (* interval overlap with the beginning of range ? *)
+  (* was: r.range_begin < interval_end && r.range_end > interval_begin *)
+  if r.range_begin >= interval_begin && 
+    r.range_begin < interval_end then begin
 (*      lprintf "... entered\n"; *)
-      let new_current_begin =
-        max (min chunk_end r.range_end) r.range_current_begin in
-      let downloaded = new_current_begin -- r.range_current_begin in
-      let b = r.range_block in
-      let s = b.block_s in
-      add_file_downloaded maybe_t s downloaded;
-      b.block_remaining <- b.block_remaining -- downloaded;
-      r.range_current_begin <- new_current_begin;
-      if r.range_current_begin = r.range_end then begin
-          (match r.range_next with
-              None -> ()
-            | Some rr -> rr.range_prev <- r.range_prev);
-          (match r.range_prev with
-              None ->
-                begin
-                  match r.range_next with
-                    None ->
-                      begin
-                        match s.s_blocks.(b.block_num) with
-                          PartialBlock _ | EmptyBlock ->
-
-                            begin
-                              match s.s_networks with
-                                [] -> assert false
-                              | t :: _ when t.t_primary ->
-                                  begin
-                                    match t.t_verifier with
-                                      NoVerification ->
-                                        set_verified_block s b.block_num
-                                    | _ ->
-                                        set_completed_block (Some t) s b.block_num;
-                                        must_verify_block s b.block_num false
-                                  end
-                              | _ -> ()
-                            end
-                        | _ -> ()
-                      end
-                  | Some rr -> b.block_ranges <- rr
-                end;
-            | Some rr -> rr.range_next <- r.range_next);
-          r.range_next <- None;
-          r.range_prev <- None;
-        end (* else begin
-          lprintf " ... new range %Ld-%Ld\n" r.range_current_begin r.range_end;
-        end *)
-    end
-
+    let new_current_begin =
+      max (min interval_end r.range_end) r.range_begin in
+    let downloaded = new_current_begin -- r.range_begin in
+    let b = r.range_block in
+    let s = b.block_s in
+    add_file_downloaded maybe_t s downloaded;
+    b.block_remaining <- b.block_remaining -- downloaded;
+    r.range_begin <- new_current_begin;
+    if r.range_begin = r.range_end then begin
+      (* range completed, unlink it *)
+      (match r.range_next with
+       | Some rr -> rr.range_prev <- r.range_prev
+       | None -> ());
+      (match r.range_prev with
+       | Some rr -> rr.range_next <- r.range_next
+       | None ->
+	   (* that was the first range of the block *)
+           match r.range_next with
+           | Some rr -> (* fix block's first range *)
+	       b.block_ranges <- rr
+           | None ->
+	       (* that was the last remaining range of the block *)
+               (match s.s_blocks.(b.block_num) with
+                | PartialBlock _ | EmptyBlock ->
+                    (match s.s_networks with
+		     | t :: _ -> 
+			 assert(t.t_primary);
+                         (match t.t_verifier with
+			  | NoVerification ->
+                              set_verified_block s b.block_num
+			  | _ ->
+                              set_completed_block (Some t) s b.block_num;
+                              must_verify_block s b.block_num)
+		     | [] -> assert false)
+                | _ -> () ));
+      r.range_next <- None;
+      r.range_prev <- None;
+    end (* else begin
+           lprintf " ... new range %Ld-%Ld\n" r.range_begin r.range_end;
+           end *)
+  end
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         set_present_block (internal)                  *)
-(*                                                                       *)
-(*************************************************************************)
+(** Remove an interval from the ranges of a block, calling
+    range_received over all of them
 
-(* Assumption: we never download ranges from the middle, so present chunks
-  can only overlap the beginning of a range *)
-let set_present_block b chunk_begin chunk_end =
-  let rec iter r =
-    let range_next = r.range_next in
-(*    lprintf "iter range %Ld-%Ld\n" r.range_begin r.range_end; *)
-    (try range_received None r chunk_begin chunk_end
-      with e ->
-          lprintf_nl () "EXCEPTION IN range_received: %s"
-            (Printexc2.to_string e);
-          exit 2);
-    match range_next with
-      None -> ()
-    | Some rr ->
-        iter rr
-  in
-(*  lprintf "BEFORE:  ";  print_block b; *)
-  iter b.block_ranges;
-(*  lprintf "AFTER:  ";  print_block b *)
-  ()
+    Assumption: we never download ranges from the middle, so present
+    intervals can only overlap the beginning of ranges
 
+    A (double linked) list is definitely not the most efficient
+    datastructure for this operation... *)
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         set_present                                   *)
-(*                                                                       *)
-(*************************************************************************)
+let set_present_block b interval_begin interval_end =
+  iter_block_ranges (fun r ->
+    range_received None r interval_begin interval_end) b
 
-let set_present s chunks =
+(** Remove a list of intervals from the ranges of a swarmer *)
 
-  apply_intervals s (fun i block_begin block_end chunk_begin chunk_end ->
+let set_present s intervals =
+  iter_intervals s (fun i block_begin block_end interval_begin interval_end ->
 (*      lprintf "interval: %Ld-%Ld in block %d [%Ld-%Ld]\n"
-      chunk_begin chunk_end i block_begin block_end;  *)
-      match s.s_blocks.(i) with
-        EmptyBlock ->
+      interval_begin interval_end i block_begin block_end;  *)
+    match s.s_blocks.(i) with
+    | EmptyBlock ->
 (*          lprintf "  EmptyBlock"; *)
-          if block_begin >= chunk_begin && block_end <= chunk_end then
-            begin
+        if block_begin >= interval_begin && block_end <= interval_end
+	then begin
 (*              lprintf " --> CompleteBlock\n"; *)
-              s.s_blocks.(i) <- CompleteBlock;
-              must_verify_block s i false;
-              add_file_downloaded None s (block_end -- block_begin)
-            end
-          else
+          s.s_blocks.(i) <- CompleteBlock;
+          must_verify_block s i;
+          add_file_downloaded None s (block_end -- block_begin)
+        end
+        else
           let b = new_block s i in
 (*          lprintf " ... set_present_block\n";  *)
-          set_present_block b chunk_begin chunk_end
-      | PartialBlock b ->
+          set_present_block b interval_begin interval_end
+    | PartialBlock b ->
 (*          lprintf "  PartialBlock\n"; *)
-          set_present_block b chunk_begin chunk_end
-      | _ ->
+        set_present_block b interval_begin interval_end
+    | CompleteBlock | VerifiedBlock ->
 (*          lprintf "  Other\n"; *)
-          ()
-  ) chunks
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         end_present (internal)                        *)
-(*                                                                       *)
-(*************************************************************************)
+        ()
+  ) intervals
 
-let rec end_present present begin_present end_file list =
-  match list with
-    [] ->
-      let present =
-        if begin_present = end_file then present else
-          (begin_present, end_file) :: present
-      in
-      List.rev present
-  | (begin_absent, end_absent) :: tail ->
-      let present =
-        if begin_present = begin_absent then present
-        else (begin_present, begin_absent) :: present
-      in
-      end_present present end_absent end_file tail
+(** reverse absent/present in the list and call set_present *)
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         set_absent                                    *)
-(*                                                                       *)
-(*************************************************************************)
+let set_absent s list_absent =
+(** Build the complementary list of intervals of [intervals] in 
+    [set_begin, set_end[ *)
+  let rec complementary acc set_begin set_end intervals =
+    match intervals with
+      | [] ->
+	  let acc =
+            if set_begin = set_end then acc else
+              (set_begin, set_end) :: acc
+	  in
+	  List.rev acc
+      | (interval_begin, interval_end) :: other_intervals ->
+	  let acc =
+            if set_begin = interval_begin then acc
+            else (set_begin, interval_begin) :: acc
+	  in
+	  complementary acc interval_end set_end other_intervals in
+  let list_present = complementary [] Int64.zero s.s_size list_absent in
+  set_present s list_present
 
-let set_absent s list =
-(* reverse absent/present in the list and call set_present *)
-  let list =
-    match list with [] -> [ Int64.zero, s.s_size ]
-    | (t1,t2) :: tail ->
-        if t1 = zero then
-          end_present [] t2 s.s_size tail
-        else
-          end_present [zero, t1] t2 s.s_size tail
-  in
-  set_present s list
+let intervals_to_string s intervals =
+  match intervals with
+  | AvailableIntervals intervals ->
+      let st = String.make (Array.length s.s_blocks) '0' in
+      iter_intervals s (fun i _ _ _ _ -> st.[i] <- '1') intervals;
+      st
+  | AvailableBitv b -> Bitv.to_string b
 
 (*************************************************************************)
 (*                                                                       *)
-(*                         chunks_to_string (internal)                   *)
+(*                               Uploaders                               *)
 (*                                                                       *)
 (*************************************************************************)
 
-let chunks_to_string s chunks =
-  match chunks with
-      AvailableRanges chunks ->
-        begin
-          let st = String.make (Array.length s.s_blocks) '0' in
-          apply_intervals s (fun i block_begin block_end chunk_begin chunk_end -> st.[i] <- '1') chunks;
-          st
-        end
-  | AvailableCharBitmap st -> st
-  | AvailableBitv b -> Bitv.to_string b
+(** if not [up_declared], 
+    sets [up_intervals], [up_complete_blocks], [up_ncomplete],
+    [up_partial_blocks], [up_npartial] according to [intervals],
+    resets [up_block], [up_block_begin], [up_block_end], and calls
+    [client_has_bitmap] on associated client.
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         update_uploader_chunks (internal)             *)
-(*                                                                       *)
-(*************************************************************************)
+    My feeling is that if all those fields only make sense when
+    up_declared is true, they should be regrouped in a record option.
+*)
 
-let update_uploader_chunks up chunks =
-  if not up.up_declared then
+let set_uploader_intervals up intervals =
+  if up.up_declared then
+    lprintf_nl "set_uploader_intervals: called on an already declared uploader\n"
+  else
     let t = up.up_t in
     let s = t.t_s in
-(* INVARIANT: complete_blocks must be in reverse order *)
+    (* INVARIANT: complete_blocks must be in reverse order *)
 
-    let complete_blocks = ref [] in
-    let partial_blocks = ref [] in
+  let complete_blocks = ref [] in
+  let partial_blocks = ref [] in
 
-    begin
-      match chunks with
-        AvailableRanges chunks ->
+  let incr_availability s i =
+    s.s_availability.(i) <- s.s_availability.(i) + 1 in
 
-          apply_intervals s (fun i block_begin block_end
-                chunk_begin chunk_end ->
-(*              lprintf "apply_intervals %d %Ld-%Ld %Ld-%Ld\n"
-                i block_begin block_end chunk_begin chunk_end; *)
-              s.s_availability.(i) <- s.s_availability.(i) + 1;
+  (match intervals with
+   | AvailableIntervals intervals ->
+       iter_intervals s (fun i block_begin block_end interval_begin interval_end ->
+(*              lprintf "iter_intervals %d %Ld-%Ld %Ld-%Ld\n"
+                i block_begin block_end interval_begin interval_end; *)
+         incr_availability s i;
 
-              match s.s_blocks.(i) with
-                CompleteBlock | VerifiedBlock -> ()
-              | _ ->
-                  if block_begin = chunk_begin && block_end = chunk_end then
-                    complete_blocks := i :: !complete_blocks
-                  else
-                    partial_blocks :=
-                    (i, chunk_begin, chunk_end) :: !partial_blocks
-          ) chunks;
+         match s.s_blocks.(i) with
+	 | CompleteBlock | VerifiedBlock -> ()
+         | EmptyBlock | PartialBlock _ ->
+             if block_begin = interval_begin && block_end = interval_end then
+               complete_blocks := i :: !complete_blocks
+             else
+               partial_blocks :=
+                 (i, interval_begin, interval_end) :: !partial_blocks
+       ) intervals
 
-      | AvailableCharBitmap string ->
-          for i = 0 to String.length string - 1 do
-            if string.[i] = '1' then
-              List.iter (fun i ->
-                  s.s_availability.(i) <- s.s_availability.(i) + 1;
-                  complete_blocks := i :: !complete_blocks
-              ) t.t_blocks_of_chunk.(i)
-          done;
-      | AvailableBitv bitmap ->
-          for i = 0 to Bitv.length bitmap - 1 do
-            if Bitv.get bitmap i then
-              List.iter (fun i ->
-                  s.s_availability.(i) <- s.s_availability.(i) + 1;
-                  complete_blocks := i :: !complete_blocks
-              ) t.t_blocks_of_chunk.(i)
-          done;
-    end;
+   | AvailableBitv bitmap ->
+       Bitv.iteri_true (fun i ->
+         List.iter (fun j ->
+           incr_availability s j;
+           complete_blocks := j :: !complete_blocks
+         ) t.t_blocks_of_chunk.(i)
+       ) bitmap
+  );
 
-    List.iter (fun i ->
+  List.iter (fun i ->
 (*        s.s_last_seen.(i) <- BasicSocket.last_time (); *)
+    let i = t.t_chunk_of_block.(i) in
+    t.t_last_seen.(i) <- BasicSocket.last_time ()
+  ) !complete_blocks;
 
-        let i = t.t_chunk_of_block.(i) in
-        t.t_last_seen.(i) <- BasicSocket.last_time ()
-
-    ) !complete_blocks;
-
-    let complete_blocks = Array.of_list !complete_blocks in
-    let partial_blocks = Array.of_list !partial_blocks in
-    up.up_chunks <- chunks;
-
-    up.up_complete_blocks <- complete_blocks;
-    up.up_ncomplete <- Array.length complete_blocks;
-
-    if Array.length partial_blocks > 0 then
-      lprintf_nl () "WARNING: partial_blocks = %d" (Array.length partial_blocks);
-    up.up_partial_blocks <- partial_blocks;
-    up.up_npartial <- Array.length partial_blocks;
-
-    up.up_block <- None;
-    up.up_block_begin <- zero;
-    up.up_block_end <- zero;
-
-    up.up_declared <- true;
-
-    let bm = chunks_to_string s chunks in
-    client_has_bitmap up.up_client up.up_t.t_file bm;
-
-    if debug_all then print_uploader up
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         clean_uploader_chunks (internal)              *)
-(*                                                                       *)
-(*************************************************************************)
-
+  let complete_blocks = Array.of_list !complete_blocks in
+  let partial_blocks = Array.of_list !partial_blocks in
+  up.up_intervals <- intervals;
 
-let clean_uploader_chunks up =
+  up.up_complete_blocks <- complete_blocks;
+  up.up_ncomplete <- Array.length complete_blocks;
+  
+  if Array.length partial_blocks > 0 then
+    lprintf_nl "WARNING: partial_blocks = %d" (Array.length partial_blocks);
+  up.up_partial_blocks <- partial_blocks;
+  up.up_npartial <- Array.length partial_blocks;
 
-  if up.up_declared then
+  up.up_block <- None;
+  up.up_block_begin <- zero;
+  up.up_block_end <- zero;
 
-    let decr_availability s i =
-      s.s_availability.(i) <- s.s_availability.(i) - 1
-    in
-(*          lprintf "clean_uploader_chunks:\n"; *)
+  up.up_declared <- true;
+  
+  let bm = intervals_to_string s intervals in
+  client_has_bitmap up.up_client up.up_t.t_file bm;
 
-    let t = up.up_t in
-    let s = t.t_s in
-    for i = 0 to Array.length up.up_complete_blocks - 1 do
-(*            lprintf "decr_availability complete[%d] %d\n" i
-              up.up_complete_blocks.(i); *)
-      decr_availability s up.up_complete_blocks.(i)
-    done;
-    for i = 0 to Array.length up.up_partial_blocks - 1 do
-      let b,_,_ = up.up_partial_blocks.(i) in
-(*            lprintf "decr_availability partial[%d] %d\n" i b; *)
-      decr_availability s b
-    done;
-    clear_uploader_block up;
-    up.up_declared <- false
+  if debug_all then print_uploader up
 
 (*************************************************************************)
 (*                                                                       *)
@@ -1714,15 +1568,14 @@
 (*                                                                       *)
 (*************************************************************************)
 
-let register_uploader t client chunks =
-
+let register_uploader t client intervals =
   let up =
     {
       up_t = t;
       up_client = client;
 
       up_declared = false;
-      up_chunks = chunks;
+      up_intervals = intervals;
 
       up_complete_blocks = [||];
       up_ncomplete = 0;
@@ -1733,11 +1586,12 @@
       up_block = None;
       up_block_begin = zero;
       up_block_end = zero;
+
       up_ranges = [];
     }
   in
   HU.add uploaders_by_num up;
-  update_uploader_chunks up chunks;
+  set_uploader_intervals up intervals;
   up
 
 (*************************************************************************)
@@ -1746,34 +1600,63 @@
 (*                                                                       *)
 (*************************************************************************)
 
-let unregister_uploader up =
-  clean_uploader_chunks up;
-  clear_uploader_block up;
-  clear_uploader_ranges up
+let clear_uploader_ranges up =
+  List.iter (fun (_,_,r) ->
+    if r.range_nuploading > 0 then
+      r.range_nuploading <- r.range_nuploading - 1
+    else
+      lprintf_nl "clear_uploader_ranges: some range_nuploading was about to become negative\n"
+  ) up.up_ranges;
+  up.up_ranges <- []
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         update_uploader                               *)
-(*                                                                       *)
-(*************************************************************************)
+let clear_uploader_block up =
+  match up.up_block with
+  | None -> ()
+  | Some b ->
+      let num = b.block_num in
+      let t = up.up_t in
+      let s = t.t_s in
+      if s.s_nuploading.(num) > 0 then
+	s.s_nuploading.(num) <- s.s_nuploading.(num) - 1
+      else
+	lprintf_nl "clear_uploader_block: some s_nuploading was about to become negative\n";
+      up.up_block <- None;
+      up.up_block_begin <- zero;
+      up.up_block_end <- zero
 
-let update_uploader up chunks =
+let clear_uploader_intervals up =
+  if up.up_declared then
+    let decr_availability s i =
+      if s.s_availability.(i) > 0 then
+	s.s_availability.(i) <- s.s_availability.(i) - 1 
+      else 
+	lprintf_nl "clear_uploader_intervals: some s_availability was about to become negative\n" in
+(*          lprintf "clean_uploader_chunks:\n"; *)
+    let t = up.up_t in
+    let s = t.t_s in
+    Array.iter (decr_availability s) up.up_complete_blocks;
+    up.up_complete_blocks <- [||];
+    up.up_ncomplete <- 0;
+    Array.iter (fun (b,_,_) -> decr_availability s b) up.up_partial_blocks;
+    up.up_partial_blocks <- [||];
+    up.up_npartial <- 0;
+    clear_uploader_block up;
+    up.up_declared <- false
 
-  clean_uploader_chunks up;
-  update_uploader_chunks up chunks
+let update_uploader_intervals up intervals =
+  clear_uploader_intervals up;
+  set_uploader_intervals up intervals
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         print_uploaders                               *)
-(*                                                                       *)
-(*************************************************************************)
+let unregister_uploader up =
+  clear_uploader_intervals up;
+  clear_uploader_ranges up
 
-let print_uploaders s =
-  let nblocks = Array.length s.s_blocks in
-  for i = 0 to nblocks - 1 do
+(** (debug) output the uploaders of a swarmer to current log *)
 
-    match s.s_blocks.(i) with
-      EmptyBlock -> lprintf "_"
+let print_uploaders s =
+  Array.iteri (fun i b ->
+    match b with
+    | EmptyBlock -> lprintf "_"
     | CompleteBlock -> lprintf "C"
     | VerifiedBlock -> lprintf "V"
     | PartialBlock b ->
@@ -1781,127 +1664,128 @@
           lprintf "X"
         else
           lprintf "%d" s.s_nuploading.(i)
-  done;
+  ) s.s_blocks;
   lprint_newline ();
-  for i = 0 to nblocks - 1 do
-
-    match s.s_blocks.(i) with
-      EmptyBlock -> lprintf "_"
+  Array.iteri (fun i b ->
+    match b with
+    | EmptyBlock -> lprintf "_"
     | CompleteBlock -> lprintf "C"
     | VerifiedBlock -> lprintf "V"
     | PartialBlock b ->
         lprintf "{ %d : %d=" b.block_num
           s.s_nuploading.(b.block_num);
-
-        let rec iter_range r =
-          lprintf "(%d)" r.range_nuploading;
-          match r.range_next with
-            None -> ()
-          | Some rr -> iter_range rr
-        in
-        iter_range b.block_ranges;
+	iter_block_ranges (fun r -> 
+          lprintf "(%d)" r.range_nuploading
+	) b;
         lprintf " }";
-
-  done;
+  ) s.s_blocks;
   lprint_newline ()
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         permute_and_return (internal)                 *)
-(*                                                                       *)
-(*************************************************************************)
+(** swap elements n and up_ncomplete-1 in up_complete_blocks, then
+    decrease up_ncomplete block, return up_ncomplete block, converting
+    it to a PartialBlock as needed.
+    global effect is that up_complete_blocks array virtually contains
+    two disctinct lists, with elements flowing from one to the other,
+    without any allocation needed.
+
+    0 .. up_ncomplete-1 : not yet returned by permute_and_return
+    up_ncomplete .. Array.length up_complete_blocks - 1 : already returned 
+*)
 
 let permute_and_return up n =
+  assert (n <= up.up_ncomplete-1);
   let b = up.up_complete_blocks.(n) in
   if debug_all then  lprintf "permute_and_return %d <> %d" n b;
-  up.up_complete_blocks.(n) <- up.up_complete_blocks.(up.up_ncomplete-1);
-  up.up_complete_blocks.(up.up_ncomplete-1) <- b;
+  if n < up.up_ncomplete then begin
+    up.up_complete_blocks.(n) <- up.up_complete_blocks.(up.up_ncomplete-1);
+    up.up_complete_blocks.(up.up_ncomplete-1) <- b
+  end;
   up.up_ncomplete <- up.up_ncomplete - 1;
   let t = up.up_t in
   let s = t.t_s in
   match s.s_blocks.(b) with
-    EmptyBlock ->
+  | EmptyBlock ->
       let b = new_block s b in
       b, b.block_begin, b.block_end
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
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         LinearStrategy.select_block (internal)            *)
-(*                                                                       *)
-(*************************************************************************)
+(** find a block in up_complete_blocks that's not already
+    CompleteBlock or VerifiedBlock.
+    If none can be found, do the same with up_partial_blocks.
+    If none can be found still, raise Not_found exception 
+    
+    up_ncomplete and up_npartial are used as in the same way as in
+    permute_and_return, but no element is ever permuted.
 
-module LinearStrategy = struct
-    let select_block  up =
-      let rec iter_complete up =
-        let n = up.up_ncomplete in
-        if n = 0 then iter_partial up
-        else
-        let b = up.up_complete_blocks.(n-1) in
-        up.up_ncomplete <- n-1;
-        let t = up.up_t in
-        let s = t.t_s in
-        match s.s_blocks.(b) with
-          CompleteBlock | VerifiedBlock ->
-            iter_complete up
-        | PartialBlock b ->
-            b, b.block_begin, b.block_end
-        | EmptyBlock ->
-            let b = new_block s b in
-            b, b.block_begin, b.block_end
+    Since set_uploader_intervals puts the blocks with the lowest
+    offsets at the end of up_complete_blocks and up_partial_blocks,
+    this also selects the blocks in increasing offsets order.
+*)
 
-      and iter_partial up =
-        let n = up.up_npartial in
-        if n = 0 then raise Not_found;
-        let b, block_begin, block_end = up.up_partial_blocks.(n-1) in
-        let t = up.up_t in
-        let s = t.t_s in
-        match s.s_blocks.(b) with
-          CompleteBlock | VerifiedBlock ->
-            iter_partial up
-        | PartialBlock b ->
-            b, block_begin, block_end
-        | EmptyBlock ->
-            let b = new_block s b in
-            b, block_begin, block_end
-      in
-      iter_complete up
-  end
+let linear_select_block up =
+  let rec iter_partial up =
+    let n = up.up_npartial in
+    if n = 0 then raise Not_found;
+    let b, block_begin, block_end = up.up_partial_blocks.(n-1) in
+    let t = up.up_t in
+    let s = t.t_s in
+    (* priority bitmap <> 0 here ? *)
+    match s.s_blocks.(b) with
+    | CompleteBlock | VerifiedBlock ->
+        iter_partial up
+    | PartialBlock b ->
+        b, block_begin, block_end
+    | EmptyBlock ->
+        let b = new_block s b in
+        b, block_begin, block_end in
+  let rec iter_complete up =
+    let n = up.up_ncomplete in
+    if n = 0 then iter_partial up
+    else
+      let b = up.up_complete_blocks.(n-1) in
+      up.up_ncomplete <- n-1;
+      let t = up.up_t in
+      let s = t.t_s in
+      (* priority bitmap <> 0 here ? *)
+      match s.s_blocks.(b) with
+      | CompleteBlock | VerifiedBlock ->
+          iter_complete up
+      | PartialBlock b ->
+          b, b.block_begin, b.block_end
+      | EmptyBlock ->
+          let b = new_block s b in
+          b, b.block_begin, b.block_end
+  in
+  iter_complete up
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         should_download_block (internal)              *)
-(*                                                                       *)
-(*************************************************************************)
+(** Check whether block [n] of swarmer [s] is not completed yet,
+    calling chunk verification first if block still need verification *)
 
 let should_download_block s n =
 (*  lprintf "should_download_block %d\n" n; *)
   let result =
     match s.s_verified_bitmap.[n] with
-      '2' ->
-        begin
-          match s.s_networks with
-            [] -> assert false
-          | t :: _ when t.t_primary ->
-              begin
-                try
-                  let n = t.t_chunk_of_block.(n) in
-                  if t.t_converted_verified_bitmap.[n] = '2' then
-                    verify_chunk t n
-                with VerifierNotReady -> ()
-              end
-          | _ -> ()
-        end;
-        s.s_verified_bitmap.[n] < '2'
     | '0' | '1' -> true
-    | _ -> false
+    | '2' ->
+        (match s.s_networks with
+         | t :: _ ->
+	     assert(t.t_primary);
+             (try
+               let n = t.t_chunk_of_block.(n) in
+               if t.t_converted_verified_bitmap.[n] = '2' then
+                 verify_chunk t n
+             with VerifierNotReady -> ());
+	 | [] -> assert false);
+        s.s_verified_bitmap.[n] < '2'
+    | '3' -> false
+    | _ -> assert false
   in
 (*  if result then
     lprintf "should_download_block %d\n" n; *)
@@ -1913,264 +1797,204 @@
 (*                                                                       *)
 (*************************************************************************)
 
-exception BlockFound of int
+(* Would it be faster not to build those records, and use functions of
+   the block number ? *)
 
-let random_int max =
-  let x = Random.int max in
-  if debug_all then lprintf_nl () "(Random %d -> %d)" max x;
-  x
+type choice = {
+  choice_num : int;
+  choice_user_priority : int;
+  choice_nuploaders : int;
+  choice_size : int64;
+  choice_remaining : int64;
+  choice_remaining_per_uploader : int64;
+  choice_other_complete : int Lazy.t; (* ...blocks in the same chunk *)
+  choice_availability : int;
+}
+
+(* based on Array.fold_left code *)
+let array_fold_lefti f x a =
+  let r = ref x in
+  for i = 0 to Array.length a - 1 do
+    r := f !r i (Array.unsafe_get a i)
+  done;
+  !r
 
 let select_block up =
   let t = up.up_t in
   let s = t.t_s in
   try
     match s.s_strategy with
-      LinearStrategy ->
-        LinearStrategy.select_block up
+    | LinearStrategy ->
+        linear_select_block up
     | _ ->
         if up.up_ncomplete = 0 && up.up_npartial = 0 then raise Not_found;
 
-(**************
-
-This strategy sucks. It has to be improved.
-Important:
-1) never give a block to 2 clients if another one has 0 client.
-2) try to complete partial blocks as soon as possible.
-3) comfigure the chooser depending on the network (maybe BT might
-better work at the beginning if the first incomplete blocks are offered
-    to several clients.
-
-***************)
-
-
-
-        if up.up_ncomplete > 1 then begin
-(*          let debug_all = true in *)
-            try
-
-              let rec iter_max_uploaders max_nuploaders =
-                let t = up.up_t in
-                let nblocks = Array.length s.s_blocks in
-
-(*************   Try to download the movie index and the first minute to
-   allow preview of the file as soon as possible *)
-
-                if debug_all then lprintf_nl () "{First}";
-
-                let download_first n b =
-(*                lprintf "download_first %d\n" n; *)
-                  if
-                    up.up_complete_blocks.(n) = b &&
-                    s.s_nuploading.(b) < max_nuploaders &&
-                    should_download_block s b then
-                    raise (BlockFound n)
-                in
-
-(*              lprintf "up_complete_blocks: %d\n"
-                (Array.length up.up_complete_blocks); *)
-
-(* This must be the position of the last block of the file *)
-                download_first 0 (nblocks-1);
-
-(* This can be the position of the first block of the file *)
-                download_first (up.up_ncomplete-1) 0;
-
-(* This can be the position of the first block of the file *)
-                download_first 0 0;
-
-(* This must be the position of the second last block of the file *)
-                download_first 0 (nblocks-2);
-
-(* These can be the positions of the second block of the file *)
-                download_first 0 1;
-                download_first (up.up_ncomplete-1) 1;
-                download_first (up.up_ncomplete-2) 1;
-
-(************* If the file can be verified, and we don't have a lot of blocks
-    yet, try to download the partial ones as soon as possible *)
-
-                if debug_all then lprintf_nl () "{PartialBlock}";
-
-                let download_partial max_uploaders =
-                  let partial_block = ref (-1) in
-                  let partial_remaining = ref zero in
-                  for i = 0 to up.up_ncomplete - 1 do
-                    let n = up.up_complete_blocks.(i) in
-                    match s.s_blocks.(n) with
-                      PartialBlock b ->
-                        if (!partial_block = -1 ||
-                            !partial_remaining > b.block_remaining) &&
-                          s.s_nuploading.(n) < max_uploaders
-                        then
-                          begin
-                            partial_block := i;
-                            partial_remaining := b.block_remaining
-                          end
-                    | _ -> ()
-                  done;
-                  if !partial_block <> -1 then
-                    raise (BlockFound !partial_block)
-                in
-
-                if t.t_verifier <> NoVerification &&
-                  t.t_nverified_blocks  < 2  then begin
-                    download_partial max_nuploaders;
-                  end;
-
-(************* Download partial chunks from the verification point of view *)
-
-                if List.length s.s_networks > 1 then begin
-                    if debug_all then lprintf_n () "{PartialChunk}";
-
-                    let my_t = if t.t_verifier <> NoVerification then t
-                      else match s.s_networks with t :: _ -> t | _ -> t in
-
-                    let download_partial max_uploaders =
-                      let partial_block = ref (-1) in
-                      let partial_remaining = ref 0 in
-                      for i = 0 to up.up_ncomplete - 1 do
-                        let n = up.up_complete_blocks.(i) in
-(* TODO move this after the first if... *)
-                        let t_index = t.t_chunk_of_block.(n) in
-                        let bs = List.filter (fun s_index ->
-                              s.s_verified_bitmap.[s_index] = '2'
-                          ) t.t_blocks_of_chunk.(t_index) in
-                        let nbs = List.length bs in
-
-(* TODO remove this *)
-                        let b = should_download_block s n in
+(* to evaluate the relative rarity of a block, we must compare it to
+   the availability of *all* blocks, not only those available from
+   that uploader *)
+	let sum_availability = Array.fold_left (+) 0 s.s_availability in
+	let mean_availability = sum_availability / Array.length s.s_blocks in
 
-                        if !verbose_swarming then
-                            lprintf_nl2 "  test %d %c %d %b %d"
-                              n s.s_verified_bitmap.[n] s.s_nuploading.(n)
-                            b nbs;
+	let my_t = if t.t_verifier <> NoVerification then t else 
+	  match s.s_networks with
+	    | tprim :: _ ->
+		assert(tprim.t_primary);
+		tprim
+	    | [] -> assert false in
+	let verification_available = my_t.t_verifier <> NoVerification in
 
-                        if s.s_verified_bitmap.[n] < '2' &&
-                          s.s_nuploading.(n) < max_uploaders &&
-                          should_download_block s n then
+	let several_frontends = List.length s.s_networks > 1 in
+	(* many results may not be useful, evaluate them as needed *)
+	let completed_blocks_in_chunk = 
+	  Array.init my_t.t_nchunks (fun i ->
+            lazy (
+              List.fold_left (fun acc b ->
+		if s.s_verified_bitmap.[b] = '2' then acc + 1 else acc
+              ) 0 my_t.t_blocks_of_chunk.(i))) in
 
-                          if (!partial_block = -1 || !partial_remaining < nbs)
-                          then
-                            begin
-                              partial_block := i;
-                              partial_remaining := nbs
-                            end
-                      done;
-                      if !partial_block <> -1 then begin
-                          if !verbose_swarming then
-                            lprintf_n () "PartialChunk won for %d waiting blocks"
-                              !partial_remaining;
-                          raise (BlockFound !partial_block)
-                        end
-                    in
+	let preview_beginning = 10000000L in
+	let preview_end = (s.s_size ** 98L) // 100L in
 
-                    if my_t.t_verifier <> NoVerification then begin
-                        download_partial max_nuploaders;
-                      end;
-                  end;
+	(* sources_per_chunk was initially for edonkey only *)
+	let data_per_source = 9728000L // (Int64.of_int !!sources_per_chunk) in
 
-(************* Download rarest first only if other blocks are much more
-  available *)
+	let need_to_complete_some_blocks_quickly = true
+	  (* verification_available && t.t_nverified_chunks < 2 *) in
 
-                if debug_all then lprintf "{Rarest}";
+	(** > 0 == c1 is best, < 0 = c2 is best, 0 == they're equivalent *)
+	let compare_choices c1 c2 =
 
-                let sum_availability = ref 0 in
-                let min_availability = ref max_int in
-                for i = 0 to up.up_ncomplete - 1 do
-                  let n = up.up_complete_blocks.(i) in
-                  sum_availability := !sum_availability +
-                    s.s_availability.(n);
-                  min_availability := min !min_availability
-                    s.s_availability.(n);
-                done;
+	  (* avoid overly unbalanced situations *)
+	  let cmp = 
+	    if c1.choice_remaining_per_uploader < data_per_source ||
+	      c2.choice_remaining_per_uploader < data_per_source then
+		compare c1.choice_remaining_per_uploader 
+		  c2.choice_remaining_per_uploader else 0 in
+	  if cmp <> 0 then cmp else
 
-                let mean_availability =
-                  !sum_availability / up.up_ncomplete in
+	  (* Do what Master asked for *)
+	  let cmp = compare c1.choice_user_priority c2.choice_user_priority in
+	  if cmp <> 0 then cmp else
 
-                if mean_availability > 5 && !min_availability < 3 then
-                  for i = 0 to up.up_ncomplete - 1 do
-                    let n = up.up_complete_blocks.(i) in
-                    if s.s_availability.(n) < 3
-                        && should_download_block s n
-                    then
-                      raise (BlockFound i)
-                  done;
+	  (* Pick really rare gems *)
+	  let cmp = 
+	    if mean_availability > 5 &&
+	      (c1.choice_availability <= 3 || c2.choice_availability <= 3) then
+		compare c2.choice_availability c1.choice_availability 
+	    else 0 in
+	  if cmp <> 0 then cmp else
 
-(************* Otherwise, download in random order *)
+	  (* try to quickly complete blocks *)
+	  let cmp = 
+	    if need_to_complete_some_blocks_quickly then
+	      compare c2.choice_remaining c1.choice_remaining else 0 in
+	  if cmp <> 0 then cmp else
 
-                if debug_all then lprintf "{Random}";
-                let find_random max_uploaders =
-                  let list = ref [] in
-                  if debug_all then lprintf " {NC: %d}" up.up_ncomplete;
-                  for i = 0 to up.up_ncomplete - 1 do
-                    let n = up.up_complete_blocks.(i) in
-                    if s.s_nuploading.(n) < max_uploaders
-                        && should_download_block s n
-                    then
-                      list := i :: !list
-                  done;
-                  match !list with
-                    [] -> ()
-                  | [i] -> raise (BlockFound i)
-                  | list ->
-                      let array = Array.of_list list in
-                      raise (BlockFound (array.(
-                            random_int (Array.length array))))
-                in
+	  (* try to quickly complete (and validate) chunks *)
+	  let cmp = 
+	    if verification_available && several_frontends then 
+	      compare (Lazy.force c1.choice_other_complete)
+		(Lazy.force c2.choice_other_complete)
+	    else 0 in
+	  if cmp <> 0 then cmp else
 
-                find_random max_nuploaders
+	  (* Can't tell *)
+	  0 in
 
-(************* Fall back on linear download if nothing worked *)
+	let best_choices = array_fold_lefti (fun acc n b ->
+	  (* priority bitmap <> 0 here ? *)
+	  if not (should_download_block s b) then acc else
+	    let nchunk = my_t.t_chunk_of_block.(b) in
+	    let block_begin = compute_block_begin s b in
+	    let block_end = compute_block_end s b in
+	    let size = block_end -- block_begin in
+	    let remaining = match s.s_blocks.(b) with
+		| EmptyBlock -> size
+		| PartialBlock b -> b.block_remaining
+		| CompleteBlock | VerifiedBlock -> 0L in
+	    let nuploaders = s.s_nuploading.(b) in
+	    let this_choice = {
+	      choice_num = n;
+	      choice_user_priority = (* priority bitmap here instead ? *)
+		if block_begin < preview_beginning then 3 else
+		  if block_end > preview_end then 2 else 1;
+	      choice_nuploaders = nuploaders;
+	      choice_size = size;
+	      choice_remaining = remaining;
+	      choice_remaining_per_uploader = remaining //
+		(Int64.of_int (nuploaders + 1)); (* planned value *)
+	      choice_other_complete = completed_blocks_in_chunk.(nchunk);
+	      choice_availability = s.s_availability.(b);
+	    } in
+	    match acc with
+	    | [] -> [this_choice]
+	    | h :: _ ->
+		(* all the choices in the accumulator are supposed to
+		   be equivalent, compare against the first *)
+		let cmp = compare_choices this_choice h in
+		if cmp > 0 then [this_choice]
+		else if cmp < 0 then acc
+		else this_choice :: acc
+	) [] up.up_complete_blocks in
+	(* what about up_partial_blocks ? 
+	   currently they're taken care of by linear_select_block
+	   fallback below *)
 
-              in
-              iter_max_uploaders !!sources_per_chunk;
-              iter_max_uploaders max_int;
-              raise Not_found
-            with
-              BlockFound n ->
-                if debug_all then lprintf "\nBlockFound %d\n"
-                    up.up_complete_blocks.(n);
-                permute_and_return up n
-          end else
-          LinearStrategy.select_block up
+	try
+	  let result = 
+	    match best_choices with
+	      | [] -> raise Not_found
+	      | [choice] -> choice
+	      | _::_ -> 
+		  let nchoices = List.length best_choices in
+		  List.nth best_choices (Random.int nchoices) in
+	  let n = result.choice_num in
+	  
+          if debug_all then lprintf "\nBlockFound %d\n"
+            up.up_complete_blocks.(n);
+          permute_and_return up n
+	with Not_found ->
+	  linear_select_block up
   with Not_found ->
 
       (* print_s "NO BLOCK FOUND" s; *)
-      raise Not_found
+    raise Not_found
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         find_block                                    *)
-(*                                                                       *)
-(*************************************************************************)
+(** If uploader is associated to a file being downloaded,
+    clear previously selected block (in any) and select best available
+    block, according to block selection strategy 
+    @param up the uploader *)
 
 let find_block up =
   try
     if debug_all then begin
-        lprintf "C: ";
-        for i = 0 to up.up_ncomplete - 1 do
-          lprintf "%d " up.up_complete_blocks.(i)
-        done;
-      end;
+      lprintf "C: ";
+      for i = 0 to up.up_ncomplete - 1 do
+        lprintf "%d " up.up_complete_blocks.(i)
+      done;
+    end;
 
     let t = up.up_t in
     let s = t.t_s in
     match file_state t.t_file with
     | FilePaused
     | FileAborted _
-    | FileCancelled -> raise Not_found
-    | _ ->
-
-
+    | FileCancelled 
+    | FileShared
+    | FileNew 
+    | FileDownloaded -> 
+	raise Not_found
+    | FileDownloading
+    | FileQueued ->
         (match up.up_block with
-            None -> ()
-          | Some b ->
-              let num = b.block_num in
-              s.s_nuploading.(num) <- s.s_nuploading.(num) - 1;
-              up.up_block <- None;
+	 | None -> ()
+         | Some b ->
+             let num = b.block_num in
+             s.s_nuploading.(num) <- s.s_nuploading.(num) - 1;
+             up.up_block <- None;
         );
 
-        let (b,block_begin,block_end) (* as result *) = select_block up in
+        let b, block_begin, block_end = select_block up in
         let num = b.block_num in
         s.s_nuploading.(num) <- s.s_nuploading.(num) + 1;
         up.up_block <- Some b;
@@ -2179,60 +2003,33 @@
         if debug_all then lprintf " = %d \n" num;
         b
   with e ->
-      if debug_all then lprintf_nl () "Exception %s" (Printexc2.to_string e);
-      raise e
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         clean_ranges (internal)                       *)
-(*                                                                       *)
-(*************************************************************************)
+    if debug_all then lprintf_nl "Exception %s" (Printexc2.to_string e);
+    raise e
 
-let clean_ranges up =
+(** Remove completed ranges from an uploader's range list, and
+    decrease their reference counter *)
 
-  let rec iter list left =
-    match list with
-      [] -> List.rev left
-    | ((_,_,r) as rr) :: tail ->
-        iter tail
-          (if r.range_current_begin < r.range_end then rr :: left
-          else begin
-              r.range_nuploading <- r.range_nuploading - 1;
-              left
-            end)
-  in
-  up.up_ranges <- iter up.up_ranges []
+let remove_completed_uploader_ranges up =
+  let not_completed_ranges, completed_ranges = 
+    List.partition (fun (_,_,r) -> 
+      r.range_begin < r.range_end) up.up_ranges in
+  up.up_ranges <- not_completed_ranges;
+  List.iter (fun (_,_,r) -> 
+    r.range_nuploading <- r.range_nuploading - 1) completed_ranges
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         current_ranges                                *)
-(*                                                                       *)
-(*************************************************************************)
+(** uploader accessors *)
 
 let current_ranges up =  up.up_ranges
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         current_block                                 *)
-(*                                                                       *)
-(*************************************************************************)
-
 let current_block up =
   match up.up_block with
-    None -> raise Not_found
+  | None -> raise Not_found
   | Some b -> b
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         in_uploader_ranges                            *)
-(*                                                                       *)
-(*************************************************************************)
+(** Check whether a range is in a list *)
 
-let rec in_uploader_ranges r list =
-  match list with
-    [] -> false
-  | (_,_,r') :: tail when r' == r -> true
-  | _ :: tail -> in_uploader_ranges r tail
+let in_uploader_ranges r list =
+  List.exists (fun (_,_,r') -> r' == r) list
 
 (*************************************************************************)
 (*                                                                       *)
@@ -2240,262 +2037,200 @@
 (*                                                                       *)
 (*************************************************************************)
 
+let uploader_ranges_fold_left f acc l =
+  let rec aux acc l =
+    match l with
+    | [] -> acc
+    | h :: q -> aux (f acc h) q
+  in aux acc l
+
 let find_range up =
-  clean_ranges up;
+  remove_completed_uploader_ranges up;
 
   let b =
     match up.up_block with
-      None -> raise Not_found
+    | None -> raise Not_found
     | Some b -> b
   in
-  let r = b.block_ranges in
-
   let t = up.up_t in
-
   match file_state t.t_file with
   | FilePaused
   | FileAborted _
-  | FileCancelled -> raise Not_found
-  | _ ->
-
-      let rec iter limit r =
-
-(* let use a very stupid heuristics: ask for the first non-used range.
-we thus might put a lot of clients on the same range !
-*)
+  | FileCancelled 
+  | FileShared
+  | FileNew
+  | FileDownloaded -> 
+      raise Not_found
+  | FileDownloading
+  | FileQueued ->
+      (* pick the first correct range with fewest uploaders *)
+      let best_range =
+	let rec iter acc r =
+	  let better_found =
+	    if in_uploader_ranges r up.up_ranges ||
+	      r.range_begin = r.range_end ||
+	      r.range_begin < up.up_block_begin ||
+	      r.range_end > up.up_block_end then
+		false
+	    else
+	      match acc with
+	      | None -> true
+	      | Some best_range ->
+		  best_range.range_nuploading > r.range_nuploading in
+	  (* fast exit, and why I didn't use an iterator :/ *)
+	  if better_found && r.range_nuploading = 0 then Some r
+	  else
+	    let acc = if better_found then Some r else acc in
+	    match r.range_next with
+	    | None -> acc
+	    | Some rr -> iter acc rr in
+	iter None b.block_ranges in
+      match best_range with
+      | None -> raise Not_found
+      | Some r ->
+	  let key = r.range_begin, r.range_end, r in
+	  up.up_ranges <- up.up_ranges @ [key];
+	  r.range_nuploading <- r.range_nuploading + 1;
+	  key
 
-        if not (in_uploader_ranges r up.up_ranges) &&
-          r.range_current_begin < r.range_end &&
-          r.range_current_begin >= up.up_block_begin &&
-          r.range_end <= up.up_block_end &&
-          r.range_nuploading < limit
-        then begin
-            let key = r.range_current_begin, r.range_end, r in
-            up.up_ranges <- up.up_ranges @ [key];
-            r.range_nuploading <- r.range_nuploading + 1;
-            if r.range_current_begin = r.range_end then
-              lprintf_nl () "error: range is empty error";
-            key
-          end else
-        match r.range_next with
-          None -> raise Not_found
-        | Some rr -> iter limit rr
-      in
-      try
-(* try normal ranges *)
-        iter !!sources_per_chunk r
-      with Not_found ->
-(* force maximal uploading otherwise to finish it *)
-          iter max_int r
+(** range accessor(s) *)
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         range_range                                   *)
-(*                                                                       *)
-(*************************************************************************)
+let range_range r = (r.range_begin, r.range_end)
 
-let range_range r = (r.range_current_begin, r.range_end)
+(** Data has been received from uploader [up]. Transfer data to file
+    and update uploader ranges.
+    Data = String.sub [str] [string_begin] [string_len] *)
 
-(*************************************************************************)
-(*                                                                       *)
-(*                         received                                      *)
-(*                                                                       *)
-(*************************************************************************)
+let received up file_begin str string_begin string_len =
+  assert (string_begin >= 0);
+  assert (string_len >= 0);
+  assert (string_begin + string_len <= String.length str);
 
-let received (up : uploader) (file_begin : Int64.t)
-  (str:string) (string_begin:int) (string_len:int) =
+(*
+  let debug_bad_write r string_pos =
+    if !verbose then begin
+      let t = up.up_t in
+      let s = t.t_s in
+      lprintf_nl "BAD WRITE in %s for range %Ld-%Ld (string_pos %d)"
+        (file_best_name t.t_file) r.range_begin r.range_end string_pos;
+      lprintf_nl "  received: file_pos:%Ld string:%d %d"
+        file_begin string_begin string_len;
+      lprintf_nl "  ranges:";
+      List.iter (fun (_,_,r) ->
+        lprintf_n "     range: %Ld-%Ld"
+          r.range_begin
+          r.range_end;
+        (match r.range_next with
+          | None -> ()
+          | Some rr ->
+              lprintf "  next: %Ld" rr.range_begin);
+        (match r.range_prev with
+          | None -> ()
+          | Some rr ->
+              lprintf "  prev: %Ld" rr.range_begin);
+        lprint_newline ();
+        let b = r.range_block in
+        lprintf_n "        block: %d[%c] %Ld-%Ld [%s]"
+          b.block_num
+          s.s_verified_bitmap.[b.block_num]
+          b.block_begin b.block_end
+          (match s.s_blocks.(b.block_num) with
+            | EmptyBlock -> "empty"
+            | PartialBlock _ -> "partial"
+            | CompleteBlock -> "complete"
+            | VerifiedBlock -> "verified"
+          );
+        let br = b.block_ranges in
+        lprintf " first range: %Ld(%Ld)"
+          br.range_begin
+          (br.range_end -- br.range_begin);
+        lprint_newline ();
+      ) up.up_ranges
+    end;
+  if !exit_on_error then exit 2 in *)
 
   if string_len > 0 then
     let file_end = file_begin ++ (Int64.of_int string_len) in
 
     if !verbose_swarming then
-      lprintf_nl () "received on %Ld-%Ld" file_begin file_end;
+      lprintf_nl "received on %Ld-%Ld" file_begin file_end;
 
 (* TODO: check that everything we received has been required *)
     let t = up.up_t in
     let s = t.t_s in
-    try
-
-      List.iter (fun (_,_,r) ->
-          if r.range_current_begin < file_end &&
-            r.range_end > file_begin then begin
-
-              let file_end = min file_end r.range_end in
-              let written_len = file_end -- r.range_current_begin in
-
-              begin
-                match file_state t.t_file with
-                | FilePaused
-                | FileAborted _
-                | FileCancelled -> ()
-                | _ ->
-
-                    let string_pos = string_begin +
-                        Int64.to_int (r.range_current_begin -- file_begin) in
-                    let string_length = Int64.to_int written_len in
-
-                    if
-                      string_pos < 0 ||
-                      string_pos < string_begin ||
-                      string_len < string_length then begin
-                        if !verbose then
-                        begin
-                        lprintf_nl () "BAD WRITE in %s for range %Ld-%Ld (string_pos %d)"
-                          (file_best_name t.t_file) r.range_begin r.range_end string_pos;
-                        lprintf_nl () "  received: file_pos:%Ld string:%d %d"
-                          file_begin string_begin string_len;
-                        lprintf_nl () "  ranges:";
-                        List.iter (fun (_,_,r) ->
-                            lprintf_n () "     range: %Ld-[%Ld]-%Ld"
-                              r.range_begin r.range_current_begin
-                              r.range_end;
-                            (match r.range_next with
-                                None -> ()
-                              | Some rr ->
-                                  lprintf "  next: %Ld" rr.range_begin);
-                            (match r.range_prev with
-                                None -> ()
-                              | Some rr ->
-                                  lprintf "  prev: %Ld" rr.range_begin);
-                            lprint_newline ();
-                            let b = r.range_block in
-                            lprintf_n () "        block: %d[%c] %Ld-%Ld [%s]"
-                              b.block_num
-                              s.s_verified_bitmap.[b.block_num]
-                              b.block_begin b.block_end
-                              (match s.s_blocks.(b.block_num) with
-                                EmptyBlock -> "empty"
-                              | PartialBlock _ -> "partial"
-                              | CompleteBlock -> "complete"
-                              | VerifiedBlock -> "verified"
-                            );
-                            let br = b.block_ranges in
-                            lprintf " first range: %Ld(%Ld)"
-                              br.range_begin
-                              (br.range_end -- br.range_current_begin);
-                            lprint_newline ();
-                        ) up.up_ranges;
-                        end;
-                        if !exit_on_error then exit 2
-                      end else
-                    if string_length > 0 then
-                      match s.s_networks with
-                        [] -> assert false
-                      | t :: _ when t.t_primary ->
-                          file_write t.t_file
-                            r.range_current_begin
-                            str string_pos string_length;
-                      | _ -> ()
-              end;
-              range_received (Some t) r r.range_current_begin file_end;
-
-            end
-      ) up.up_ranges;
-      clean_ranges up
-    with e ->
-        raise e
-
-
-(*************************************************************************)
-(*                                                                       *)
-(*                         present_chunks                                *)
-(*                                                                       *)
-(*************************************************************************)
-
-let present_chunks s =
-  let nblocks = Array.length s.s_blocks in
-(*  lprintf "present_chunks...%d blocks\n" nblocks; *)
-
-  let rec iter_block_out i block_begin list =
-    if debug_present_chunks then
-      lprintf_nl () "iter_block_out %d bb: %Ld"
-        i block_begin;
-
-    if i = nblocks then List.rev list else
-    let block_end = compute_block_end s i in
-    match s.s_blocks.(i) with
-      EmptyBlock ->
-        iter_block_out (i+1) block_end list
-    | CompleteBlock | VerifiedBlock ->
-        let block_begin = compute_block_begin s i in
-        iter_block_in (i+1) block_end block_begin list
-    | PartialBlock b ->
-        iter_range_out i block_end block_begin b.block_ranges  list
-
-  and iter_block_in i block_begin chunk_begin list =
-    if debug_present_chunks then
-      lprintf_nl () "iter_block_in %d bb: %Ld cb:%Ld"
-        i block_begin chunk_begin
-      ;
-
-    if i = nblocks then
-      let list = (chunk_begin, s.s_size) :: list in
-      List.rev list
-    else
-    let block_end = compute_block_end s i in
-    match s.s_blocks.(i) with
-      EmptyBlock ->
-        iter_block_out (i+1) block_end ( (chunk_begin, block_begin) :: list)
-    | CompleteBlock | VerifiedBlock ->
-        iter_block_in (i+1) block_end chunk_begin list
-    | PartialBlock b ->
-        iter_range_in i block_end
-          chunk_begin block_begin b.block_ranges list
+    match file_state t.t_file with
+    | FilePaused
+    | FileAborted _
+    | FileCancelled 
+    | FileShared
+    | FileNew
+    | FileDownloaded -> 
+	if !verbose then
+	  lprintf_nl "CommonSwarming.received: wrong file state";
+	()
+    | FileDownloading
+    | FileQueued ->
+	try
+	  List.iter (fun (_,_,r) ->
+    (* was: r.range_begin < file_end && r.range_end > file_begin *)
+            if r.range_begin >= file_begin &&
+              r.range_begin < file_end then 
+		let file_end = min file_end r.range_end in
+		let written_len = file_end -- r.range_begin in
+                let string_pos = string_begin +
+                  Int64.to_int (r.range_begin -- file_begin) in
+                let string_length = Int64.to_int written_len in
+		(* None of those conditions can happen anymore *)
+(*                if string_pos < 0 || 
+                  string_pos < string_begin || 
+                  string_len < string_length then 
+		    debug_bad_write r string_pos
+		  else *)
+                  if string_length > 0 then
+		    match s.s_networks with
+                    | [] -> assert false
+		    | tprim :: _ ->
+			assert (tprim.t_primary);
+                        file_write tprim.t_file
+                          r.range_begin
+                          str string_pos string_length;
+			range_received (Some t) r r.range_begin file_end;
+	  ) up.up_ranges;
+	  remove_completed_uploader_ranges up
+	with e ->
+	  remove_completed_uploader_ranges up;
+          raise e
 
-  and iter_range_out i block_end block_begin r list =
-    if debug_present_chunks then
-      lprintf_nl () "iter_range_out %d nb: %Ld bb:%Ld"
-        i block_end block_begin;
+(** compute the list of present intervals of a swarmer *)
 
-    if r.range_begin > block_begin then
-      iter_range_in i block_end block_begin r.range_begin r list
+let present_intervals s =
+  (* intervals is a reversed list of intervals *)
+  let append_interval ((interval_begin, interval_end) as interval) intervals =
+    (* remove void intervals *)
+    if interval_begin = interval_end then intervals
     else
+      match intervals with
+      | [] -> [interval]
+      | (last_interval_begin, last_interval_end) :: other_intervals  ->
+	  if last_interval_end < interval_begin then
+	    interval :: intervals
+	  else 
+	    (* coalescing intervals *)
+	    (last_interval_begin, interval_end) :: other_intervals in
 
-    if r.range_current_begin > block_begin then begin
-        if r.range_current_begin < r.range_end then
-          let list = (r.range_begin, r.range_current_begin) :: list in
-          match r.range_next with
-            None ->
-              iter_block_out (i+1) block_end list
-          | Some rr ->
-              iter_range_out i block_end r.range_end rr list
-        else
-        match r.range_next with
-          None ->
-            iter_block_in (i+1) block_end r.range_begin list
-        | Some rr ->
-            iter_range_in i block_end
-              r.range_begin r.range_end rr list
-      end else
-    match r.range_next with
-      None ->
-        iter_block_out (i+1) block_end list
-    | Some rr ->
-        iter_range_out i block_end r.range_end rr list
-
-
-  and iter_range_in i block_end chunk_begin chunk_end r list =
-    if debug_present_chunks then
-      lprintf_nl () "iter_range_in %d bn: %Ld cb:%Ld ce: %Ld"
-        i block_end chunk_begin chunk_end;
-
-    if r.range_current_begin < r.range_end then
-      let list = (chunk_begin, r.range_current_begin) :: list in
-      match r.range_next with
-        None ->
-          iter_block_out (i+1) block_end list
-      | Some rr ->
-          iter_range_out i block_end r.range_end rr list
-    else
-    match r.range_next with
-      None ->
-        iter_block_in (i+1) block_end chunk_begin list
-    | Some rr ->
-        iter_range_in i block_end chunk_begin r.range_end rr list
-  in
-  let chunks = iter_block_out 0 zero [] in
-(*  lprintf "present_chunks done\n"; *)
-  chunks
+  List.rev (
+    array_fold_lefti (fun acc i b -> 
+      match s.s_blocks.(i) with
+      | EmptyBlock -> acc
+      | CompleteBlock | VerifiedBlock ->
+	  append_interval (compute_block_begin s i, compute_block_end s i) acc
+      | PartialBlock b ->
+	  let acc, last_interval_end =
+	    block_ranges_fold (fun (acc,  lie) r ->
+	      (append_interval (lie, r.range_begin) acc, r.range_end)
+	    ) (acc, compute_block_begin s i) b in
+	  append_interval (last_interval_end, compute_block_end s i) acc
+    ) [] s.s_blocks)
 
 (*************************************************************************)
 (*                                                                       *)
@@ -2550,7 +2285,7 @@
           sw := (t, i, pos) :: !sw;
           iter (i+1) len (pos ++ bsize) bsize size
       in
-      iter 0 (Array.length t.t_checksums) zero t.t_block_size t.t_size
+      iter 0 (Array.length t.t_checksums) zero t.t_chunk_size t.t_size
   ) swarmers_by_num;
   Hashtbl.iter (fun c (has, has_not) ->
       match !has, !has_not with
@@ -2600,7 +2335,7 @@
     match bitmap.[i] with
     | '2' ->
         if t.t_converted_verified_bitmap.[i] < '2' then begin
-            t.t_ncomplete_blocks <- t.t_ncomplete_blocks + 1;
+            t.t_ncomplete_chunks <- t.t_ncomplete_chunks + 1;
             t.t_converted_verified_bitmap.[i] <- '2'
           end
 
@@ -2625,7 +2360,7 @@
                   ()
           ) t.t_blocks_of_chunk.(i);
           if t.t_converted_verified_bitmap.[i] <> '3' then
-            lprintf_nl () "FIELD AS BEEN CLEARED"
+            lprintf_nl "FIELD AS BEEN CLEARED"
     | _ -> ()
   done
 
@@ -2746,7 +2481,7 @@
 
 let set_present t = set_present t.t_s
 let set_absent t = set_absent t.t_s
-let present_chunks t = present_chunks t.t_s
+let present_intervals t = present_intervals t.t_s
 let print_t str t = print_s str t.t_s
 let print_uploaders t = print_uploaders t.t_s
 
@@ -2794,7 +2529,7 @@
             (get_value  "file_all_chunks" value_to_string)
 
     with e ->
-        lprintf_nl () "Exception %s while loading bitmap"
+        lprintf_nl "Exception %s while loading bitmap"
           (Printexc2.to_string e);
   );
 
@@ -2804,7 +2539,7 @@
 *)
 
   if primary then begin
-      if !verbose_swarming then lprintf_nl () "Loading present...";
+      if !verbose_swarming then lprintf_nl "Loading present...";
       let present = try
           let present =
             (get_value "file_present_chunks"
@@ -2813,46 +2548,46 @@
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
 
-              let p = present_chunks t in
-              lprintf_nl () "ERROR: present now:";
+              let p = present_intervals t in
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
@@ -2893,7 +2628,7 @@
   ("file_present_chunks", List
       (List.map (fun (i1,i2) ->
           SmallList [int64_to_value i1; int64_to_value i2])
-      (present_chunks t))) ::
+      (present_intervals t))) ::
   ("file_downloaded", int64_to_value (downloaded t)) ::
 
   ("file_chunks_age", List (Array.to_list
@@ -2955,27 +2690,28 @@
   let s1 = HS.find swarmers_by_name { dummy_swarmer with s_filename = file_disk_name f1 } in
   let s2 = HS.find swarmers_by_name { dummy_swarmer with s_filename = file_disk_name f2 } in
 
-  if s1 == s2 then
+  if s1.s_filename = s2.s_filename then
     failwith "Files are already sharing their swarmer";
 
   if s1.s_size <> s2.s_size then
     failwith "Files don't have the same size";
 
-  let t2 = match s2.s_networks with
-      [t] -> t
+  let t2 = 
+    match s2.s_networks with
+    | [t] -> t
     | list ->
-        lprintf_nl () "s_networks: %d files" (List.length list);
+        lprintf_nl "s_networks: %d files" (List.length list);
         failwith "Second file is already merged with other files"
   in
 
   let t1 =
     match s1.s_networks with
-      [] -> assert false
+    | [] -> assert false
     | t1 :: _ ->
         match t1.t_verifier with
-          NoVerification ->
+	| NoVerification | VerificationNotAvailable ->
             failwith "Cannot use first file as a primary for swarming (no verification scheme)"
-        | _ -> t1
+        | Verification _ | ForceVerification -> t1
   in
 
   begin
@@ -3012,7 +2748,7 @@
     None -> () 
   | Some sw -> if not (has_secondaries sw)
                 then HS.remove swarmers_by_name sw.t_s
-                else lprintf_nl () "Tried to remove swarmer with secondaries"
+                else lprintf_nl "Tried to remove swarmer with secondaries"
 
 (*************************************************************************)
 (*                                                                       *)
@@ -3037,7 +2773,7 @@
           let get_value name conv = conv (List.assoc name assocs) in
           let file_size = get_value "file_size" value_to_int64 in
           let file_name = get_value "file_name" value_to_string in
-          let s = create_swarmer file_name file_size edonkey_range_size in
+          let s = create_swarmer file_name file_size in
           let block_sizes = get_value "file_chunk_sizes"
               (value_to_list value_to_int64) in
           List.iter (fun bsize ->
@@ -3053,7 +2789,7 @@
         ("file_name", string_to_value s.s_filename);
         ("file_bitmap", string_to_value s.s_verified_bitmap);
         ("file_chunk_sizes", list_to_value int64_to_value
-            (List.map (fun t -> t.t_block_size) s.s_networks));
+            (List.map (fun t -> t.t_chunk_size) s.s_networks));
         ]
 
     let t =
@@ -3189,9 +2925,8 @@
             Array.length up.up_complete_blocks * 4 +
             List.length up.up_ranges * (12 + 16 + 12 + 12 +  4) +
             Array.length up.up_partial_blocks * (16 + 12 + 12) +
-            (8 + match up.up_chunks with
-              AvailableRanges list -> List.length list * (12 + 12 + 12 + 12)
-            | AvailableCharBitmap s -> 8 + String.length s
+            (8 + match up.up_intervals with
+            | AvailableIntervals list -> List.length list * (12 + 12 + 12 + 12)
             | AvailableBitv b -> let ws = Sys.word_size in (ws/8) + ((ws / 8) * (Bitv.length b / (ws - 2))) 
           ) ;
           incr counter;
@@ -3211,7 +2946,7 @@
           if bitmap.[i] <> '3' then raise Not_found;
         done;
         if file_size file <> downloaded t then
-          lprintf_nl () "Downloaded size differs after complete verification";
+          lprintf_nl "Downloaded size differs after complete verification";
         true
   with _ -> false
 
