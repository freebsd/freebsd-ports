--- src/rpsl/rpsl/rpsl_policy.hh.orig	2004-07-30 12:58:15.000000000 +0200
+++ src/rpsl/rpsl/rpsl_policy.hh
@@ -91,8 +91,8 @@ public:
 
 #ifdef DEBUG
    virtual const char *className(void) const = 0;
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "(*** Need more work here ***)" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "(*** Need more work here ***)" << std::endl;
    }
 #endif // DEBUG
 };
@@ -170,15 +170,15 @@ public:
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
@@ -231,9 +231,9 @@ public:
       return "PolicyPeeringAction";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "peering (PolicyPeering *)" << endl;
+      INDENT(indent); os << "peering (PolicyPeering *)" << std::endl;
       peering->printClass(os, indent + 2);
-      INDENT(indent); os << "action (PolicyActionList *)" << endl;
+      INDENT(indent); os << "action (PolicyActionList *)" << std::endl;
       action->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -265,14 +265,14 @@ public:
    }
    virtual void printClass(std::ostream &os, int indent) const {
       // Action
-      INDENT(indent); os << "peeringActionList" << endl;
+      INDENT(indent); os << "peeringActionList" << std::endl;
       for (PolicyPeeringAction *pc = peeringActionList->head(); 
 	   pc;
 	   pc = peeringActionList->next(pc)) {
 	 pc->printClass(os, indent + 2);
       }
       // Filter
-      INDENT(indent); os << "filter (Filter *)" << endl;
+      INDENT(indent); os << "filter (Filter *)" << std::endl;
       filter->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -327,9 +327,9 @@ public:
       return "PolicyRefine";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "left" << endl;
+      INDENT(indent); os << "left" << std::endl;
       left->printClass(os, indent + 2);
-      INDENT(indent); os << "right" << endl;
+      INDENT(indent); os << "right" << std::endl;
       right->printClass(os, indent + 2);
    }
 #endif // DEBUG
@@ -358,9 +358,9 @@ public:
       return "PolicyExcept";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "left" << endl;
+      INDENT(indent); os << "left" << std::endl;
       left->printClass(os, indent + 2);
-      INDENT(indent); os << "right" << endl;
+      INDENT(indent); os << "right" << std::endl;
       right->printClass(os, indent + 2);
    }
 #endif // DEBUG
