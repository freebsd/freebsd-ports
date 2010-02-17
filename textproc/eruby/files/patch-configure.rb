--- configure.rb.orig	2010-02-17 16:52:48.000000000 +0100
+++ configure.rb	2010-02-17 16:52:48.000000000 +0100
@@ -317,7 +317,16 @@
 else
   $CFLAGS = CFLAGS + " " + CONFIG["CCDLFLAGS"]
 end
+if not CONFIG["rubyhdrdir"].nil?
+  $CFLAGS << " -I" + CONFIG["rubyhdrdir"] + "/" + $sitearch
+end
+if not ENV["EXTRA_CFLAGS"].nil?
+  $CFLAGS << " " + ENV["EXTRA_CFLAGS"]
+end
 $LDFLAGS = CONFIG["LDFLAGS"]
+if not ENV["EXTRA_LDFLAGS"].nil?
+  $LDFLAGS << " " + ENV["EXTRA_LDFLAGS"]
+end
 if $LDFLAGS.to_s.empty? && /mswin32/ =~ RUBY_PLATFORM
   $LDFLAGS = "-link -incremental:no -pdb:none"
 end
@@ -435,7 +444,7 @@
 AC_MSG_CHECKING("whether we are using gcc")
 if $CC == "gcc" || `#{$CC} -v 2>&1` =~ /gcc/
   $using_gcc = true
-  $CFLAGS += " -Wall"
+  $CFLAGS += " -Wall -g"
 else
   $using_gcc = false
 end
