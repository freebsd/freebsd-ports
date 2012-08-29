--- lenses/sysctl.aug.orig	2012-08-19 01:11:41.000000000 +0000
+++ lenses/sysctl.aug	2012-08-19 01:11:57.000000000 +0000
@@ -6,7 +6,7 @@
   let eol = Util.eol
   let indent = Util.indent
   let key_re = /[A-Za-z0-9_.-]+/
-  let eq = del /[ \t]*=[ \t]*/ " = "
+  let eq = del /[ \t]*=[ \t]*/ "="
   let value_re = /[^ \t\n](.*[^ \t\n])?/
 
   let comment = [ indent . label "#comment" . del /[#;][ \t]*/ "# "
