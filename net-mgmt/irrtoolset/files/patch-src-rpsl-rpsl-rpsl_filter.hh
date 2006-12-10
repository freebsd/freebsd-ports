--- src/rpsl/rpsl/rpsl_filter.hh.orig	2005-08-25 12:41:52.000000000 +0200
+++ src/rpsl/rpsl/rpsl_filter.hh
@@ -92,8 +92,8 @@
    virtual Filter* dup() const = 0;
 #ifdef DEBUG
    virtual const char *className(void) const = 0;
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "(*** Need more work here ***)" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); print(os); os << std::endl;
    }
 #endif // DEBUG
 };
@@ -125,10 +125,10 @@
    virtual const char *className(void) const {
       return "FilterOR";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "f1 (" << f1->className() << " *)" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "f1 (" << f1->className() << " *)" << std::endl;
       f1->printClass(os, indent + 2);
-      INDENT(indent); os << "f2 (" << f2->className() << " *)" << endl;
+      INDENT(indent); os << "f2 (" << f2->className() << " *)" << std::endl;
       f2->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -157,10 +157,10 @@
    virtual const char *className(void) const {
       return "FilterAND";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "f1" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "f1" << std::endl;
       f1->printClass(os, indent + 2);
-      INDENT(indent); os << "f2" << endl;
+      INDENT(indent); os << "f2" << std::endl;
       f2->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -186,8 +186,8 @@
    virtual const char *className(void) const {
       return "FilterNOT";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "f1 (NOT)" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "f1 (NOT)" << std::endl;
       f1->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -216,10 +216,10 @@
    virtual const char *className(void) const {
       return "FilterEXCEPT";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "f1" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "f1" << std::endl;
       f1->printClass(os, indent + 2);
-      INDENT(indent); os << "f2" << endl;
+      INDENT(indent); os << "f2" << std::endl;
       f2->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -256,8 +256,8 @@
    virtual const char *className(void) const {
       return "FilterMS";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "f1 (" << f1->className() << " *)" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "f1 (" << f1->className() << " *)" << std::endl;
       f1->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -279,8 +279,8 @@
    virtual const char *className(void) const {
       return "FilterASNO";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "asno = " << asno << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "asno = " << asno << std::endl;
    }
 #endif // DEBUG
 };
@@ -301,8 +301,8 @@
    virtual const char *className(void) const {
       return "FilterASNAME";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "asname = \"" << asname << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "asname = \"" << asname << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -323,8 +323,8 @@
    virtual const char *className(void) const {
       return "FilterRSNAME";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "rsname = \"" << rsname << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "rsname = \"" << rsname << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -345,8 +345,8 @@
    virtual const char *className(void) const {
       return "FilterRTRSNAME";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "rtrsname = \"" << rtrsname << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "rtrsname = \"" << rtrsname << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -368,7 +368,7 @@
       return "FilterFLTRNAME";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "fltrname = \"" << fltrname << "\"" << endl;
+      INDENT(indent); os << "fltrname = \"" << fltrname << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -386,8 +386,8 @@
    virtual const char *className(void) const {
       return "FilterANY";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "ANY" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "ANY" << std::endl;
    }
 #endif // DEBUG
 };
@@ -405,8 +405,8 @@
    virtual const char *className(void) const {
       return "FilterPeerAS";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "peerAS" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "peerAS" << std::endl;
    }
 #endif // DEBUG
 };
@@ -432,8 +432,8 @@
    virtual const char *className(void) const {
       return "FilterASPath";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "re = ..." << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "re = ..." << std::endl;
    }
 #endif // DEBUG
 };
@@ -452,8 +452,8 @@
    virtual const char *className(void) const {
       return "FilterPRFXList";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << *this << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << *this << std::endl;
    }
 #endif // DEBUG
 };
@@ -477,8 +477,8 @@
    virtual const char *className(void) const {
       return "FilterMPPRFXList";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << *this << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); print(os); os << std::endl;
    }
 #endif // DEBUG
 };
@@ -516,8 +516,8 @@
    virtual const char *className(void) const {
       return "FilterAFI";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << *this << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << *this << std::endl;
    }
 #endif // DEBUG
 
@@ -554,17 +554,17 @@
    virtual const char *className(void) const {
       return "FilterRPAttribute";
    }
-   virtual void printClass(ostream &os, int indent) const {
+   virtual void printClass(std::ostream &os, int indent) const {
       // For rp_attr
-      INDENT(indent); os << "rp_attr" << endl;
-      INDENT(indent); os << "  _name = \"" << "\"" << endl;
-      INDENT(indent); os << "  methods (RPMethod *)" << endl;
-      INDENT(indent); os << "    _name = \"" << "\"" << endl;
+      INDENT(indent); os << "rp_attr" << std::endl;
+      INDENT(indent); os << "  _name = \"" << "\"" << std::endl;
+      INDENT(indent); os << "  methods (RPMethod *)" << std::endl;
+      INDENT(indent); os << "    _name = \"" << "\"" << std::endl;
       // For rp_method
-      INDENT(indent); os << "rp_method" << endl;
-      INDENT(indent); os << "  _name = \"" << "\"" << endl;
+      INDENT(indent); os << "rp_method" << std::endl;
+      INDENT(indent); os << "  _name = \"" << "\"" << std::endl;
       // For rp_args
-      INDENT(indent); os << "args (ItemList *)" << endl;
+      INDENT(indent); os << "args (ItemList *)" << std::endl;
       args->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -722,7 +722,7 @@
       return "FilterRouterName";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "name = \"" << name << "\"" << endl;
+      INDENT(indent); os << "name = \"" << name << "\"" << std::endl;
    }
 #endif // DEBUG
 };
