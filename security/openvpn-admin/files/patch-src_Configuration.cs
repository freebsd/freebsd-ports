--- src/Configuration.cs.orig	Tue Nov 22 01:46:04 2005
+++ src/Configuration.cs	Sun Feb 26 15:09:48 2006
@@ -459,8 +459,8 @@
 			int pid = Int32.Parse(Configuration.GetFileContents(pidfile, true));
 			
 			// Only for Mono after 1.9.1 releases.
-			//Mono.Unix.Native.Syscall.kill(pid, Mono.Unix.Native.Signum.SIGKILL);
-			Mono.Unix.Syscall.kill(pid, Mono.Unix.Signum.SIGKILL);
+			Mono.Unix.Native.Syscall.kill(pid, Mono.Unix.Native.Signum.SIGKILL);
+			//Mono.Unix.Syscall.kill(pid, Mono.Unix.Signum.SIGKILL);
 
 			File.Delete(pidfile);
 			File.Delete(stafile);
