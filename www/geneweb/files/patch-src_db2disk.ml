--- src/db2disk.ml.orig	2024-02-11 18:31:31 UTC
+++ src/db2disk.ml
@@ -230,7 +230,7 @@ value spi2_first db2 spi (f1, f2) s = do {
         let ic = fast_open_in_bin_and_seek db2 f1 f2 "index.dat" pos in
         try
           loop i where rec loop i =
-            let (s1, pos) : (string * int) = Iovalue.input ic in
+            let (s1, pos) = Iovalue.input ic in
             if start_with s1 s then Some (s1, pos, i) else loop (i + 1)
         with
         [ End_of_file -> None ]
@@ -284,7 +284,7 @@ value spi2_next db2 spi (f1, f2) need_whole_list =
             let pos = input_binary_int ic in
             fast_open_in_bin_and_seek db2 f1 f2 "index.dat" pos
           in
-          let (s, pos) : (string * int) = Iovalue.input ic in
+          let (s, pos) = Iovalue.input ic in
           let dlen = i - spi.curr_i in
           Some (i, s, pos, dlen)
         with
