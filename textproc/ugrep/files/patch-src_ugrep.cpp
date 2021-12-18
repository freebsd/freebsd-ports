--- src/ugrep.cpp.orig	2021-12-18 06:58:40 UTC
+++ src/ugrep.cpp
@@ -5717,7 +5717,7 @@ void terminal()
         // --pager: if output is to a TTY then page through the results
 
         // open a pipe to a forked pager
-        output = popen(flag_pager, "wb");
+        output = popen(flag_pager, "w");
         if (output == NULL)
           error("cannot open pipe to pager", flag_pager);
 
