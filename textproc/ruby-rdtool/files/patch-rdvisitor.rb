--- rd/rdvisitor.rb.orig	Tue May 22 02:37:12 2001
+++ rd/rdvisitor.rb	Thu Jun  7 12:37:19 2001
@@ -193,7 +193,7 @@
       indexes = []
       tree.each do |i|
 	if i.is_a?(MethodListItem)
-	  klass, kind, method, args = analize_method(i.term)
+	  klass, kind, method, args = analize_method(i.term.content)
 	  indexes.push([klass, kind2num(kind), method, kind]) if kind
 	end
       end
