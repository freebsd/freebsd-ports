--- GG/adobe/adam.hpp.orig	2012-01-27 18:29:22.000000000 +0300
+++ GG/adobe/adam.hpp	2012-01-27 18:30:05.000000000 +0300
@@ -528,7 +528,7 @@
     relation_t(name_t n, line_position_t p, array_t e) :
         name_m(n),
         position_m(p),
-        expression_m(move(e))
+        expression_m(::adobe::move(e))
     { }
     
     friend void swap(relation_t& x, relation_t& y)
@@ -541,7 +541,7 @@
     relation_t(move_from<relation_t> x) :
         name_m(x.source.name_m),
         position_m(x.source.position_m),
-        expression_m(move(x.source.expression_m))
+        expression_m(::adobe::move(x.source.expression_m))
     { }
     
     relation_t& operator=(relation_t x) 
