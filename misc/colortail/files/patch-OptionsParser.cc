--- OptionsParser.cc.orig	Thu Aug  5 01:23:39 1999
+++ OptionsParser.cc	Tue Jan 28 13:11:52 2003
@@ -136,6 +136,8 @@
 	       {
 		  if (optarg[pos] == ',')
 		  {
+		     filename.put('\0');
+
 		     // found seperator
 		     // set filename in options class
 		     o->cfg_filenames[o->nr_cfg_files] = filename.str();
@@ -152,6 +154,8 @@
 
 		  if (optarg[pos] == '\0')
 		  {
+		     filename.put('\0');
+
 		     // found end of string
 		     // set filename in options class
 		     o->cfg_filenames[o->nr_cfg_files] = filename.str();
