--- lib/pkgtools.rb.orig	Sun Jul 23 18:50:49 2006
+++ lib/pkgtools.rb	Sun Jul 23 18:50:59 2006
@@ -486,10 +486,8 @@
 def logged_command(file, args)
   if !file  
     args
-  elsif STDIN.tty?
-    ['/usr/bin/script', '-qa', file, *args]
   else
-    ['/bin/sh', '-c', sprintf('%s >>%s 2>&1', shelljoin(*args), shelljoin(file))]
+    ['/usr/bin/script', '-qa', file, *args]
   end
 end
 
