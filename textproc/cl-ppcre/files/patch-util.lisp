--- util.lisp.orig	Fri May 16 23:16:22 2003
+++ util.lisp	Fri May 16 23:16:42 2003
@@ -155,10 +155,10 @@
   (loop with min1 and min2 and min3
         and max1 and max2 and max3
         ;; loop through all characters in HASH, sorted by CHAR<
-        for chr in (sort (loop for chr being the hash-keys of hash
-                               collect (if downcasep
-                                         (char-downcase chr)
-                                         chr))
+        for chr in (sort (the list (loop for chr being the hash-keys of hash
+					 collect (if downcasep
+						     (char-downcase chr)
+						     chr)))
                          #'char<)
         for code = (char-code chr)
         ;; MIN1, MAX1, etc. are _exclusive_
