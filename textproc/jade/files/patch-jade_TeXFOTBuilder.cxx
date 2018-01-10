--- jade/TeXFOTBuilder.cxx.orig	1998-10-07 05:16:34 UTC
+++ jade/TeXFOTBuilder.cxx
@@ -83,6 +83,8 @@ class TeXFOTBuilder : public SerialFOTBuilder { (publi
       value.convertString(nic_.placement);
       }
     ExtensionFlowObj *copy() const { return new PageFloatFlowObj(*this); }
+  public:
+    PageFloatFlowObj() {}
   private:
     PageFloatNIC nic_;
     StringC name_;
@@ -96,6 +98,8 @@ class TeXFOTBuilder : public SerialFOTBuilder { (publi
       fotb.endPageFootnote();
     }
     ExtensionFlowObj *copy() const { return new PageFootnoteFlowObj(*this); }
+  public:
+    PageFootnoteFlowObj() {}
   private:
   };
   //////////////////////////////////////////////////////////////////////
