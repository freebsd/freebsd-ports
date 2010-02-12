--- vapi/glib-2.0.vapi.orig	2009-11-23 01:21:30.000000000 +0500
+++ vapi/glib-2.0.vapi	2009-12-03 14:12:42.840631369 +0500
@@ -2452,6 +2452,8 @@
 		public static FileStream? open (string path, string mode);
 		[CCode (cname = "fdopen")]
 		public static FileStream? fdopen (int fildes, string mode);
+		[CCode (cname = "freopen", instance_pos = -1)]
+		public void reopen (string path, string mode);
 		[CCode (cname = "fprintf")]
 		[PrintfFormat ()]
 		public void printf (string format, ...);
