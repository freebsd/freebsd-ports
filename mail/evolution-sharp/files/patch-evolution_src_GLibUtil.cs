--- evolution/src/GLibUtil.cs.orig	Mon Sep 12 16:49:54 2005
+++ evolution/src/GLibUtil.cs	Mon Oct  3 23:49:21 2005
@@ -10,7 +10,7 @@
 			return ((int)time.Subtract (local_epoch).TotalSeconds);
 		}
 	
-		[DllImport("libglib-2.0.so.0")]
+		[DllImport("libglib-2.0.so")]
 		public static extern int g_slist_length (IntPtr slist);
 		
                 [DllImport("glibsharpglue")]
@@ -19,7 +19,7 @@
 		[DllImport("glibsharpglue")]
 		public static extern  IntPtr gtksharp_slist_get_next (IntPtr slist);
  
-		[DllImport("libglib-2.0.so.0")]
+		[DllImport("libglib-2.0.so")]
 		public static extern void g_slist_free (IntPtr slist);
 
 		public static string[] GLibSListToStringArray (IntPtr slist, bool free_list_mem)
