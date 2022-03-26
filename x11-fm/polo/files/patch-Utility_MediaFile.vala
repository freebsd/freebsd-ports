--- Utility/MediaFile.vala.orig	2018-08-12 04:41:58 UTC
+++ Utility/MediaFile.vala
@@ -634,7 +634,7 @@ public abstract class MediaStream : GLib.Object{
     public string Description = "";
 	public bool IsSelected = true;
 	
-	public MediaStream(MediaStreamType _type){
+	protected MediaStream(MediaStreamType _type){
 		Type = _type;
 	}
 	
