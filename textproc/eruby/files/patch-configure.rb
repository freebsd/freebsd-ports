--- configure.rb.orig	2009-02-14 00:50:10.000000000 +0300
+++ configure.rb	2009-02-14 00:50:18.000000000 +0300
@@ -307,6 +307,7 @@
 end
 $LIBS = CONFIG["LIBS"]
 $XLDFLAGS = CONFIG["XLDFLAGS"]
+$XLDFLAGS="" if $XLDFLAGS.nil?
 $XLDFLAGS.gsub!(/-L\./, "")
 if /mswin32/ !~ RUBY_PLATFORM
   $XLDFLAGS += " -L$(libdir)"
