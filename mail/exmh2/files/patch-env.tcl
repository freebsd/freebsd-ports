Index: lib/env.tcl
===================================================================
RCS file: /cvsroot/exmh/exmh/lib/env.tcl,v
retrieving revision 1.1
retrieving revision 1.3
diff -c -r1.1 -r1.3
*** lib/env.tcl	1998/05/05 17:55:23	1.1
--- lib/env.tcl	2001/01/16 02:07:46	1.3
***************
*** 34,44 ****
      }
  
      # Init TMPDIR
!     if [info exists env(EXMHTMPDIR)] {
  	set env(TMPDIR) $env(EXMHTMPDIR)
      }
!     if {![info exists env(TMPDIR)] || ![file isdirectory $env(TMPDIR)]} {
! 	set env(TMPDIR) /tmp
      }
  
      # Make sure MH is on the path
--- 34,45 ----
      }
  
      # Init TMPDIR
! 
!     if {[info exists env(EXMHTMPDIR)]} {
  	set env(TMPDIR) $env(EXMHTMPDIR)
      }
!     if {![info exists env(TMPDIR)]} {
! 	set env(TMPDIR) /tmp/$env(USER)
      }
  
      # Make sure MH is on the path
***************
*** 58,63 ****
--- 59,80 ----
  
  proc Env_Tmp {} {
      global env
+ 
+     # Doing this every time we use the temp file directory ensures
+     # no-one steals it without the user knowing it.
+ 
+     if {[catch {
+ 	file mkdir $env(TMPDIR)
+ 	if {$env(TMPDIR) != "/tmp"} {
+ 	    file attributes $env(TMPDIR) -permissions 0700
+ 	}
+     } err]} {
+ 	puts $err
+ 	catch {puts stderr "WARNING: exmh using unsafe /tmp directory"}
+ 	Exmh_Status "WARNING: exmh using unsafe /tmp directory" red
+ 	set env(TMPDIR) /tmp
+     }
+ 
      return $env(TMPDIR)
  }
  
