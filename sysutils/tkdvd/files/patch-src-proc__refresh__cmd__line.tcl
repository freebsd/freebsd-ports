--- src/proc_refresh_cmd_line.tcl.orig	2008-03-28 15:15:04.000000000 +0300
+++ src/proc_refresh_cmd_line.tcl	2009-02-15 15:27:07.000000000 +0300
@@ -127,13 +127,13 @@
 				set local_burn_speed ""
 			}
 			if { $dvd_size <= 716800 } {
-				set command_line "$burn_command $option_overburn $local_burn_speed $option_eject_cd  $option_tao_dao_cd dev=$burning_device [exec echo $iso_file | sed s/\ /\\\\\ /g -]"
+				set command_line "$burn_command $option_overburn $local_burn_speed $option_eject_cd  $option_tao_dao_cd dev=$burning_device [exec echo $iso_file | sed s/\ /\\\\\ /g]"
 			} else {
-				set command_line "$burn_command $option_dvd_compat $local_burn_speed $option_overburn $t_session $burning_device=[exec echo $iso_file | sed s/\ /\\\\\ /g -]"
+				set command_line "$burn_command $option_dvd_compat $local_burn_speed $option_overburn $t_session $burning_device=[exec echo $iso_file | sed s/\ /\\\\\ /g]"
 			}
 			if { [.f_burn.go_button cget -state] == "disabled" } { .f_burn.go_button configure -state normal }
 		}
 	} else { set command_line "growisofs/cdrecord is currently working" }
 	if {($t_session == "-M" && $space_left_f != "N/A") || ($t_session == "-use-the-force-luke=tty -Z" && $space_left_f == "N/A") } { refresh_total_file_size }
 	return 1
-}
\ No newline at end of file
+}
