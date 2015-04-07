--- extconf.rb.orig	2015-02-16 19:09:00.954071000 +0000
+++ extconf.rb	2015-02-16 19:10:17.025178000 +0000
@@ -1,14 +1,30 @@
-require "rubygems" unless defined?(Gem)
 require "mkmf"
+require "rubygems" unless defined?(Gem)
 
-hoge = Gem::GemPathSearcher.new.find("narray")
-narray_fullname = hoge.full_name
-narray_installpath = hoge.installation_path
-narray_include = "#{narray_installpath}/gems/#{narray_fullname}/"
-narray_lib = "#{narray_installpath}/gems/#{narray_fullname}/"
+ar = ARGV.grep( /^--with-netcdf-version=/ )
+if ar.length > 0
+  ncversion = ar[0].sub(/^--with-netcdf-version=/,"")
+else
+  ncversion = nil
+end
 
-dir_config('narray',narray_include,narray_lib)
-dir_config('netcdf','/usr/local')
+if Gem.respond_to?(:find_files)
+  require "rbconfig"
+  so = RbConfig::CONFIG["DLEXT"]
+  narray_include = File.expand_path(File.dirname(Gem.find_files("narray.h")[0]))
+  narray_lib = File.expand_path(File.dirname(Gem.find_files("narray." + so)[0]))
+else
+  gem_home=(`gem environment GEM_HOME`).chomp
+  narray_dir = Dir.glob("#{gem_home}/gems/narray-*").sort[-1]
+  if narray_dir
+    narray_include = narray_lib = narray_dir
+  else
+    narray_include = narray_lib = [ $sitearchdir, $vendorarchdir]
+  end
+end
+dir_config('narray', narray_include, narray_lib)
+
+dir_config('netcdf', '/usr/local')
 
 if ( ! ( have_header("narray.h") && have_header("narray_config.h") ) ) then
 print <<EOS
@@ -22,66 +38,26 @@
    exit(-1)
 end
 
-if xsystem("ncdap-config --libs")
-  libncdods = "nc-dap"
-  cflags = `ncdap-config --cflags`.gsub(/\n/, " ")
-  libs = `ncdap-config --libs`.gsub(/\n/, " ")
-  prefix_dods = `ncdap-config --prefix`.gsub(/\n/, "")
-elsif xsystem("opendap-config --libs")
-  libncdods = "nc-dods"
-  cflags = `opendap-config --cflags`.gsub(/\n/, " ")
-  libs = `opendap-config --libs-nc`.gsub(/\n/, " ")
-  prefix_dods = `opendap-config --prefix`.gsub(/\n/, "")
-end
-
-if File.directory?("/usr/include/netcdf")  #-- for Vine linux
-  cflags = "-I/usr/include/netcdf"
-  libs = "-L/usr/lib"
-  $CFLAGS += ' ' + cflags
-  $LOCAL_LIBS += ' ' + libs
-end
- 
-if (enable_config('opendap',true) && ( xsystem("opendap-config --libs") ||
-                                       xsystem("ncdap-config --libs") ) )
-
-  dir_config(libncdods,prefix_dods)
-
-  if (!have_library(libncdods))
-    print <<-EOS
-    ** ERROR ** Library not found: nc-dods (OPeNDAP/DODS-enabled NetCDF lib)
-    Install it, or run extconf.rb with option --disable-opendap.
-                                              ^^^^^^^^^^^^^^^^^
-    EOS
-    exit(-1)
+unless  ncversion 
+  # configure netcdf version
+  if xsystem("nc-config --version")
+    ncversion = `nc-config --version`.chomp!.sub!(/^n.* /i,"") # rm "netCDF "
+    ncversion.sub!(/^([^\.]+\.[^\.]+\.[^\.]+).+$/,'\1') # e.g. 4.2.1.1 -> 4.2.1
   else
-    print <<-EOS
-    ** Message **  Compiling with OPeNDAP/DODS-enabled NetCDF library.
- 
-    This is because the command opendap-config is found in your system.
-    If you want to use the ordinary (non-DODS) version of NetCDF,
-    run extconf.rb with option --disable-opendap.
-                               ^^^^^^^^^^^^^^^^^
-    EOS
+    ncversion = "3.0.0"   # assume version 3 (only for compilation)
+      # For compilation, there is no difference among subversions of netcdf 3
   end
+end
 
-  $CFLAGS += ' '+cflags
-  $LOCAL_LIBS += ' ' + libs
+ncver0 = ncversion[0..0]  # "3" or "4"
+ncver = ncversion.gsub(/\./,'')
+unless /^\d\d\d$/ =~ ncver   # 3 digits
+  raise("Invalid netcdf version: #{ncversion}. Use --with-netcdf-version=") 
+end
+$CFLAGS += ' -DNCVER='+ncver
 
-  # non portable treatments: should be improved (by Horinouchi)
-  CONFIG['LDSHARED'].sub!(/gcc/,'g++')
-  $LIBS.sub!(/-lc\s/,'') ; $LIBS.sub!(/-lc$/,'')
-  print <<-EOS
-    ** Warning **  non-portable treatments are made, 
-    which was sucessfull redhat linux 9:
-     * gcc was replaced with g++ in CONFIG['LDSHARED']
-     * -lc library was removed if in $LIBS 
-
-  EOS
-  #  p '@@@'
-  #  ary = []
-  #  CONFIG.each{|k,v| ary.push([k,v])}
-  #  ary.sort.each{|x| p x}
-else
+case ncver0
+when "4"
   if xsystem("nc-config --libs") # for NetCDF 4
     cflags = `nc-config --cflags`.gsub(/\n/, " ")
     libs = `nc-config --libs`.gsub(/\n/, " ")
@@ -91,23 +67,82 @@
     $CFLAGS += ' ' + cflags
     $LOCAL_LIBS += ' ' + libs
   end
-  if ( ! ( have_header("netcdf.h") && have_library("netcdf") ) )then
-    print <<-EOS
-    ** configure error **  
-       Header netcdf.h or the compiled netcdf library is not found. 
-       If you have the library installed under /netcdfdir (that is, netcdf.h is
-       in /netcdfdir/include and the library in /netcdfdir/lib/),
-       try the following:
+when "3"
+  # for NetCDF 3, which needs external libraries for OpenDAP
+  if xsystem("ncdap-config --libs")
+    libncdods = "nc-dap"
+    cflags = `ncdap-config --cflags`.gsub(/\n/, " ")
+    libs = `ncdap-config --libs`.gsub(/\n/, " ")
+    prefix_dods = `ncdap-config --prefix`.gsub(/\n/, "")
+  elsif xsystem("opendap-config --libs")
+    libncdods = "nc-dods"
+    cflags = `opendap-config --cflags`.gsub(/\n/, " ")
+    libs = `opendap-config --libs-nc`.gsub(/\n/, " ")
+    prefix_dods = `opendap-config --prefix`.gsub(/\n/, "")
+  end
+  if (enable_config('opendap',true) && ( xsystem("opendap-config --libs") ||
+                                         xsystem("ncdap-config --libs") ) )
+
+    dir_config(libncdods,prefix_dods)
 
-       % ruby extconf.rb --with-netcdf-dir=/netcdfdir
+    if (!have_library(libncdods))
+      print <<-EOS
+      ** ERROR ** Library not found: nc-dods (OPeNDAP/DODS-enabled NetCDF lib)
+      Install it, or run extconf.rb with option --disable-opendap.
+                                                ^^^^^^^^^^^^^^^^^
+      EOS
+      exit(-1)
+    else
+      print <<-EOS
+      ** Message **  Compiling with OPeNDAP/DODS-enabled NetCDF library.
+
+      This is because the command opendap-config is found in your system.
+      If you want to use the ordinary (non-DODS) version of NetCDF,
+      run extconf.rb with option --disable-opendap.
+                                 ^^^^^^^^^^^^^^^^^
+      EOS
+    end
+
+    $CFLAGS += ' '+cflags
+    $LOCAL_LIBS += ' ' + libs
+
+    # non portable treatments: should be improved (by Horinouchi)
+    CONFIG['LDSHARED'].sub!(/gcc/,'g++')
+    $LIBS.sub!(/-lc\s/,'') ; $LIBS.sub!(/-lc$/,'')
+    print <<-EOS
+      ** Warning **  non-portable treatments are made, 
+      which was sucessfull redhat linux 9:
+       * gcc was replaced with g++ in CONFIG['LDSHARED']
+       * -lc library was removed if in $LIBS 
 
-       Alternatively, you can specify the two directory separately
-       with --with-netcdf-include and --with-netcdf-lib.
     EOS
-    exit(-1)
+    #  p '@@@'
+    #  ary = []
+    #  CONFIG.each{|k,v| ary.push([k,v])}
+    #  ary.sort.each{|x| p x}
+  else
+    if ( ! ( have_header("netcdf.h") && have_library("netcdf") ) )then
+      print <<-EOS
+      ** configure error **  
+         Header netcdf.h or the compiled netcdf library is not found. 
+         If you have the library installed under /netcdfdir (that is, netcdf.h is
+         in /netcdfdir/include and the library in /netcdfdir/lib/),
+         try the following:
+
+         % ruby extconf.rb --with-netcdf-dir=/netcdfdir
+
+         Alternatively, you can specify the two directory separately
+         with --with-netcdf-include and --with-netcdf-lib.
+      EOS
+      exit(-1)
+    end
   end
+else
+  raise "Netcdf version #{ncver0} is not supported"
 end
 
+
+
 if /cygwin|mingw/ =~ RUBY_PLATFORM
    have_library("narray") || raise("ERROR: narray library is not found")
 end
@@ -128,9 +163,9 @@
       newmkfl.puts("")         
       newmkfl.puts("test: all")            # insert the "test" target
       newmkfl.puts("\t\t@cd test && ruby test.rb && echo 'test did not fail :-p (please ignore the warnings)' && cd ..") 
-   when /lib\/netcdf/
-      line = line.chomp! + "/"
-      newmkfl.puts(line)
+#   when /lib\/netcdf/
+#      line = line.chomp! + "/"
+#      newmkfl.puts(line)
    else
       newmkfl.puts(line)
    end
