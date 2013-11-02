--- ./src/bulk_extractor.cpp.orig	2013-09-04 17:58:01.000000000 +0000
+++ ./src/bulk_extractor.cpp	2013-10-19 13:09:32.000000000 +0000
@@ -1042,9 +1042,9 @@
             feature_recorder *fr = fs.get_name(params.at(1));
             const std::string &cmd = params.at(2);
             if(fr){
-                if(cmd=="window") fr->set_context_window(stoi(it->second));
-                if(cmd=="window_before") fr->set_context_window_before(stoi(it->second));
-                if(cmd=="window_after") fr->set_context_window_after(stoi(it->second));
+                if(cmd=="window") fr->set_context_window(be13stoi(it->second));
+                if(cmd=="window_before") fr->set_context_window_before(be13stoi(it->second));
+                if(cmd=="window_after") fr->set_context_window_after(be13stoi(it->second));
             }
         }
         /* See if there is a scanner? */
