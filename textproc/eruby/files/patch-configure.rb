--- configure.rb.orig	2013-11-16 10:18:41.000000000 +0100
+++ configure.rb	2013-11-16 10:27:26.000000000 +0100
@@ -210,6 +210,7 @@
 
 $stdout.sync = true
 
+# include RbConfig ?
 drive = File::PATH_SEPARATOR == ';' ? /\A\w:/ : /\A/
 prefix = Regexp.new("\\A" + Regexp.quote(CONFIG["prefix"]))
 $drive = CONFIG["prefix"] =~ drive ? $& : ''
@@ -293,14 +294,14 @@
 
 $arch = CONFIG["arch"]
 $sitearch = CONFIG["sitearch"]
-$ruby_version = Config::CONFIG["ruby_version"] ||
+$ruby_version = CONFIG["ruby_version"] ||
   CONFIG["MAJOR"] + "." + CONFIG["MINOR"]
 
 $CC = CONFIG["CC"]
 $AR = CONFIG["AR"]
 $LD = "$(CC)"
 $RANLIB = CONFIG["RANLIB"]
-$ruby = arg_config("--ruby", File.join(Config::CONFIG["bindir"], CONFIG["ruby_install_name"]))
+$ruby = arg_config("--ruby", File.join(CONFIG["bindir"], CONFIG["ruby_install_name"]))
 $RUBY = ($nmake && !$configure_args.has_key?('--ruby')) ? $ruby.gsub(%r'/', '\\') : $ruby
 if RUBY_VERSION < "1.8.0"
   $RM = 'rm -f'
@@ -317,7 +318,16 @@
 else
   $CFLAGS = CFLAGS + " " + CONFIG["CCDLFLAGS"]
 end
+if not CONFIG["rubyhdrdir"].nil?
+  $CFLAGS << " -I" + RbConfig::CONFIG["rubyhdrdir"] + "/" + $sitearch
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
@@ -435,7 +445,7 @@
 AC_MSG_CHECKING("whether we are using gcc")
 if $CC == "gcc" || `#{$CC} -v 2>&1` =~ /gcc/
   $using_gcc = true
-  $CFLAGS += " -Wall"
+  $CFLAGS += " -Wall -g"
 else
   $using_gcc = false
 end
