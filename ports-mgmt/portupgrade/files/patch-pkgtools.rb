Index: lib/pkgtools.rb
===================================================================
RCS file: /home/cvs/pkgtools/lib/pkgtools.rb,v
retrieving revision 1.123
diff -u -r1.123 pkgtools.rb
--- lib/pkgtools.rb	30 Jun 2004 16:24:12 -0000	1.123
+++ lib/pkgtools.rb	2 Jul 2004 03:51:12 -0000
@@ -82,7 +82,7 @@
     if !pattern.include?('/')
       gtable[pattern] = value
     end
-  end
+  end if hash
 
   table = [otable, gtable]
 end
