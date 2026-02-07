https://github.com/scim-im/scim/commit/ea2a777b2fab

--- src/scim_debug.h.orig	2008-11-02 06:42:34 UTC
+++ src/scim_debug.h
@@ -41,7 +41,7 @@ namespace scim {
  * @name The mask for debug messages filtering.
  * @{
  */
-#define SCIM_DEBUG_AllMask          (~0) /**< Show all messages. */
+#define SCIM_DEBUG_AllMask          ((uint32)~0) /**< Show all messages. */
 #define SCIM_DEBUG_MainMask         1    /**< Show messages of main application. */
 #define SCIM_DEBUG_ConfigMask       2    /**< Show messages of Config objects */
 #define SCIM_DEBUG_IMEngineMask     4    /**< Show messages of IMEngine objects */
