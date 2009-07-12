--- configure.rb.orig	2003-02-10 04:18:10.000000000 +0100
+++ configure.rb	2009-07-12 16:05:45.000000000 +0200
@@ -59,7 +59,7 @@
   end
 end
 
-require 'ftools'
+require 'fileutils'
 
 def AC_OUTPUT(*files)
   if $AC_LIST_HEADER
@@ -71,7 +71,7 @@
   for file in files
     print "creating ", file, "\n"
     open(File.join($srcdir, file + ".in")) do |fin|
-      File.makedirs(File.dirname(file))
+      FileUtils.mkdir_p(File.dirname(file))
       open(file, "w") do |fout|
 	while line = fin.gets
 	  line.gsub!(/@([A-Za-z_]+)@/) do |s|
@@ -301,12 +301,22 @@
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
 $LIBS = CONFIG["LIBS"]
 $XLDFLAGS = CONFIG["XLDFLAGS"]
+$XLDFLAGS="" if $XLDFLAGS.nil?
 $XLDFLAGS.gsub!(/-L\./, "")
 if /mswin32/ !~ RUBY_PLATFORM
   $XLDFLAGS += " -L$(libdir)"
@@ -333,7 +343,7 @@
 $LIBRUBY_A = CONFIG["LIBRUBY_A"]
 $RUBY_SO_NAME = CONFIG["RUBY_SO_NAME"]
 
-case PLATFORM
+case RUBY_PLATFORM
 when /-aix/
   if $RUBY_SHARED
     $LIBRUBYARG = "-Wl,$(libdir)/" + CONFIG["LIBRUBY_SO"]
@@ -407,7 +417,7 @@
 AC_MSG_CHECKING("whether we are using gcc")
 if $CC == "gcc" || `#{$CC} -v 2>&1` =~ /gcc/
   $using_gcc = true
-  $CFLAGS += " -Wall"
+  $CFLAGS += " -Wall -g"
 else
   $using_gcc = false
 end
@@ -431,7 +441,7 @@
 $ENABLE_SHARED = false
 AC_ENABLE("shared") { |enableval|
   if enableval == "yes"
-    if PLATFORM =~ /-mswin32/
+    if RUBY_PLATFORM =~ /-mswin32/
       AC_MSG_ERROR("can't enable shared on mswin32")
     end
     $ENABLE_SHARED = true
@@ -449,7 +459,7 @@
 if $ENABLE_SHARED
   $LIBERUBY = "${LIBERUBY_SO}"
   $LIBERUBYARG = "-L. -leruby"
-  case PLATFORM
+  case RUBY_PLATFORM
   when /-sunos4/
     $LIBERUBY_ALIASES = "liberuby.so.$(MAJOR).$(MINOR) liberuby.so"
   when /-linux/
@@ -457,7 +467,7 @@
     $LIBERUBY_ALIASES = "liberuby.so.$(MAJOR).$(MINOR) liberuby.so"
   when /-(freebsd|netbsd)/
     $LIBERUBY_SO = "liberuby.so.$(MAJOR).$(MINOR)"
-    if PLATFORM =~ /elf/ || PLATFORM =~ /-freebsd[3-9]/
+    if RUBY_PLATFORM =~ /elf/ || RUBY_PLATFORM =~ /-freebsd[3-9]/
       $LIBERUBY_SO = "liberuby.so.$(MAJOR_MINOR)"
       $LIBERUBY_ALIASES = "liberuby.so"
     else
@@ -493,7 +503,7 @@
   end
 end
 
-if PLATFORM =~ /-mswin32/
+if RUBY_PLATFORM =~ /-mswin32/
   $AR = "lib"
   $AROPT = "/out:$@"
   $LIBERUBY_A = "liberuby.lib"
