--- include/Attribute.h.orig	Fri Mar 10 03:30:56 2000
+++ include/Attribute.h	Tue Aug  5 11:49:19 2003
@@ -25,12 +25,32 @@
 class Entity;
 class Notation;
 class DeclaredValue;
-class AttributeValue;
 class TokenizedAttributeValue;
 class AttributeSemantics;
 class AttributeContext;
 class Syntax;
 
+class SP_API AttributeValue : public Resource {
+public:
+  enum Type {
+    implied,
+    cdata,
+    tokenized
+    };
+  AttributeValue();
+  virtual ~AttributeValue();
+  virtual AttributeSemantics *makeSemantics(const DeclaredValue *,
+					    AttributeContext &,
+					    const StringC &,
+					    unsigned &,
+					    unsigned &) const;
+  virtual Type info(const Text *&, const StringC *&) const = 0;
+  virtual const Text *text() const;
+  virtual Boolean recoverUnquoted(const StringC &, const Location &,
+				  AttributeContext &, const StringC &);
+  static Boolean handleAsUnterminated(const Text &, AttributeContext &);
+};
+
 class SP_API AttributeDefinitionDesc {
 public:
   AttributeDefinitionDesc() { }
@@ -378,27 +398,6 @@
   AttributeSemantics *copy() const;
 private:
   ConstPtr<Notation> notation_;
-};
-
-class SP_API AttributeValue : public Resource {
-public:
-  enum Type {
-    implied,
-    cdata,
-    tokenized
-    };
-  AttributeValue();
-  virtual ~AttributeValue();
-  virtual AttributeSemantics *makeSemantics(const DeclaredValue *,
-					    AttributeContext &,
-					    const StringC &,
-					    unsigned &,
-					    unsigned &) const;
-  virtual Type info(const Text *&, const StringC *&) const = 0;
-  virtual const Text *text() const;
-  virtual Boolean recoverUnquoted(const StringC &, const Location &,
-				  AttributeContext &, const StringC &);
-  static Boolean handleAsUnterminated(const Text &, AttributeContext &);
 };
 
 class SP_API ImpliedAttributeValue : public AttributeValue {
