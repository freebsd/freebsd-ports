--- src/build_sources/proxy.h.m4.orig	Sun Sep  5 05:45:02 2004
+++ src/build_sources/proxy.h.m4	Sun Sep  5 05:50:18 2004
@@ -174,20 +174,20 @@
           data.callback=&callback;
           data.obj=this;
           SigC::ScopeNode* node=tmp->receiver();
-          obj->register_data(node);
+          this->obj->register_data(node);
           return tmp;
         }
 
       RType emit(ARG_BOTH($1))
         {
           return reinterpret_cast<RType (*)(LIST(gObj*,1,ARG_TYPE($1),[$1]))>
-            (emit_func) (LIST(obj->gtkobj(),1,ARG_NAME($1),[$1]));
+            (emit_func) (LIST(this->obj->gtkobj(),1,ARG_NAME($1),[$1]));
         }
 
       RType operator()(ARG_BOTH($1))
         {
           return reinterpret_cast<RType (*)(LIST(gObj*,1,ARG_TYPE($1),[$1]))>
-            (emit_func) (LIST(obj->gtkobj(),1,ARG_NAME($1),[$1]));
+            (emit_func) (LIST(this->obj->gtkobj(),1,ARG_NAME($1),[$1]));
         }
 
   };
