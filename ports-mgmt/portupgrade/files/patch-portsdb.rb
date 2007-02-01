--- lib/portsdb.rb.orig	Thu Feb  1 10:15:59 2007
+++ lib/portsdb.rb	Thu Feb  1 10:17:25 2007
@@ -387,8 +387,8 @@
   end
 
   def subdirs(dir)
-    %x"fgrep -v bsd.port.subdir.mk #{dir}/Makefile |
-       make -f - -V SUBDIR 2> /dev/null".split.select { |i|
+    %x"fgrep SUBDIR #{dir}/Makefile | sed -e 's/SUBDIR +=//'
+    	2> /dev/null".split.select { |i|
       File.directory?(File.join(dir, i))
     }.sort
   end
