--- sulci/plugin_cerberus.ml.orig	Sun Sep 18 16:10:16 2005
+++ sulci/plugin_cerberus.ml	Tue Sep 20 16:23:52 2005
@@ -10,7 +10,7 @@
 open Hooks
 
 let regexp ca          = 0x430 | 0x410 | 'a' | 'A'
-let regexp cb          = 0x431 | 0x411 | '6'
+let regexp cb          = 0x431 | 0x411
 let regexp cv          = 0x432 | 0x412 | 'B' 
 let regexp cg          = 0x433 | 0x413
 let regexp cd          = 0x434 | 0x414
@@ -45,7 +45,7 @@
 
 let regexp cyrillic = [0x410-0x44F 0x451 0x401 '0' '3' 'a''A' 'e' 'E' 'H' 
 			  'o' 'O' 'c' 'C' 'k' 'K' 'T' 'x' 'X' 'y' 'Y' 'p' 
-			  'P' '6' '0'] | "|/|" | "bl" | "bI"
+			  'P' '0'] | "|/|" | "bl" | "bI"
 
 let regexp ci_ie_io = ci | cie | cio
 let regexp cie_io = cie | cio
