Index: lib/mh.tcl
===================================================================
RCS file: /cvsroot/exmh/exmh/lib/mh.tcl,v
retrieving revision 1.17
retrieving revision 1.19
diff -u -r1.17 -r1.19
--- lib/mh.tcl	2001/07/09 16:45:33	1.17
+++ lib/mh.tcl	2001/11/21 06:32:08	1.19
@@ -765,6 +765,13 @@
     while {![eof $input]} {
 	set numBytes [gets $input line]
 	if {$numBytes > 0} {
+	    if {[regexp {^\s+(.*)$} $line foo other]} {
+		 # handle continued lines
+		 if {[info exists key]} {
+		     append mhProfile($key) " [string trim $other]"
+		 }
+		 continue
+	    }
 	    set parts [split $line :]
 	    set key [string tolower [lindex $parts 0]]
 	    set other [lindex $parts 1]
@@ -772,6 +779,7 @@
 	    set mhProfile($key) $value
 	}
     }
+    close $input
     if {![info exists mhProfile(path)]} {
 	if {[info exists mhProfile(FAIL)]} {
 	    puts stderr "No Path entry in your [file tail $mhProfile(profile)] file."
