Index: autoconf.rb
===================================================================
RCS file: /src/mod_ruby/autoconf.rb,v
retrieving revision 1.3
diff -u -r1.3 autoconf.rb
--- autoconf.rb	8 Jan 2003 08:10:00 -0000	1.3
+++ autoconf.rb	18 Jan 2003 13:17:10 -0000
@@ -308,6 +308,7 @@
 $VPATH = ""
 
 $arch = CONFIG["arch"]
+$sitearch = CONFIG["sitearch"]
 $ruby_version = Config::CONFIG["ruby_version"] ||
   CONFIG["MAJOR"] + "." + CONFIG["MINOR"]
 
@@ -371,6 +372,7 @@
 AC_SUBST("VPATH")
 
 AC_SUBST("arch")
+AC_SUBST("sitearch")
 AC_SUBST("ruby_version")
 AC_SUBST("drive")
 AC_SUBST("prefix")
Index: configure.rb
===================================================================
RCS file: /src/mod_ruby/configure.rb,v
retrieving revision 1.23
diff -u -r1.23 configure.rb
--- configure.rb	8 Jan 2003 08:10:00 -0000	1.23
+++ configure.rb	18 Jan 2003 13:17:10 -0000
@@ -288,6 +288,7 @@
 $VPATH = ""
 
 $arch = CONFIG["arch"]
+$sitearch = CONFIG["sitearch"]
 $ruby_version = Config::CONFIG["ruby_version"] ||
   CONFIG["MAJOR"] + "." + CONFIG["MINOR"]
 
@@ -351,6 +352,7 @@
 AC_SUBST("VPATH")
 
 AC_SUBST("arch")
+AC_SUBST("sitearch")
 AC_SUBST("ruby_version")
 AC_SUBST("drive")
 AC_SUBST("prefix")
