--- xbmc/visualizations/XBMCProjectM/libprojectM/PresetLoader.hpp.orig	2015-05-11 07:54:22 UTC
+++ xbmc/visualizations/XBMCProjectM/libprojectM/PresetLoader.hpp
@@ -29,7 +29,7 @@ class PresetLoader {
 		static const std::string MILKDROP_FILE_EXTENSION;
 		
 		/** Initializes the preset loader with the target directory specified */
-		PresetLoader(std::string dirname);
+		PresetLoader(std::string dirname = std::string());
 		
 		/** Destructor will remove all alllocated presets */
 		~PresetLoader();
