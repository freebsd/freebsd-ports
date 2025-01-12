--- src/js/spidermonkey/fragment.cpp.orig	2024-12-26 11:02:09 UTC
+++ src/js/spidermonkey/fragment.cpp
@@ -2290,7 +2290,7 @@ DocumentFragment_constructor(JSContext *ctx, unsigned 
 	}
 	JS::Realm *comp = js::GetContextRealm(ctx);
 	struct ecmascript_interpreter *interpreter = (struct ecmascript_interpreter *)JS::GetRealmPrivate(comp);
-	JS::RootedObject r_doc(ctx, interpreter->document_obj);
+	JS::RootedObject r_doc(ctx, (JSObject *)interpreter->document_obj);
 	dom_document *doc = JS::GetMaybePtrFromReservedSlot<dom_document>(r_doc, 0);
 
 	if (!doc) {
