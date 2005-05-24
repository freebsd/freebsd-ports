--- lib/uri.tcl.orig	Mon Jul 26 20:23:34 2004
+++ lib/uri.tcl	Wed May 25 00:05:06 2005
@@ -174,8 +174,8 @@
     global mimeHdr mime
     set fileName $mimeHdr($part,file)
     File_Delete [Env_Tmp]/exmh.[pid].html
-    if [catch {file link -hard $fileName [Env_Tmp]/exmh.[pid].html}] {
-	file copy $fileName [Env_Tmp]/exmh.[pid].html
+    if [catch {exec ln $fileName [Env_Tmp]/exmh.[pid].html}] {
+	exec cp $fileName [Env_Tmp]/exmh.[pid].html
     }
     set fileName [Env_Tmp]/exmh.[pid].html
     Exmh_Status "HTML Load $fileName"
