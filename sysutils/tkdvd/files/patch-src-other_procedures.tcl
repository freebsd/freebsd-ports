--- src/other_procedures.tcl.orig	2008-08-30 13:43:00.000000000 +0400
+++ src/other_procedures.tcl	2009-02-17 00:56:27.000000000 +0300
@@ -448,7 +448,7 @@
 		button .create_iso_window.f_dest_file.b_mess -highlightbackground blue -text "$i18n_choose_target_file" -command { set dest_file [tk_getSaveFile -filetypes {{ {ISO Image} { .iso } } {{All Files}  * } } -defaultextension .iso] }
 		entry .create_iso_window.f_dest_file.e_fp  -relief flat -highlightbackground blue -highlightcolor blue -readonlybackground #f5f5f5 -state readonly -textvariable dest_file -width 57
 	
-		button .create_iso_window.b_create -highlightbackground red -text "$i18n_create" -command { if { $dest_file == "" } { tk_messageBox -icon error -message $i18n_error_target_file_ns -type ok -title $i18n_error } else {launch "create_iso" "[exec echo $dest_file | sed s/\ /\\\\\ /g -]"; destroy .create_iso_window} }
+		button .create_iso_window.b_create -highlightbackground red -text "$i18n_create" -command { if { $dest_file == "" } { tk_messageBox -icon error -message $i18n_error_target_file_ns -type ok -title $i18n_error } else {launch "create_iso" "[exec echo $dest_file | sed s/\ /\\\\\ /g]"; destroy .create_iso_window} }
 		button .create_iso_window.b_close -highlightbackground red -text "$i18n_close" -command { destroy .create_iso_window}
 	
 		pack .create_iso_window.f_dest_file.b_mess -side left -padx {12 12}
@@ -565,4 +565,4 @@
 		}
 	}
 	return "no"
-}
\ No newline at end of file
+}
