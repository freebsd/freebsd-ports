--- tcl/ui-resource.tcl.org	Mon May  7 16:17:03 2001
+++ tcl/ui-resource.tcl	Mon May  7 16:17:29 2001
@@ -153,7 +153,7 @@
 	option add Vic.infoHighlightColor LightYellow2 startupFile
 	option add Vic.useJPEGforH261 false startupFile
 	option add Vic.useHardwareComp false startupFile
-	option add Vic.stillGrabber false startupFile
+	option add Vic.stillGrabber true startupFile ; # XXX was false
 	option add Vic.siteDropTime "300" startupFile
 	option add Vic.quality "0" startupFile
 
