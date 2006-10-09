--- estic-1.61.orig/spunk/str.h
+++ spunk/str.h
@@ -91,6 +91,46 @@
 // Note: This string class may not work with strings greater than INT_MAX or
 //       0xFFFF, whichever is less
 
+// Declare functions and operators which are later 'injected' as friends
+// (gcc-4.1 doesn't allow friend injection any more)
+
+    String ShowControls (const String& S, unsigned Style);
+    String HideControls (const String& S);
+    String& operator += (String&, const char);
+    String& operator += (String&, const char*);
+    inline String& operator += (String&, const String&);
+    String operator + (const String&, const char);
+    String operator + (const String&, const char*);
+    String operator + (const String&, const String&);
+    String operator + (const char, const String&);
+    String operator + (const char*, const String&);
+    inline int operator == (const String&, const String&);
+    inline int operator != (const String&, const String&);
+    inline int operator >= (const String&, const String&);
+    inline int operator <= (const String&, const String&);
+    inline int operator > (const String&, const String&);
+    inline int operator < (const String&, const String&);
+    inline int operator == (const char*, const String&);
+    inline int operator != (const char*, const String&);
+    inline int operator >= (const char*, const String&);
+    inline int operator <= (const char*, const String&);
+    inline int operator > (const char*, const String&);
+    inline int operator < (const char*, const String&);
+    inline int operator == (const String&, const char*);
+    inline int operator != (const String&, const char*);
+    inline int operator >= (const String&, const char*);
+    inline int operator <= (const String&, const char*);
+    inline int operator > (const String&, const char*);
+    inline int operator < (const String&, const char*);
+
+    inline int Compare (const String& S1, const String& S2);
+
+    int Match (const char* Source, const char* Pattern);
+    int Match (const String& Source, const String& Pattern);
+    int Match (const String& Source, const char* Pattern);
+    int Match (const char* Source, const String& Pattern);
+
+    String FormatStr (const char* S, ...);
 
 class String : public Streamable {
 
