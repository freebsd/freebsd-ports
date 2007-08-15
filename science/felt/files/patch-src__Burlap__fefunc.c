--- src/Burlap/fefunc.c.orig	Tue Feb 22 07:44:30 2000
+++ src/Burlap/fefunc.c	Sat Aug  4 22:27:48 2007
@@ -190,7 +190,7 @@
 	    D_Type    (arg1) = T_Element;
 	    D_Temp    (arg1) = F_False;
 	    D_Trapped (arg1) = F_False;
-	    D_Element (arg1) = &element;
+	    arg1->u.ptr      = &element;
 
 	    D_Type    (arg2) = T_Int;
 	    D_Temp    (arg2) = F_False;
@@ -247,7 +247,7 @@
 	    D_Type    (arg1) = T_Element;
 	    D_Temp    (arg1) = F_False;
 	    D_Trapped (arg1) = F_False;
-	    D_Element (arg1) = &element;
+	    arg1->u.ptr      = &element;
 
 	    if (!function_call (function, 1)) {
 		result = top ( );
