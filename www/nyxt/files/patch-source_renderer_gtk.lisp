--- source/renderer/gtk.lisp.orig	2025-11-09 06:33:25 UTC
+++ source/renderer/gtk.lisp
@@ -641,7 +641,7 @@ Return nil when key must be discarded, e.g. for modifi
                (member :meta-mask modifier-state))
       (alex:deletef (modifiers browser) :super-mask))))
 
-(-> translate-modifiers (list &optional gdk:gdk-event) list)
+(-> translate-modifiers (list &optional t) list)
 (defun translate-modifiers (modifier-state &optional event)
   "Return list of modifiers fit for `keymaps:make-key'.
 See `gtk-browser's `modifier-translator' slot."
