--- api/vpl/mfxdefs.h.orig	2025-04-18 15:44:33 UTC
+++ api/vpl/mfxdefs.h
@@ -64,7 +64,7 @@ extern "C"
     #define MFX_PACK_BEGIN_STRUCT_W_PTR()    MFX_PACK_BEGIN_X(8)
     #define MFX_PACK_BEGIN_STRUCT_W_L_TYPE() MFX_PACK_BEGIN_X(8)
 /* 32-bit ILP32 data model Windows* (Intel(r) architecture) */
-#elif defined(_WIN32) || defined(_M_IX86) && !defined(__linux__)
+#elif defined(_WIN32) || defined(_M_IX86) && !defined(__unix__)
     #define MFX_PACK_BEGIN_STRUCT_W_PTR()    MFX_PACK_BEGIN_X(4)
     #define MFX_PACK_BEGIN_STRUCT_W_L_TYPE() MFX_PACK_BEGIN_X(8)
 /* 32-bit ILP32 data model Linux* */
@@ -99,7 +99,7 @@ extern "C"
        #define MFX_DEPRECATED __declspec(deprecated)
        #define MFX_DEPRECATED_ENUM_FIELD_INSIDE(arg) arg
        #define MFX_DEPRECATED_ENUM_FIELD_OUTSIDE(arg) __pragma(deprecated(arg))
-     #elif defined(__linux__)
+     #elif defined(__unix__)
        #define MFX_DEPRECATED __attribute__((deprecated))
        #if defined(__cplusplus)
          #define MFX_DEPRECATED_ENUM_FIELD_INSIDE(arg) arg __attribute__((deprecated))
