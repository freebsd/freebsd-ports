--- hexcalc.c.orig	2011-05-13 08:28:24.000000000 +0800
+++ hexcalc.c	2011-05-13 08:32:09.000000000 +0800
@@ -37,6 +37,7 @@
 #endif	
 
 #include	<stdio.h>
+#include	<stdlib.h>
 #include	<ctype.h>
 #include	<X11/IntrinsicP.h>
 #include	<X11/StringDefs.h>
@@ -509,14 +510,16 @@
 
 		switch(topOp) {
 		case '+' :
-			ac = PopArg()  + PopArg();
+                        temp = PopArg();
+			ac = PopArg() + temp;
 			break;
 		case '-' :
 			temp = PopArg();
 			ac = PopArg() - temp;
 			break;
 		case '*' :
-			ac = PopArg()  * PopArg();
+                        temp = PopArg();
+			ac = temp * PopArg();
 			break;
 		case '/' :
 			temp = PopArg();
@@ -528,15 +531,18 @@
 			break;
 			
 		case '|' :
-			ac = PopArg() | PopArg();
+                        temp = PopArg();
+			ac = temp | PopArg();
 			break;
 
 		case '&' :
-			ac = PopArg() & PopArg();
+                        temp = PopArg();
+			ac = temp & PopArg();
 			break;
 
 		case '^' :
-			ac = PopArg() ^ PopArg();
+                        temp = PopArg();
+			ac = temp ^ PopArg();
 			break;
 
 		case '<' :
