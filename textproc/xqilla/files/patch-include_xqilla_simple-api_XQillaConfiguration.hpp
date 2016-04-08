--- include/xqilla/simple-api/XQillaConfiguration.hpp.orig	2015-05-18 17:38:59 UTC
+++ include/xqilla/simple-api/XQillaConfiguration.hpp
@@ -53,9 +53,13 @@ public:
 
   virtual ASTToXML *createASTToXML() = 0;
 
-  virtual void populateStaticContext(StaticContext *context) {}
+  virtual void populateStaticContext(StaticContext *context) {
+	  (void) context;
+  }
 
-  virtual void populateDynamicContext(DynamicContext *context) {}
+  virtual void populateDynamicContext(DynamicContext *context) {
+	  (void) context;
+  }
 
   virtual void testInterrupt() {}
 };
