Index: lib/pkgmisc.rb
===================================================================
RCS file: /cvsroot/portupgrade/pkgtools/lib/pkgmisc.rb,v
retrieving revision 1.2.2.2
diff -u -r1.2.2.2 pkgmisc.rb
--- lib/pkgmisc.rb	24 Feb 2007 12:32:11 -0000	1.2.2.2
+++ lib/pkgmisc.rb	2 Mar 2007 19:59:30 -0000
@@ -93,7 +93,8 @@
 def shelljoin(*args)
   args.collect { |arg|
     if /[*?{}\[\]<>()~&|\\$;\'\`\"\s]/ =~ arg
-      '"' + arg.gsub(/([$\\\"\`])/, "\\\\\\1") + '"'
+      a = '"' + arg.gsub(/([$\\\"\`])/, "\\\\\\1") + '"'
+      a.gsub(/\s/, '" "')
     else
       arg
     end
