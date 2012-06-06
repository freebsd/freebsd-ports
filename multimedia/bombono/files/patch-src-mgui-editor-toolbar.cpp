--- src/mgui/editor/toolbar.cpp.orig	2012-06-05 17:43:12.000000000 +0200
+++ src/mgui/editor/toolbar.cpp	2012-06-05 17:43:33.000000000 +0200
@@ -287,7 +287,7 @@
     	    if( fs::is_directory(dir) )
     	    {    
     		boost_foreach( const fs::path& pth, dir_range(dir) )
-    		    o_lst.push_back(pth.filename());
+    		    o_lst.push_back(pth.filename().string());
     	    }
     	}
     	std::sort(o_lst.begin(), o_lst.end(), &ByExtName);
