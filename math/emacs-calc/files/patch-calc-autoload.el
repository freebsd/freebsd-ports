--- calc-autoload.el.orig	Wed Dec 31 19:00:00 1969
+++ calc-autoload.el	Sun Jul 10 12:05:24 2005
@@ -0,0 +1,16 @@
+
+(global-set-key '[?\M-# ?c] 'calc)
+
+(autoload 'defmath		  "calc" nil                          t t)
+(autoload 'calc-eval		  "calc" "Use Calculator from Lisp"   )
+(autoload 'calc-dispatch	  "calc" "Calculator Options"         t)
+(autoload 'full-calc		  "calc" "Full-screen Calculator"     t)
+(autoload 'full-calc-keypad	  "calc" "Full-screen X Calculator"   t)
+(autoload 'calc			  "calc" "Calculator Mode"            t)
+(autoload 'quick-calc		  "calc" "Quick Calculator"           t)
+(autoload 'calc-keypad		  "calc" "X windows Calculator"       t)
+(autoload 'calc-embedded	  "calc" "Use Calc inside any buffer" t)
+(autoload 'calc-embedded-activate "calc" "Activate =>'s in buffer"    t)
+(autoload 'calc-grab-region	  "calc" "Grab region of Calc data"   t)
+(autoload 'calc-grab-rectangle	  "calc" "Grab rectangle of data"     t)
+
