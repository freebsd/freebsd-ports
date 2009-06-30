--- src/privproc.c
+++ src/privproc.c
@@ -122,7 +122,6 @@ miredo_privileged_process (unsigned ifindex,
 			return -1;
 
 		case 0:
-			clean_cb (opaque);
 			close (fd[1]);
 			break;
 
@@ -241,6 +240,7 @@ miredo_privileged_process (unsigned ifindex,
 		run_script ();
 	}
 
+	clean_cb (opaque);
 	exit (0);
 }
 
