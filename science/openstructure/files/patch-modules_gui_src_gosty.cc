--- modules/gui/src/gosty.cc.orig	2018-07-09 03:10:04 UTC
+++ modules/gui/src/gosty.cc
@@ -111,7 +111,7 @@ String setup_python_search_path(const St
 #ifdef _MSC_VER
   String loc=root+"\\lib\\"+site_pkgs.str()+"\\site-packages";
 #else  
-# if (defined(__ppc64__) || defined(__x86_64__)) && !defined(__APPLE__) && !OST_UBUNTU_LAYOUT
+# if (defined(__ppc64__) || defined(__x86_64__)) && !defined(__APPLE__) && !OST_UBUNTU_LAYOUT && !defined(__FreeBSD__)
   String loc=root+"/lib64/"+site_pkgs.str()+"/site-packages";
 # else
   String loc=root+"/lib/"+site_pkgs.str()+"/site-packages";
