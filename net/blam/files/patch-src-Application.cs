--- src/Application.cs.orig	Sun Apr 15 16:59:40 2007
+++ src/Application.cs	Sun Apr 15 17:00:45 2007
@@ -23,8 +23,7 @@
     public class Application : Program {
 
 	[DllImport("libc")]
-	private static extern int prctl(int option, byte [] arg2, ulong arg3, 
-    	ulong arg4, ulong arg5);
+	private static extern void setproctitle(byte [] fmt, byte [] str_arg);
         
 	public static Application TheApp;
 
@@ -723,11 +722,7 @@
 
 	public static void SetProcessName(string name)
 	{
-	    if(prctl(15 /* PR_SET_NAME */, Encoding.ASCII.GetBytes(name + "\0"), 
-        	0, 0, 0) != 0) {
-        	throw new ApplicationException("Error setting process name: " + 
-        	    Mono.Unix.Native.Stdlib.GetLastError());
-	    }
+		setproctitle(Encoding.ASCII.GetBytes("%s\0"), Encoding.ASCII.GetBytes(name + "\0"));
 	}
 
         public static void Main(string[] args)
