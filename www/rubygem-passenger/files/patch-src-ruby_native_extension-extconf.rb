--- src/ruby_native_extension/extconf.rb.orig	2020-06-05 11:51:04.865937000 -0400
+++ src/ruby_native_extension/extconf.rb	2020-06-05 13:22:43.694831000 -0400
@@ -70,6 +70,12 @@
 		File.open("Makefile", "w") do |f|
 			f.write(makefile)
 		end
+	elsif RUBY_PLATFORM =~ /freebsd/
+		makefile = File.read("Makefile")
+		makefile.sub!(/-Wl,--compress-debug-sections=zlib/, "")
+		File.open("Makefile", "w") do |f|
+			f.write(makefile)
+		end
 	end
 end
 
