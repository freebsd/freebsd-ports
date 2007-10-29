--- libdesktopbsd-ui/moddevinfo.ui.h.orgi	2007-10-29 19:53:33.000000000 +0100
+++ libdesktopbsd-ui/moddevinfo.ui.h	2007-10-29 19:54:09.000000000 +0100
@@ -32,7 +32,7 @@
 
 	if(dev->dd_name[0] != '\0' && dev->dd_state >= DIS_ATTACHED) {
 		Device  device(dev->dd_name);
-		uint level = (uint) arg;
+		uint64_t level = (uint64_t) arg;
 
 		/* Check the index in parents[], even if it is
 		 * highly unlikely that it is > 32.
