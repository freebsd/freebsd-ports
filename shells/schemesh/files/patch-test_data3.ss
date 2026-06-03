--- test/data3.ss.orig	2025-12-28 20:30:02 UTC
+++ test/data3.ss
@@ -138,7 +138,7 @@
 
   ;; ------------------------- wildcard expansion -------------------------
   (wildcard1+ #t "a" "bcd" "" "ef")                   ("abcdef")
-  (wildcard1+ #t '* "f" '*)                           ("Makefile" "default.nix" "srfi")
+  (wildcard1+ #t '* "f" '*)                           ("Makefile" "Makefile.bak" "default.nix" "srfi")
   (wildcard->sh-patterns '(*))                      ,@(span (sh-pattern '*))
   (wildcard->sh-patterns '("/" * ".so"))            ,@(span "/" (sh-pattern '* ".so"))
   (wildcard->sh-patterns '("//abc//" "//def//"))    ,@(span "/" "abc/" "def/")
