--- source/updater.hpp.orig	2022-12-29 20:10:45 UTC
+++ source/updater.hpp
@@ -45,8 +45,8 @@ namespace streamfx {
 
 	struct version_info {
 		public:
-		uint16_t      major;
-		uint16_t      minor;
+		uint16_t      major_;
+		uint16_t      minor_;
 		uint16_t      patch;
 		uint16_t      tweak;
 		version_stage stage;
