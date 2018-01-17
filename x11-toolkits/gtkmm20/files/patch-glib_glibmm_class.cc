class.cc:40:5: error: non-constant-expression cannot be narrowed from type 'guint'
      (aka 'unsigned int') to 'guint16' (aka 'unsigned short') in initializer list
      [-Wc++11-narrowing]
    base_query.class_size,
    ^~~~~~~~~~~~~~~~~~~~~
class.cc:40:5: note: insert an explicit cast to silence this issue
    base_query.class_size,
    ^~~~~~~~~~~~~~~~~~~~~
    static_cast<guint16>()
class.cc:46:5: error: non-constant-expression cannot be narrowed from type 'guint'
      (aka 'unsigned int') to 'guint16' (aka 'unsigned short') in initializer list
      [-Wc++11-narrowing]
    base_query.instance_size,
    ^~~~~~~~~~~~~~~~~~~~~~~~
class.cc:46:5: note: insert an explicit cast to silence this issue
    base_query.instance_size,
    ^~~~~~~~~~~~~~~~~~~~~~~~
    static_cast<guint16>(   )
class.cc:78:7: error: non-constant-expression cannot be narrowed from type 'guint'
      (aka 'unsigned int') to 'guint16' (aka 'unsigned short') in initializer list
      [-Wc++11-narrowing]
      base_query.class_size,
      ^~~~~~~~~~~~~~~~~~~~~
class.cc:78:7: note: insert an explicit cast to silence this issue
      base_query.class_size,
      ^~~~~~~~~~~~~~~~~~~~~
      static_cast<guint16>()
class.cc:84:7: error: non-constant-expression cannot be narrowed from type 'guint'
      (aka 'unsigned int') to 'guint16' (aka 'unsigned short') in initializer list
      [-Wc++11-narrowing]
      base_query.instance_size,
      ^~~~~~~~~~~~~~~~~~~~~~~~
class.cc:84:7: note: insert an explicit cast to silence this issue
      base_query.instance_size,
      ^~~~~~~~~~~~~~~~~~~~~~~~
      static_cast<guint16>(   )

https://git.gnome.org/browse/glibmm/commit/?id=926909ed02a2

--- glib/glibmm/class.cc.orig	2002-10-11 18:05:43 UTC
+++ glib/glibmm/class.cc
@@ -35,15 +35,23 @@ void Class::register_derived_type(GType base_type)
   GTypeQuery base_query = { 0, 0, 0, 0, };
   g_type_query(base_type, &base_query);
 
+  //GTypeQuery::class_size is guint but GTypeInfo::class_size is guint16.
+  const guint16 class_size =
+   (guint16)base_query.class_size;
+
+  //GTypeQuery::instance_size is guint but GTypeInfo::instance_size is guint16.
+  const guint16 instance_size =
+   (guint16)base_query.instance_size;
+ 
   const GTypeInfo derived_info =
   {
-    base_query.class_size,
+    class_size,
     0, // base_init
     0, // base_finalize
     class_init_func_,
     0, // class_finalize
     0, // class_data
-    base_query.instance_size,
+    instance_size,
     0, // n_preallocs
     0, // instance_init
     0, // value_table
@@ -73,15 +81,23 @@ GType Class::clone_custom_type(const char* custom_type
     GTypeQuery base_query = { 0, 0, 0, 0, };
     g_type_query(base_type, &base_query);
 
+    //GTypeQuery::class_size is guint but GTypeInfo::class_size is guint16.
+    const guint16 class_size =
+      (guint16)base_query.class_size;
+
+    //GTypeQuery::instance_size is guint but GTypeInfo::instance_size is guint16.
+    const guint16 instance_size =
+      (guint16)base_query.instance_size;
+
     const GTypeInfo derived_info =
     {
-      base_query.class_size,
+      class_size,
       0, // base_init
       0, // base_finalize
       &Class::custom_class_init_function,
       0, // class_finalize
       this, // class_data
-      base_query.instance_size,
+      instance_size,
       0, // n_preallocs
       0, // instance_init
       0, // value_table
