--- ext/extconf.rb.orig	Mon Dec  6 01:16:04 2004
+++ ext/extconf.rb	Sun Dec 26 03:26:56 2004
@@ -2,13 +2,13 @@
 
 def gsl_config()
   print("checking gsl cflags... ")
-  IO.popen("sh gsl-config --cflags") do |f|
+  IO.popen("gsl-config --cflags") do |f|
     cflags = f.gets.chomp
     puts(cflags)
     $CFLAGS += " -Wall " + cflags
   end
    
-  IO.popen("sh gsl-config --libs") do |f|
+  IO.popen("gsl-config --libs") do |f|
     libs = f.gets.chomp
     dir_config("cblas")
     dir_config("atlas")
@@ -29,7 +29,7 @@
 def check_version(configfile)
   
   print("checking gsl version... ")
-  IO.popen("sh gsl-config --version") do |f|
+  IO.popen("gsl-config --version") do |f|
     ver = f.gets.chomp
     puts(ver)
     configfile.printf("#ifndef GSL_VERSION\n#define GSL_VERSION \"#{ver}\"\n#endif\n")
