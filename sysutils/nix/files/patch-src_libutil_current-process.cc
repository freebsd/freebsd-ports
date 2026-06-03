--- src/libutil/current-process.cc.orig	2025-09-13 18:20:31 UTC
+++ src/libutil/current-process.cc
@@ -134,6 +134,11 @@ std::optional<Path> getSelfExe()
             return std::nullopt;
         }
 
+        // error: input string '/usr/ports/sysutils/nix/work/nix-2.31.1/_build/src/nix/nix␀' cannot be represented
+        //    as Nix string because it contains null bytes
+        // So: pop the '\0' character in the string
+        path.pop_back();
+
         return Path(path.begin(), path.end());
 #else
         return std::nullopt;
