--- iso9660.cc.orig	Wed Oct 15 15:42:23 2003
+++ iso9660.cc	Wed Oct 15 15:44:37 2003
@@ -307,7 +307,7 @@
 	return;
     }
     if ((boot_catalog && !boot_image) || (!boot_catalog && boot_image)) {
-	Error ("You must specify a boot image AND
+	Error ("You must specify a boot image AND\n\
 a boot catalog to make a bootable CD.");
 	return;
     }
@@ -375,8 +375,8 @@
     button = -1;
 
     TkToplevel (".mkisofs");
-    TkLabel (".mkisofs.l", "-wraplength 6i -justify left -text {
-I don't know where is ``mkisofs'' and MKISOFS is not set in your environment.
+    TkLabel (".mkisofs.l", "-wraplength 6i -justify left -text {\n\
+I don't know where is ``mkisofs'' and MKISOFS is not set in your environment.\n\
 }");
     ExFileSelectBox2 B = tixExFileSelectBox2 (".mkisofs.sel");
     B.command (fileselect);
@@ -419,8 +419,8 @@
 
     Balloon balloon = tixBalloon (".iso9660.balloon");
     TkFrame (".iso9660.d -border 1 -relief raised");
-    E_out = tixLabelEntry (".iso9660.d.e", "-label {Output file:} -labelside top -options {
-	    entry.width 55
+    E_out = tixLabelEntry (".iso9660.d.e", "-label {Output file:} -labelside top -options {\n\
+	    entry.width 55\n\
 	    label.anchor w }");
     Button B = TkButton (".iso9660.d.browse", "-text {Browse...}");
     B.command (browse, "F");
@@ -429,8 +429,8 @@
     TkPack (".iso9660.d", "-side top -fill x -pady 8");
 
     TkFrame (".iso9660.t -border 1 -relief raised");
-    E_tree = tixLabelEntry (".iso9660.t.e", "-label {Path:} -labelside top -options {
-	    entry.width 55
+    E_tree = tixLabelEntry (".iso9660.t.e", "-label {Path:} -labelside top -options {\n\
+	    entry.width 55\n\
 	    label.anchor w }");
     B = TkButton (".iso9660.t.browse", "-text {Browse ...}");
     B.command (browse, "D");
@@ -438,26 +438,26 @@
     TkPack (".iso9660.t.browse -side left -anchor s -padx 4 -pady 1");
     TkPack (".iso9660.t", "-side top -fill x -pady 8");
 
-    E_app = tixLabelEntry (".iso9660.app", "-label {Application ID:} -labelside top -options {
-	    entry.width 55
+    E_app = tixLabelEntry (".iso9660.app", "-label {Application ID:} -labelside top -options {\n\
+	    entry.width 55\n\
 	    label.anchor w }");
     balloon.bind (".iso9660.app -balloonmsg", app_help);
     TkPack (".iso9660.app", "-side top -fill x");
 
-    E_vol = tixLabelEntry (".iso9660.vol", "-label {Volume ID:} -labelside top -options {
-	    entry.width 55
+    E_vol = tixLabelEntry (".iso9660.vol", "-label {Volume ID:} -labelside top -options {\n\
+	    entry.width 55\n\
 	    label.anchor w }");
     balloon.bind (".iso9660.vol -balloonmsg", vol_help);
     TkPack (".iso9660.vol", "-side top -fill x");
 
-    E_prep = tixLabelEntry (".iso9660.prep", "-label {Preparer:} -labelside top -options {
-	    entry.width 55
+    E_prep = tixLabelEntry (".iso9660.prep", "-label {Preparer:} -labelside top -options {\n\
+	    entry.width 55\n\
 	    label.anchor w }");
     balloon.bind (".iso9660.prep -balloonmsg", prep_help);
     TkPack (".iso9660.prep", "-side top -fill x");
 
-    E_pub = tixLabelEntry (".iso9660.pub", "-label {Publisher:} -labelside top -options {
-	    entry.width 55
+    E_pub = tixLabelEntry (".iso9660.pub", "-label {Publisher:} -labelside top -options {\n\
+	    entry.width 55\n\
 	    label.anchor w }");
     balloon.bind (".iso9660.pub -balloonmsg", pub_help);
     TkPack (".iso9660.pub", "-side top -fill x");
@@ -468,15 +468,15 @@
     balloon.bind (".iso9660.excl -balloonmsg", x_help);
     TkPack (".iso9660.excl", "-side top -fill x");
 
-    E_excl = tixLabelEntry (".iso9660.glob", "-label {Exclude patterns:} -labelside top -options {
-	    entry.width 55
+    E_excl = tixLabelEntry (".iso9660.glob", "-label {Exclude patterns:} -labelside top -options {\n\
+	    entry.width 55\n\
 	    label.anchor w }");
     balloon.bind (".iso9660.glob -balloonmsg", m_help);
     TkPack (".iso9660.glob", "-side top -fill x");
 
     TkFrame (".iso9660.bopt -border 1 -relief raised");
-    E_BootImage = tixLabelEntry (".iso9660.bopt.e", "-label {Boot image:} -labelside top -options {
-	    entry.width 55
+    E_BootImage = tixLabelEntry (".iso9660.bopt.e", "-label {Boot image:} -labelside top -options {\n\
+	    entry.width 55\n\
 	    label.anchor w }");
     B = TkButton (".iso9660.bopt.browse", "-text {Browse ...}");
     B.command (browse, "I");
@@ -486,8 +486,8 @@
     balloon.bind (".iso9660.bopt.e -balloonmsg", b_help);
 
     TkFrame (".iso9660.c -border 1 -relief raised");
-    E_BootCatalog = tixLabelEntry (".iso9660.c.e", "-label {Boot catalog:} -labelside top -options {
-	    entry.width 55
+    E_BootCatalog = tixLabelEntry (".iso9660.c.e", "-label {Boot catalog:} -labelside top -options {\n\
+	    entry.width 55\n\
 	    label.anchor w }");
     B = TkButton (".iso9660.c.browse", "-text {Browse ...}");
     B.command (browse, "C");
