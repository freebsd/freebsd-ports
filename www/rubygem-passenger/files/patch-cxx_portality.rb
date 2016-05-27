--- src/ruby_supportlib/phusion_passenger/platform_info/cxx_portability.rb.orig	2016-05-08 18:50:00.990066000 -0400
+++ src/ruby_supportlib/phusion_passenger/platform_info/cxx_portability.rb	2016-05-08 18:50:33.632523000 -0400
@@ -211,7 +211,7 @@
       end
       result << ' -lrt' if has_rt_library?
       result << ' -lmath' if has_math_library?
-      result << ' -ldl'
+      # result << ' -ldl'
       result.strip!
       return result
     end
