--- emacs/uim-var.el.orig	2023-08-22 15:31:18 UTC
+++ emacs/uim-var.el
@@ -435,7 +435,7 @@ keeps the size of it when showing the candidates.")
 (make-face 'uim-preedit-face)
 
 (copy-face 'uim-preedit-face 'uim-preedit-underline-face)
-(set-face-underline-p        'uim-preedit-underline-face t)
+(set-face-underline          'uim-preedit-underline-face t)
 
 ;; highlight
 (make-face 'uim-preedit-highlight-face)
@@ -443,7 +443,7 @@ keeps the size of it when showing the candidates.")
 (set-face-background 'uim-preedit-highlight-face "Blue3")
 
 (copy-face 'uim-preedit-highlight-face 'uim-preedit-highlight-underline-face)
-(set-face-underline-p 'uim-preedit-highlight-underline-face t)
+(set-face-underline 'uim-preedit-highlight-underline-face t)
 
 ;; separator
 (make-face 'uim-separator-face)
