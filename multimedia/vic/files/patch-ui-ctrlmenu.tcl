--- tcl/ui-ctrlmenu.tcl.org	Thu May 10 08:44:51 2001
+++ tcl/ui-ctrlmenu.tcl	Thu May 10 08:48:19 2001
@@ -408,16 +408,16 @@
 		-relief raised -command transmit \
 		-anchor w -variable transmitButtonState -font $f \
 		-state disabled -highlightthickness 0
-#	checkbutton $w.freeze -text "Freeze" \
-#		-relief raised -command "grabber freeze \$freeze" \
-#		-anchor w -variable freeze -font $f \
-#		-highlightthickness 0
+	checkbutton $w.freeze -text "Freeze" \
+		-relief raised -command "grabber freeze \$freeze" \
+		-anchor w -variable freeze -font $f \
+		-highlightthickness 0
 	button $w.release -text "Release" \
 		-relief raised -command release_device \
 		-font $f -highlightthickness 0
 
-#	pack $w.send $w.release $w.freeze -fill both
-	pack $w.send $w.release -fill both
+	pack $w.send $w.release $w.freeze -fill both
+#	pack $w.send $w.release -fill both
 }
 
 proc doNothing { args } {
