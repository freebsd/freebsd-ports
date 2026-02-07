--- src/nuspell/finder.cxx.orig	2024-07-04 11:45:35 UTC
+++ src/nuspell/finder.cxx
@@ -94,9 +94,9 @@ auto append_default_dir_paths(vector<fs::path>& paths)
 			paths[i] /= "myspell";
 	}
 	else {
-		paths.push_back("/usr/local/share/hunspell");
+		paths.push_back("%%PREFIX%%/share/hunspell");
 		paths.push_back("/usr/share/hunspell");
-		paths.push_back("/usr/local/share/myspell");
+		paths.push_back("%%PREFIX%%/share/myspell");
 		paths.push_back("/usr/share/myspell");
 	}
 #if defined(__APPLE__) && defined(__MACH__)
