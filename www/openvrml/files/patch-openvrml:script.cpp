$FreeBSD$

--- src/libopenvrml/openvrml/script.cpp.orig	Tue Sep  9 00:56:42 2003
+++ src/libopenvrml/openvrml/script.cpp	Wed Nov 17 10:56:07 2004
@@ -1856,7 +1856,7 @@
 
     case field_value::sfcolor_id:
         {
-            using openvrml::sfcolor
+            using openvrml::sfcolor;
             const sfcolor & c = static_cast<const sfcolor &>(fieldValue);
             if (!SFColor::toJsval(c.value, this->cx, globalObj, &rval)) {
                 rval = JSVAL_NULL;
@@ -3056,7 +3056,7 @@
 
         auto_ptr<openvrml::sfcolor>
             sfcolor(new openvrml::sfcolor(color(rgb[0], rgb[1], rgb[2])));
-        auto_ptr<sfdata> sfdata(new sfdata(sfcolor.get()));
+        auto_ptr<sfdata> sfdata(new sfield::sfdata(sfcolor.get()));
         sfcolor.release();
         if (!JS_SetPrivate(cx, obj, sfdata.get())) { return JS_FALSE; }
         sfdata.release();
@@ -3236,7 +3236,7 @@
         std::auto_ptr<openvrml::sfimage>
                 sfimageClone(static_cast<openvrml::sfimage *>
                     (sfimage.clone().release()));
-        std::auto_ptr<sfdata> sfdata(new sfdata(sfimageClone.get()));
+        std::auto_ptr<sfdata> sfdata(new sfield::sfdata(sfimageClone.get()));
         sfimageClone.release();
         if (!JS_SetPrivate(cx, sfimageObj, sfdata.get())) { return JS_FALSE; }
         sfdata.release();
@@ -3355,7 +3355,7 @@
 
         auto_ptr<openvrml::sfimage>
             sfimage(new openvrml::sfimage(x, y, comp, &pixels[0]));
-        auto_ptr<sfdata> sfdata(new sfdata(sfimage.get()));
+        auto_ptr<sfdata> sfdata(new sfield::sfdata(sfimage.get()));
         sfimage.release();
         if (!JS_SetPrivate(cx, obj, sfdata.get())) { return JS_FALSE; }
         sfdata.release();
@@ -3483,7 +3483,7 @@
         using std::auto_ptr;
 
         auto_ptr<openvrml::sfnode> sfnodeClone(new openvrml::sfnode(node));
-        auto_ptr<sfdata> sfdata(new sfdata(sfnodeClone.get()));
+        auto_ptr<sfdata> sfdata(new sfield::sfdata(sfnodeClone.get()));
         sfnodeClone.release();
         if (!JS_SetPrivate(cx, sfnodeObj, sfdata.get())) { return JS_FALSE; }
         sfdata.release();
@@ -3573,7 +3573,7 @@
     try {
         using std::auto_ptr;
         auto_ptr<openvrml::sfnode> sfnode(new openvrml::sfnode(nodes[0]));
-        auto_ptr<sfdata> sfdata(new sfdata(sfnode.get()));
+        auto_ptr<sfdata> sfdata(new sfield::sfdata(sfnode.get()));
         sfnode.release();
         if (!JS_SetPrivate(cx, obj, sfdata.get())) { return JS_FALSE; }
         sfdata.release();
@@ -3863,7 +3863,7 @@
     try {
         auto_ptr<openvrml::sfrotation>
             sfrotation(new openvrml::sfrotation(rotation(x, y, z, angle)));
-        auto_ptr<sfdata> sfdata(new sfdata(sfrotation.get()));
+        auto_ptr<sfdata> sfdata(new sfield::sfdata(sfrotation.get()));
         sfrotation.release();
         if (!JS_SetPrivate(cx, obj, sfdata.get())) { return JS_FALSE; }
         sfdata.release();
@@ -4325,7 +4325,7 @@
 
         auto_ptr<openvrml::sfvec2f>
             sfvec2f(new openvrml::sfvec2f(vec2f(x, y)));
-        auto_ptr<sfdata> sfdata(new sfdata(sfvec2f.get()));
+        auto_ptr<sfdata> sfdata(new sfield::sfdata(sfvec2f.get()));
         sfvec2f.release();
         if (!JS_SetPrivate(cx, obj, sfdata.get())) { return JS_FALSE; }
         sfdata.release();
@@ -4816,7 +4816,7 @@
 
         auto_ptr<openvrml::sfvec3f>
             sfvec3f(new openvrml::sfvec3f(vec3f(vec[0], vec[1], vec[2])));
-        auto_ptr<sfdata> sfdata(new sfdata(sfvec3f.get()));
+        auto_ptr<sfdata> sfdata(new sfield::sfdata(sfvec3f.get()));
         sfvec3f.release();
         if (!JS_SetPrivate(cx, obj, sfdata.get())) { return JS_FALSE; }
         sfdata.release();
