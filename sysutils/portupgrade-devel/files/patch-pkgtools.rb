Index: lib/pkgtools.rb
===================================================================
RCS file: /home/cvs/pkgtools/lib/pkgtools.rb,v
retrieving revision 1.116
diff -u -r1.116 pkgtools.rb
--- lib/pkgtools.rb	19 Oct 2003 11:56:34 -0000	1.116
+++ lib/pkgtools.rb	16 Jan 2004 12:11:11 -0000
@@ -478,14 +478,20 @@
 alias system! sudo
 alias xsystem! xsudo
 
-# script, xscript
-def __script(x, file, *args)
-  if file
-    __system(x, '/usr/bin/script', '-qa', file, *args)
+def logged_command(file, args)
+  if !file  
+    args
+  elsif STDIN.tty?
+    ['/usr/bin/script', '-qa', file, *args]
   else
-    __system(x, *args)
+    ['/bin/sh', '-c', sprintf('%s >>%s 2>&1', shelljoin(*args), shelljoin(file))]
   end
 end
+
+# script, xscript
+def __script(x, file, *args)
+  __system(x, *logged_command(file, args))
+end
 def script(file, *args)
   __script(false, file, *args)
 end
@@ -495,11 +501,7 @@
 
 # script!, xscript!
 def __script!(x, file, *args)
-  if file
-    __sudo(x, '/usr/bin/script', '-qa', file, *args)
-  else
-    __sudo(x, *args)
-  end
+  __sudo(x, *logged_command(file, args))
 end
 def script!(file, *args)
   __script!(false, file, *args)
