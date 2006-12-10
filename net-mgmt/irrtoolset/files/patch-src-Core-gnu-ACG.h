--- src/Core/gnu/ACG.h.orig	2002-03-27 12:32:59.000000000 +0100
+++ src/Core/gnu/ACG.h
@@ -42,26 +42,26 @@ Foundation, 59 Temple Place - Suite 330,
 
 class ACG : public RNG {
 
-    _G_uint32_t initialSeed;	// used to reset generator
+    uint32_t initialSeed;	// used to reset generator
     int initialTableEntry;
 
-    _G_uint32_t *state;
-    _G_uint32_t *auxState;
+    uint32_t *state;
+    uint32_t *auxState;
     short stateSize;
     short auxSize;
-    _G_uint32_t lcgRecurr;
+    uint32_t lcgRecurr;
     short j;
     short k;
 
 protected:
 
 public:
-    ACG(_G_uint32_t seed = 0, int size = 55);
+    ACG(uint32_t seed = 0, int size = 55);
     virtual ~ACG();
     //
     // Return a long-words word of random bits
     //
-    virtual _G_uint32_t asLong();
+    virtual uint32_t asLong();
     virtual void reset();
 };
 
