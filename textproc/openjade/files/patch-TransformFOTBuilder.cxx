--- jade/TransformFOTBuilder.cxx.orig	2011-09-24 14:20:28.000000000 +0000
+++ jade/TransformFOTBuilder.cxx	2011-09-24 14:22:32.000000000 +0000
@@ -41,6 +41,7 @@
   };
   class EntityRefFlowObj : public TransformExtensionFlowObj {
   public:
+    EntityRefFlowObj() {}
     void atomic(TransformFOTBuilder &fotb, const NodePtr &) const {
       fotb.entityRef(name_);
     }
@@ -56,6 +57,7 @@
   };
   class ProcessingInstructionFlowObj : public TransformExtensionFlowObj {
   public:
+    ProcessingInstructionFlowObj() {}
     void atomic(TransformFOTBuilder &fotb, const NodePtr &) const {
       fotb.processingInstruction(data_);
     }
@@ -98,6 +100,8 @@
       }
     }
     ExtensionFlowObj *copy() const { return new EmptyElementFlowObj(*this); }
+  public:
+    EmptyElementFlowObj() {}
   private:
     ElementNIC nic_;
   };
@@ -133,6 +137,8 @@
       }
     }
     ExtensionFlowObj *copy() const { return new ElementFlowObj(*this); }
+  public:
+    ElementFlowObj() {}
   private:
     ElementNIC nic_;
   };
@@ -150,6 +156,8 @@
       value.convertString(systemId_);
     }
     ExtensionFlowObj *copy() const { return new EntityFlowObj(*this); }
+  public:
+    EntityFlowObj() {};
   private:
     StringC systemId_;
   };
@@ -174,6 +182,8 @@
       }
     }
     ExtensionFlowObj *copy() const { return new DocumentTypeFlowObj(*this); }
+  public:
+    DocumentTypeFlowObj() {}
   private:
     DocumentTypeNIC nic_;
   };
