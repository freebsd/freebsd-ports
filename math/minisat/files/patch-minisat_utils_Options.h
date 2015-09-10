--- minisat/utils/Options.h.orig	2012-11-19 13:50:09 UTC
+++ minisat/utils/Options.h
@@ -282,15 +282,15 @@ class Int64Option : public Option
         if (range.begin == INT64_MIN)
             fprintf(stderr, "imin");
         else
-            fprintf(stderr, "%4"PRIi64, range.begin);
+            fprintf(stderr, "%4" PRIi64, range.begin);
 
         fprintf(stderr, " .. ");
         if (range.end == INT64_MAX)
             fprintf(stderr, "imax");
         else
-            fprintf(stderr, "%4"PRIi64, range.end);
+            fprintf(stderr, "%4" PRIi64, range.end);
 
-        fprintf(stderr, "] (default: %"PRIi64")\n", value);
+        fprintf(stderr, "] (default: %" PRIi64")\n", value);
         if (verbose){
             fprintf(stderr, "\n        %s\n", description);
             fprintf(stderr, "\n");
