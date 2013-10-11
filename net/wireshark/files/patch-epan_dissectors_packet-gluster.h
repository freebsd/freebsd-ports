--- epan/dissectors/packet-gluster.h.orig	2013-10-10 23:19:31.007195841 +0000
+++ epan/dissectors/packet-gluster.h	2013-10-10 23:20:32.550304872 +0000
@@ -354,6 +354,8 @@
 	GFS3_OP_MAXVALUE
 };
 
+# if !defined(__FreeBSD__)
+
 /* dir-entry types from libglusterfs/src/compat.h */
 enum gluster_entry_types {
 	DT_UNKNOWN = 0,
@@ -367,6 +369,7 @@
 	DT_WHT = 14
 };
 
+# endif
 
 /* LOCKING operators come from libglusterfs/src/glusterfs.h */
 
