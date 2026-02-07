--- Utility/AsyncTask.vala.orig	2018-08-12 04:41:58 UTC
+++ Utility/AsyncTask.vala
@@ -87,7 +87,7 @@ public abstract class AsyncTask : GLib.Object{
 	public signal void stderr_line_read(string line);
 	public signal void task_complete();
 
-	public AsyncTask(){
+	protected AsyncTask(){
 		init_temp_directories();
 	}
 
