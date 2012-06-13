--- lib/rabbit/element/container-element.rb.orig	2012-05-29 22:51:14.000000000 +0900
+++ lib/rabbit/element/container-element.rb	2012-06-14 07:05:17.000000000 +0900
@@ -119,18 +119,22 @@
         prev_is_inline = false
         @elements.each do |element|
           element.compile(canvas, x, y, w, h)
-          compile_horizontal(canvas, x, y, w, h)
+          compile_horizontal_element(element, canvas, x, y, w, h)
           x, y, w, h = element.draw(true)
         end
       end
 
       def compile_horizontal(canvas, x, y, w, h)
         @elements.each do |element|
-          if do_horizontal_centering? or element.do_horizontal_centering?
-            element.do_horizontal_centering(canvas, x, y, w, h)
-          else
-            element.reset_horizontal_centering(canvas, x, y, w, h)
-          end
+          compile_horizontal_element(element, canvas, x, y, w, h)
+        end
+      end
+
+      def compile_horizontal_element(element, canvas, x, y, w, h)
+        if do_horizontal_centering? or element.do_horizontal_centering?
+          element.do_horizontal_centering(canvas, x, y, w, h)
+        else
+          element.reset_horizontal_centering(canvas, x, y, w, h)
         end
       end
 
