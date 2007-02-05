--- lib/portsdb.rb.orig	Sat Nov 11 22:59:24 2006
+++ lib/portsdb.rb	Mon Feb  5 10:15:00 2007
@@ -56,7 +56,7 @@
     "vietnamese"	=> "vi-",
   }
 
-  MY_PORT = 'sysutils/portupgrade'
+  MY_PORT = 'ports-mgmt/portupgrade'
 
   LOCK_FILE = '/var/run/portsdb.lock'
 
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
