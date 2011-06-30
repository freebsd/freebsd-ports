--- ./src/3rdparty/webkit/WebCore/bindings/js/JSDOMBinding.h.orig	2011-06-30 11:23:39.846687664 +0200
+++ ./src/3rdparty/webkit/WebCore/bindings/js/JSDOMBinding.h	2011-06-30 11:24:11.486683861 +0200
@@ -225,7 +225,7 @@
     {
         if (!node)
             return JSC::jsNull();
-        if (JSNode* wrapper = getCachedDOMNodeWrapper(exec, node->document(), node))
+        if (JSC::JSCell* wrapper = getCachedDOMNodeWrapper(exec, node->document(), node))
             return wrapper;
         return createDOMNodeWrapper<WrapperClass>(exec, globalObject, node);
     }
