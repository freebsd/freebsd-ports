--- leif/sun_le_korea/korean/lookupbuf.c	Sat Mar 27 10:46:45 2004
+++ leif/sun_le_korea/korean/lookupbuf.c	Wed Feb 16 20:46:54 2005
@@ -547,7 +547,7 @@
   }
   fp = fopen (argv[1], "w");
   
-  construct_binary_tree_from_file ("/usr/lib/im/locale/ko_KR/common/data/hhdict",
+  construct_binary_tree_from_file (IMDIR "/locale/ko_KR/common/data/hhdict",
 				   &trees, &n_trees);
   mthd_return = dictionary_search_hanja_candidates_in_utf16
     (ga, &n_candidates, &cand );
