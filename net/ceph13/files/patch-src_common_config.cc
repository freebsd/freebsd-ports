index 24ac74c6db..dd66e3b2d2 100644
--- src/common/config.cc
+++ src/common/config.cc
@@ -1473,13 +1473,13 @@ class assign_visitor : public boost::static_visitor<>
   {
     using T = uint64_t;
     auto member = const_cast<T*>(&(conf->*(boost::get<const T md_config_t::*>(ptr))));
-    *member = boost::apply_visitor(get_size_visitor<T>{}, val);
+    *member = boost::apply_visitor(get_size_visitor<T>(), val);
   }
   void operator()(int64_t md_config_t::* ptr) const
   {
     using T = int64_t;
     auto member = const_cast<T*>(&(conf->*(boost::get<const T md_config_t::*>(ptr))));
-    *member = boost::apply_visitor(get_size_visitor<T>{}, val);
+    *member = boost::apply_visitor(get_size_visitor<T>(), val);
   }
 };
 } // anonymous namespace

