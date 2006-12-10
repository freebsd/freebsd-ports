--- src/rpsl/rpsl/rpsl_attr.hh.orig	2004-07-30 12:58:15.000000000 +0200
+++ src/rpsl/rpsl/rpsl_attr.hh
@@ -131,7 +131,7 @@ public:
       return "Attr";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "(*** Need more work here ***)" << endl;
+      INDENT(indent); os << "(*** Need more work here ***)" << std::endl;
    }
 #endif // DEBUG
 };
@@ -311,7 +311,7 @@ public:
       return "AttrAttr";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-     INDENT(indent); os << "_name = \"" << name() << "\"" << endl;
+     INDENT(indent); os << "_name = \"" << name() << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -370,7 +370,7 @@ public:
       return "AttrClass";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "(*** Need more work here ***)" << endl;
+      INDENT(indent); os << "(*** Need more work here ***)" << std::endl;
    }
 #endif // DEBUG
 };
@@ -400,9 +400,9 @@ public:
       return "AttrGeneric";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "type" << endl;
+      INDENT(indent); os << "type" << std::endl;
       type->printClass(os, indent + 2);
-      INDENT(indent); os << "items (" << items->className() << " *)" << endl;
+      INDENT(indent); os << "items (" << items->className() << " *)" << std::endl;
       items->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -583,7 +583,7 @@ public:
       return "AttrProtocol";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "name = \"" << name << "\"" << endl;
+      INDENT(indent); os << "name = \"" << name << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -620,19 +620,19 @@ public:
       return "AttrImport";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "fromProt" << endl;
+      INDENT(indent); os << "fromProt" << std::endl;
       if (fromProt) 
 	 fromProt->printClass(os, indent + 2);
       else {
-	 INDENT(indent); os << "  NULL" << endl;
+	 INDENT(indent); os << "  NULL" << std::endl;
       }
-      INDENT(indent); os << "intoProt" << endl;
+      INDENT(indent); os << "intoProt" << std::endl;
       if (intoProt) 
 	 intoProt->printClass(os, indent + 2);
       else {
-	 INDENT(indent); os << "  NULL" << endl;
+	 INDENT(indent); os << "  NULL" << std::endl;
       }
-      INDENT(indent); os << "policy (" << policy->className() << " *)" << endl;
+      INDENT(indent); os << "policy (" << policy->className() << " *)" << std::endl;
       policy->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -668,19 +668,19 @@ public:
       return "AttrExport";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "fromProt" << endl;
+      INDENT(indent); os << "fromProt" << std::endl;
       if (fromProt) 
 	 fromProt->printClass(os, indent + 2);
       else {
-	 INDENT(indent); os << "  NULL" << endl;
+	 INDENT(indent); os << "  NULL" << std::endl;
       }
-      INDENT(indent); os << "intoProt" << endl;
+      INDENT(indent); os << "intoProt" << std::endl;
       if (intoProt) 
 	 intoProt->printClass(os, indent + 2);
       else {
-	 INDENT(indent); os << "  NULL" << endl;
+	 INDENT(indent); os << "  NULL" << std::endl;
       }
-      INDENT(indent); os << "policy (" << policy->className() << " *)" << endl;
+      INDENT(indent); os << "policy (" << policy->className() << " *)" << std::endl;
       policy->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -725,11 +725,11 @@ public:
       return "AttrDefault";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "peering (PolicyPeering *)" << endl;
+      INDENT(indent); os << "peering (PolicyPeering *)" << std::endl;
       peering->printClass(os, indent + 2);
-      INDENT(indent); os << "action (PolicyActionList *)" << endl;
+      INDENT(indent); os << "action (PolicyActionList *)" << std::endl;
       action->printClass(os, indent + 2);
-      INDENT(indent); os << "filter (Filter *)" << endl;
+      INDENT(indent); os << "filter (Filter *)" << std::endl;
       filter->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -757,7 +757,7 @@ public:
       return "AttrFilter";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "filter (Filter *)" << endl;
+      INDENT(indent); os << "filter (Filter *)" << std::endl;
       filter->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -785,7 +785,7 @@ public:
       return "AttrMPPeval";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "mp-peval (Filter *)" << endl;
+      INDENT(indent); os << "mp-peval (Filter *)" << std::endl;
       filter->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -815,7 +815,7 @@ public:
       return "AttrPeering";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "peering (PolicyPeering *)" << endl;
+      INDENT(indent); os << "peering (PolicyPeering *)" << std::endl;
       peering->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -852,9 +852,9 @@ public:
       // ??? This causes a lot of warning mesg right now
       // It's hard to fix since it involves modification to
       // hundred of places across the whole src tree
-      //     os << "ifaddr = " << ifaddr << endl;
+      //     os << "ifaddr = " << ifaddr << std::endl;
       os << "(*** Need to fix const declaration in the extraction operator ***)"
-	 << endl;
+	 << std::endl;
    }
 #endif // DEBUG
 };
@@ -922,9 +922,9 @@ public:
       // ??? This causes a lot of warning mesg right now
       // It's hard to fix since it involves modification to
       // hundred of places across the whole src tree
-      //     os << "ifaddr = " << ifaddr << endl;
+      //     os << "ifaddr = " << ifaddr << std::endl;
       os << "(*** Need to fix const declaration in the extraction operator ***)"
-   << endl;
+   << std::endl;
    }
 #endif // DEBUG
 };
@@ -960,15 +960,15 @@ public:
    }
    virtual void printClass(std::ostream &os, int indent) const {
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
