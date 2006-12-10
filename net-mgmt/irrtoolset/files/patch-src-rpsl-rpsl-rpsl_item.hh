--- src/rpsl/rpsl/rpsl_item.hh.orig	2004-07-30 12:58:15.000000000 +0200
+++ src/rpsl/rpsl/rpsl_item.hh
@@ -100,8 +100,8 @@ public:
    virtual Buffer *bufferize(Buffer *buf = NULL, bool lcase = false) const = 0;
 #ifdef DEBUG
    virtual const char *className(void) const = 0;
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "(*** Need more work here ***)" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "(*** Need more work here ***)" << std::endl;
    }
 #endif // DEBUG
 };
@@ -131,8 +131,8 @@ public:
    virtual const char *className(void) const {
       return "ItemASNO";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "asno = " << asno << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "asno = " << asno << std::endl;
    }
 #endif // DEBUG
 };
@@ -188,8 +188,8 @@ public:
    virtual const char *className(void) const {
       return "ItemFilter";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "filter = " << filter << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "filter = " << filter << std::endl;
    }
 #endif // DEBUG
 };
@@ -213,8 +213,8 @@ public:
    virtual const char *className(void) const {
       return "ItemINT";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "i = " << i << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "i = " << i << std::endl;
    }
 #endif // DEBUG
 };
@@ -238,8 +238,8 @@ public:
    virtual const char *className(void) const {
       return "ItemTimeStamp";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "stamp = " << stamp << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "stamp = " << stamp << std::endl;
    }
 #endif // DEBUG
 };
@@ -263,8 +263,8 @@ public:
    virtual const char *className(void) const {
       return "ItemREAL";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "real = " << real << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "real = " << real << std::endl;
    }
 #endif // DEBUG
 };
@@ -295,8 +295,8 @@ public:
    virtual const char *className(void) const {
       return "ItemSTRING";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "string = \"" << string << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "string = \"" << string << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -326,8 +326,8 @@ public:
    virtual const char *className(void) const {
       return "ItemBLOB";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "blob = \"" << blob << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "blob = \"" << blob << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -358,8 +358,8 @@ public:
    virtual const char *className(void) const {
       return "ItemBUFFER";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "buffer = \"" << buffer << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "buffer = \"" << buffer << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -391,7 +391,7 @@ public:
       return "ItemIPV4";
    }
    virtual void printClass(std::ostream &os, int indent) const {
-      INDENT(indent); os << "ipv4 = \"" << *ipv4 << "\"" << endl;
+      INDENT(indent); os << "ipv4 = \"" << *ipv4 << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -424,8 +424,8 @@ public:
    virtual const char *className(void) const {
       return "ItemPRFXV4";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "prfxv4 = \"" << *prfxv4 << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "prfxv4 = \"" << *prfxv4 << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -460,8 +460,8 @@ public:
    virtual const char *className(void) const {
       return "ItemPRFXV4Range";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "prfxv4 = \"" << *prfxv4 << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "prfxv4 = \"" << *prfxv4 << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -493,8 +493,8 @@ public:
    virtual const char *className(void) const {
       return "ItemIPV6";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "ipv6 = \"" << *ipv6 << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "ipv6 = \"" << *ipv6 << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -526,8 +526,8 @@ public:
    virtual const char *className(void) const {
       return "ItemPRFXV6";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "prfxv6 = \"" << *prfxv6 << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "prfxv6 = \"" << *prfxv6 << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -563,8 +563,8 @@ public:
    virtual const char *className(void) const {
       return "ItemPRFXV6Range";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "prfxrangev6 = \"" << *prfxv6 << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "prfxrangev6 = \"" << *prfxv6 << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -596,8 +596,8 @@ public:
    virtual const char *className(void) const {
       return "ItemAFI";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "afi = \"" << *afi << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "afi = \"" << *afi << "\"" << std::endl;
    }
 #endif // DEBUG
    int operator==(ItemAFI &af) {
@@ -642,10 +642,10 @@ public:
    virtual const char *className(void) const {
       return "ItemConnection";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "ip   = \"" << *ip  << "\"" << endl;
-      INDENT(indent); os << "host = \"" << host << "\"" << endl;
-      INDENT(indent); os << "port = \"" << port << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "ip   = \"" << *ip  << "\"" << std::endl;
+      INDENT(indent); os << "host = \"" << host << "\"" << std::endl;
+      INDENT(indent); os << "port = \"" << port << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -667,8 +667,8 @@ public:
    virtual const char *className(void) const {
       return "ItemSID";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "name (SymID) = \"" << name << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "name (SymID) = \"" << name << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -718,8 +718,8 @@ public:
    virtual const char *className(void) const {
       return "ItemBOOLEAN";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "i = " << i << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "i = " << i << std::endl;
    }
 #endif // DEBUG
 };
@@ -754,8 +754,8 @@ public:
    virtual const char *className(void) const {
       return "ItemWORD";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "word = \"" << word << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "word = \"" << word << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -782,8 +782,8 @@ public:
    virtual const char *className(void) const {
       return "ItemEMAIL";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "email = \"" << email << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "email = \"" << email << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -805,7 +805,7 @@ public:
    virtual const char *className(void) const {
       return "ItemFREETEXT";
    }
-   virtual void printClass(ostream &os, int indent) const {
+   virtual void printClass(std::ostream &os, int indent) const {
       INDENT(indent); os << "\"";
 #define DISPLAYFREETEXTLENGTH  63
       if (length > DISPLAYFREETEXTLENGTH) {
@@ -813,7 +813,7 @@ public:
 	strncpy(buf, text, DISPLAYFREETEXTLENGTH - 3);
 	buf[DISPLAYFREETEXTLENGTH - 3] = 0;
 	strcat(buf, "...");
-	os << buf << endl;
+	os << buf << std::endl;
       } else {
 	for (int i = 0; i < length; i++) {
 	  char ch = *(text + i);
@@ -823,7 +823,7 @@ public:
 	    os << ch;
         }
       }
-      os << "\"" << endl;
+      os << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -902,9 +902,9 @@ public:
    virtual const char *className(void) const {
       return "ItemList";
    }
-   virtual void printClass(ostream &os, int indent) const {
+   virtual void printClass(std::ostream &os, int indent) const {
      for (Item *item = head(); item; item = next(item)) {
-        INDENT(indent); os << item->className() << endl;
+        INDENT(indent); os << item->className() << std::endl;
         item->printClass(os, indent + 2);
      }
    }
@@ -935,9 +935,9 @@ public:
    virtual const char *className(void) const {
       return "ItemRange";
    }
-   virtual void printClass(ostream &os, int indent) const {
-      INDENT(indent); os << "begin = \"" << "\"" << endl;
-      INDENT(indent); os << "end = \"" << "\"" << endl;
+   virtual void printClass(std::ostream &os, int indent) const {
+      INDENT(indent); os << "begin = \"" << "\"" << std::endl;
+      INDENT(indent); os << "end = \"" << "\"" << std::endl;
    }
 #endif // DEBUG
 };
@@ -968,9 +968,9 @@ public:
    virtual const char *className(void) const {
       return "ItemSequence";
    }
-   virtual void printClass(ostream &os, int indent) const {
+   virtual void printClass(std::ostream &os, int indent) const {
      for (Item *item = head(); item; item = next(item)) {
-        INDENT(indent); os << item->className() << endl;
+        INDENT(indent); os << item->className() << std::endl;
         item->printClass(os, indent + 2);
      }
    }
