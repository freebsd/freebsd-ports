Index: lib/thread.tcl
===================================================================
RCS file: /cvsroot/exmh/exmh/lib/thread.tcl,v
retrieving revision 1.8
retrieving revision 1.9
diff -u -r1.8 -r1.9
--- lib/thread.tcl	18 Feb 2003 06:50:43 -0000	1.8
+++ lib/thread.tcl	8 Apr 2003 17:44:37 -0000	1.9
@@ -251,8 +251,9 @@
         Exmh_Status "folder incorrectly threaded. line number mismatch" warn
     }
 
-    Seq_Forget $folder $mhProfile(unseen-sequence)
-    Ftoc_ShowSequence $mhProfile(unseen-sequence)
+#    Seq_Forget $folder $mhProfile(unseen-sequence)
+#    Ftoc_ShowSequence $mhProfile(unseen-sequence)
+    Ftoc_ShowSequences
 
     if {$curmsg != {}} {
         set msg(id) $curmsg
