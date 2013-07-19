--- xbmc/visualizations/XBMCProjectM/libprojectM/PresetLoader.cpp.orig	2013-07-04 15:52:45.000000000 +0200
+++ xbmc/visualizations/XBMCProjectM/libprojectM/PresetLoader.cpp	2013-07-04 15:53:32.000000000 +0200
@@ -35,7 +35,7 @@
 const std::string PresetLoader::PROJECTM_FILE_EXTENSION(".prjm");
 const std::string PresetLoader::MILKDROP_FILE_EXTENSION(".milk");
 
-PresetLoader::PresetLoader(std::string dirname = std::string()) :m_dirname(dirname), m_dir(0), m_ratingsSum(0)
+PresetLoader::PresetLoader(std::string dirname) :m_dirname(dirname), m_dir(0), m_ratingsSum(0)
 {
   // Do one scan
 	if (m_dirname != std::string())
