--- philesight.rb.orig	2009-01-05 18:16:40.000000000 +0300
+++ philesight.rb	2009-02-11 22:38:03.000000000 +0300
@@ -5,6 +5,8 @@
 require 'cgi'
 require 'cairo'
 require 'bdb'
+require 'locale'
+require 'iconv'
 
 class PNGWriter
 
@@ -390,6 +392,7 @@
 	#
 
 	def draw_text(cr, x, y, text, size=11, bold=false)
+		conv = Iconv.new("UTF-8", Locale.charset)
 
 		lines = text.count("\n") + 1
 		y -= (lines-1) * (size+2) / 2.0
@@ -398,11 +401,18 @@
 		cr.set_font_size(size)
 
 		text.split("\n").each do |line|
-			extents = cr.text_extents(line)
+			begin
+				newname = conv.iconv(line)
+				newname << conv.iconv(nil)
+			rescue Iconv::IllegalSequence => e
+				puts "Bad file name: #{line}"
+				next
+			end
+			extents = cr.text_extents(newname)
 			w = extents.width
 			h = extents.height
 			cr.move_to(x - w/2, y + h/2)
-			cr.show_text(line)
+			cr.show_text(newname)
 			y += size+2
 		end
 	end
