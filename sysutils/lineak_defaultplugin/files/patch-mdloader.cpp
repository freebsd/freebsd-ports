--- default_plugin/mdloader.cpp.orig	Tue Feb 15 18:31:13 2005
+++ default_plugin/mdloader.cpp	Tue Feb 15 18:31:41 2005
@@ -109,7 +109,7 @@
 	   // Handle empty lines.
 	   loc = tmp.find('=');
            // empty line
-   	   if (loc == string::npos)
+   	   if (loc == (unsigned int)string::npos)
    	     continue;
 
 	   // key == the name of the key.
