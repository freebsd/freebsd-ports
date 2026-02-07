--- unix/tools/bldmanhelp.tcl	2004-12-02 15:33:05.000000000 -0500
+++ unix/tools/bldmanhelp.tcl	2009-11-28 16:41:13.000000000 -0500
@@ -11,10 +11,9 @@
 #
 # The command line is:
 #
-#   bldmanhelp docdir maninfo helpdir
+#   bldmanhelp maninfo helpdir
 #
 # Where:
-#    o docdir is the directory containing the manual pages.
 #    o maninfo is the path to a file that when sources returns a list of
 #      entries describing manual pages to convert.  Each entry is a list
 #      of manual file and the path of the help file to generate.
@@ -68,18 +67,41 @@
 
 proc CopyManPage {manPage outFH} {
     global skipSection
+    global tcl_version
 
-    set stat [catch {
-        open $manPage
-    } fh]
+    set section [lindex [split $manPage .] end]
+    if {$section == "macros"} {
+      return
+    }
+    set manPage [file rootname $manPage]
+    if {[catch {exec man -w $section $manPage} page] &&
+	[catch {exec man -w $section $manPage$tcl_version} page]} {
+        global gotErrors
+        set gotErrors 1
+	puts stderr "can't find man-page for \"$manPage\": $page"
+	return
+    }
+    set manPage [split $page ":)"]
+    if {[llength $manPage] > 1} { # Get the source, not from cat
+	set manPage [string trim [lindex $manPage 1]]
+    }
+    
+    if {[string match *.gz $manPage]} {
+	set stat [catch {open "|gzip -d -c $manPage"} fh]
+    } elseif {[string match *.bz2 $manPage]} {
+	set stat [catch {open "|bzip2 -d -c $manPage"} fh]
+    } else {
+	set stat [catch {open $manPage} fh]
+    }
     if {$stat != 0} {
         global gotErrors
         set gotErrors 1
-        puts stderr "can't open \"$manPage\" $fh"
+        puts stderr "can't open \"$manPage\" $fh. (cwd is [pwd])"
         return
     }
     while {[gets $fh line] >= 0} {
         switch -glob -- $line {
+	    {.so man.macros} {}
             .so* {
                 CopyManPage [lindex $line 1] $outFH
             }
@@ -119,11 +141,10 @@
 # for input to buildhelp.
 #
 
-proc GenInputFile {docDir manInfoTbl tmpFile} {
+proc GenInputFile {manInfoTbl tmpFile} {
 
    set tmpFH [open $tmpFile w]
    set cwd [pwd]
-   cd $docDir
 
    foreach ent $manInfoTbl {
        puts stdout "    preprocessing $ent"
@@ -144,13 +165,12 @@
 
 set tmpFile "bldmanhelp.tmp"
 
-set docDir [lindex $argv 0]
 set manInfoTbl [source [lindex $argv 1]]
 set helpDir [lindex $argv 2]
 set brief [lindex $argv 3]
 
 puts stdout "Begin preprocessing UCB manual files"
-GenInputFile $docDir $manInfoTbl $tmpFile
+GenInputFile $manInfoTbl $tmpFile
 
 buildhelp $helpDir $brief [list $tmpFile]
 
