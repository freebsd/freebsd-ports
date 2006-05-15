--- ./src/networks/donkey/donkeyShare.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/donkey/donkeyShare.ml	Mon May 15 13:03:12 2006
@@ -107,7 +107,7 @@
 (*    file.file_all_chunks <- String.make file.file_nchunks '1'; *)
     (* Should we trust mtimes, or reverify each file.  If we trust
      * mtimes, I guess we have to call
-     * CommonSwarming.set_verified_bitmap "333..."
+     * CommonSwarming.set_chunks_verified_bitmap "333..."
      * this seems unspeakably ugly, but the alternative is to reverify
      * every shared file every hour.
      *
@@ -122,7 +122,7 @@
     match file.file_swarmer with
       Some s -> (let len = Array.length md4s in
 		 let ver_str = String.make len '3' in
-		     CommonSwarming.set_verified_bitmap s ver_str;
+		     CommonSwarming.set_chunks_verified_bitmap s ver_str;
 		 (*
 		 CommonSwarming.set_present s [(Int64.zero, file_size file)];
 		 (* If we don't verify now, it will never happen! *)
@@ -130,7 +130,7 @@
 		 *)
                 if !verbose_share then
                   lprintf_nl () "verified map of %s = %s"
-		         (codedname) (CommonSwarming.verified_bitmap s))
+		         (codedname) (CommonSwarming.chunks_verified_bitmap s))
       | None -> if !verbose_share then lprintf_nl () "no swarmer for %s" codedname;
     (try
         file.file_format <- CommonMultimedia.get_info
