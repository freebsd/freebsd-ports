Index: lib/preferences.tcl
===================================================================
RCS file: /cvsroot/exmh/exmh/lib/preferences.tcl,v
retrieving revision 1.10
retrieving revision 1.11
diff -u -r1.10 -r1.11
--- lib/preferences.tcl	18 Apr 2000 15:08:17 -0000	1.10
+++ lib/preferences.tcl	20 May 2003 03:22:57 -0000	1.11
@@ -309,6 +309,28 @@
 		set maxWidth $len
 	    }
 	}
+        FontWidget listbox $body.listbox \
+            -exportselection 0 \
+            -selectmode single \
+            -width $maxWidth \
+            -yscrollcommand "$body.scrollbar set"
+
+        scrollbar $body.scrollbar \
+                -command "$body.listbox yview"
+
+        $body.listbox insert end "The Top Ten"
+        foreach x [lsort [concat $pref(panes) Fonts]] {
+            if {$x != "The TopTen"} {
+              $body.listbox insert end $x
+            }
+        }
+        bind $body.listbox <Button-1> {PreferencesListboxHit %W %y}
+
+        pack $body.scrollbar -side right -fill y
+        pack $body.listbox -side left -fill both -expand true
+
+if {0} {
+  # Old Button List
 	Widget_AddBut $body font Fonts Font_Dialog	{top}
 	$body.font configure -width $maxWidth
 	set i 0
@@ -318,8 +340,18 @@
 	    $body.but$i configure -width $maxWidth
 	    incr i
 	}
+}
+
 	wm protocol .pref WM_DELETE_WINDOW PreferencesDelete
     }
+}
+proc PreferencesListboxHit {listbox y} {
+  set id [$listbox get @0,$y]
+  if {$id == "Fonts"} {
+      Font_Dialog
+  } else {
+      PreferencesSectionDialog $id
+  }
 }
 
 proc PreferencesSectionDialog { id } {
