--- lib/html_text.tcl.orig	2017-11-09 20:42:24.000000000 -0800
+++ lib/html_text.tcl	2021-08-31 11:19:25.451174000 -0700
@@ -60,7 +60,7 @@
     }
     set state(tag) $tag
     $win dump -tag -text -window -command \
-	    [list TextUndoTagAddProc state $win] $m1 $m2
+	    [list TextUndoTagAddProc state $win] $m1 $m2 tag
     TextUndoTagAdd state $win [$win index $m2]
     $win tag add $tag $m1 $m2
 }
@@ -179,7 +179,7 @@
 	unset state(ix)
     }
 }
-proc TextUndoTagAddProc {stateVar win key value ix} {
+proc TextUndoTagAddProc {stateVar win key value ix tag} {
     upvar $stateVar state
     switch -- $key {
 	tagon {
