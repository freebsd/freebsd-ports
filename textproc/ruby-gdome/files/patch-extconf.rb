--- extconf.rb.orig	Fri Jul 13 08:20:23 2001
+++ extconf.rb	Fri Jan 24 04:32:03 2003
@@ -1,11 +1,11 @@
 require "mkmf"
 
-$CFLAGS  += `gdome-config --cflags`.gsub("\n"," ")
+$CFLAGS << ' ' << `gdome-config --cflags`.gsub("\n"," ")
 if ($? == 0)
-  $LDFLAGS += `gdome-config --libs`.gsub("\n"," ")
+  $LDFLAGS << ' ' << `gdome-config --libs`.gsub("\n"," ")
   if ($? == 0)
     load "code_creation/parse_idl.rb"
-    $LOCAL_LIBS += $LDFLAGS
+    $LOCAL_LIBS << ' ' << $LDFLAGS
     create_makefile('gdome')
   end
 end
