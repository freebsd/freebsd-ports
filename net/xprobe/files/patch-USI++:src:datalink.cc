--- libs-external/USI++/src/datalink.cc.orig	Fri Sep 26 13:40:23 2003
+++ libs-external/USI++/src/datalink.cc	Mon Mar 22 17:26:18 2004
@@ -249,7 +249,7 @@
 
 	// loopback
 	case DLT_NULL:
-		d_framelen = 0;
+		d_framelen = 4;
 		break;
 #ifdef DLT_LINUX_SLL
     case DLT_LINUX_SLL:
@@ -349,6 +349,8 @@
                 break;
 	case DLT_RAW:
 		break;
+	case DLT_NULL:
+		break;	
 #ifdef DLT_LINUX_SLL
     case DLT_LINUX_SLL:
         break;          
