- fix Ruby incompatibilities with File.exists? and Dir.exists?

--- tools/xmlschema.rb.orig	2025-12-05 10:37:39.966228000 -0800
+++ tools/xmlschema.rb	2025-12-05 10:37:39.966839000 -0800
@@ -265,7 +265,7 @@
 if infile.nil?
   puts "Missing option -i."
   exit
-elsif !File.exists?(infile)
+elsif !File.exist?(infile)
   puts "Input file[#{infile}] does not exist\n"
   exit
 end
@@ -273,7 +273,7 @@
 if $path.nil?
   puts "Missing option -s."
   exit
-elsif !Dir.exists?($path)
+elsif !Dir.exist?($path)
   puts "SDF source dir[#{$path}] does not exist\n"
   exit
 end
@@ -281,7 +281,7 @@
 if outdir.nil?
   puts "Missing output directory, option -o."
   exit
-elsif !Dir.exists?(outdir)
+elsif !Dir.exist?(outdir)
   Dir.mkdir(outdir)
 end
 
