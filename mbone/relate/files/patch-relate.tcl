--- relate.tcl.org	Tue May 15 14:45:03 2001
+++ relate.tcl	Tue May 15 14:46:10 2001
@@ -550,7 +550,7 @@
 	frame .r.b.rat -container true
 	pack .r.b.rat -side left
 	set ratwin [winfo id .r.b.rat]
-    set commandline "exec rat -lbl_channel $channel -smallui -use $ratwin [set "audio.arguments"]"
+    set commandline "exec rat30 -lbl_channel $channel -smallui -use $ratwin [set "audio.arguments"]"
 	catch {set ratproc [eval $commandline &] }
 
 	pack .r.b.rat -side left
