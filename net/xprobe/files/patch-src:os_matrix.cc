--- src/os_matrix.cc.orig	Fri Sep 26 13:40:23 2003
+++ src/os_matrix.cc	Thu Feb 26 00:33:20 2004
@@ -84,8 +84,7 @@
     xprobe_mdebug(XPROBE_DEBUG_OSMATRIX,"Following systems are recognizable\n");
     for (osid_i = osid_name.begin();
          osid_i != osid_name.end(); osid_i++) {
-        xprobe_debug(XPROBE_DEBUG_OSMATRIX,"Id: %i\tOS:
-        %s\n",(*osid_i).first, (*osid_i).second.c_str());
+        xprobe_debug(XPROBE_DEBUG_OSMATRIX,"Id: %i\tOS: %s\n",(*osid_i).first, (*osid_i).second.c_str());
     }
 }
 
