--- lib/rabbit/parser/ext/coderay.rb.orig	2011-07-16 05:59:37.000000000 +0900
+++ lib/rabbit/parser/ext/coderay.rb	2012-02-05 11:24:16.000000000 +0900
@@ -21,7 +21,7 @@
           def setup(options)
             super
             @out = SyntaxHighlightingBlock.new
-            @elements = [@out]
+            @containers = [@out]
           end
 
           def text_token(text, type=:plain)
@@ -29,36 +29,39 @@
             escaped_text = Escape.escape_meta_character(text)
             text_element = SyntaxHighlightingText.new(Text.new(escaped_text))
             tag_name = type.to_s.gsub(/_/, '-')
-            CustomTag.new("syntax-#{tag_name}", text_element)
+            tag = CustomTag.new("syntax-#{tag_name}", text_element)
+            current_container << tag
           end
 
-          def open_token(kind)
-            p [:open, kind] if Utils.syntax_highlighting_debug?
-            @out = TextContainer.new
-            @elements << @out
-            CustomTag.new("syntax-#{kind}")
+          def begin_group(kind)
+            p [:begin_group, kind] if Utils.syntax_highlighting_debug?
+            @containers << TextContainer.new
+            tag = CustomTag.new("syntax-#{kind}")
+            current_container << tag
           end
 
           def begin_line(kind)
             p [:begin_line, kind] if Utils.syntax_highlighting_debug?
-            nil
           end
 
           def end_line(kind)
             p [:end_line, kind] if Utils.syntax_highlighting_debug?
-            nil
           end
 
-          def close_token(kind)
-            p [:close, kind] if Utils.syntax_highlighting_debug?
-            block = @elements.pop
-            @out = @elements.last
-            block
+          def end_group(kind)
+            p [:end_group, kind] if Utils.syntax_highlighting_debug?
+            block = @containers.pop
+            current_container << block
           end
 
           def finish(options)
             super
           end
+
+          private
+          def current_container
+            @containers.last
+          end
         end
       end
     end
