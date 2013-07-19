--- xbmc/visualizations/XBMCProjectM/libprojectM/PresetLoader.hpp.orig	2013-07-04 15:52:54.000000000 +0200
+++ xbmc/visualizations/XBMCProjectM/libprojectM/PresetLoader.hpp	2013-07-04 15:53:28.000000000 +0200
@@ -29,7 +29,7 @@
 		static const std::string MILKDROP_FILE_EXTENSION;
 		
 		/** Initializes the preset loader with the target directory specified */
-		PresetLoader(std::string dirname);
+		PresetLoader(std::string dirname = std::string());
 		
 		/** Destructor will remove all alllocated presets */
 		~PresetLoader();
