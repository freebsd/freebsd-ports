--- src/Burlap/descriptor.c.orig	Tue Feb 22 07:44:29 2000
+++ src/Burlap/descriptor.c	Sat Aug  4 22:27:44 2007
@@ -307,7 +307,7 @@
 	    D_Type     (dest) = T_External;
 	    D_Temp     (dest) = F_False;
 	    D_Trapped  (dest) = F_False;
-	    D_External (dest) = D_External (src);
+	    dest->u.ptr       = D_External (src);
 	    break;
 
 
