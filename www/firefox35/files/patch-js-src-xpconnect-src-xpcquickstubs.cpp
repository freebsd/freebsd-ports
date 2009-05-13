--- js/src/xpconnect/src/xpcquickstubs.cpp.orig        2009-05-10 14:31:55.000000000 +0200
+++ js/src/xpconnect/src/xpcquickstubs.cpp     2009-05-10 14:33:07.000000000 +0200
@@ -210,8 +210,8 @@
     if(setterobjp)
         *setterobjp = setterobj;
     return JS_DefinePropertyById(cx, obj, interned_id, JSVAL_VOID,
-                                 (JSPropertyOp)getterobj,
-                                 (JSPropertyOp)setterobj,
+                                     JS_DATA_TO_FUNC_PTR(JSPropertyOp, getterobj),
+                                     JS_DATA_TO_FUNC_PTR(JSPropertyOp, setterobj),
                                  attrs);
 }

@@ -255,7 +255,7 @@
         if(attrs & JSPROP_GETTER)
         {
             JS_SET_RVAL(cx, vp,
-                        OBJECT_TO_JSVAL(reinterpret_cast<JSObject *>(getter)));
+                         OBJECT_TO_JSVAL(JS_FUNC_TO_DATA_PTR(JSObject *, getter)));
             return JS_TRUE;
         }
     }
@@ -264,7 +264,7 @@
         if(attrs & JSPROP_SETTER)
         {
             JS_SET_RVAL(cx, vp,
-                        OBJECT_TO_JSVAL(reinterpret_cast<JSObject *>(setter)));
+                        OBJECT_TO_JSVAL(JS_FUNC_TO_DATA_PTR(JSObject *, setter)));
             return JS_TRUE;
         }
     }

