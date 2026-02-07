--- prnt/hpcups/HPCupsFilter.cpp.orig	2022-02-23 07:41:04 UTC
+++ prnt/hpcups/HPCupsFilter.cpp
@@ -754,7 +754,7 @@ int HPCupsFilter::processRasterData(cups_raster_t *cup
                 createTempFile(szFileName, &cfp);
                 if (cfp)
                 {
-                    chmod (szFileName, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
+                    chmod (szFileName, S_IRUSR | S_IWUSR | S_IRGRP | 0 | S_IROTH);
                 }
             }
 
@@ -765,7 +765,7 @@ int HPCupsFilter::processRasterData(cups_raster_t *cup
                 createTempFile(szFileName, &kfp);
                 if (kfp)
                 {
-                    chmod (szFileName, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
+                    chmod (szFileName, S_IRUSR | S_IWUSR | S_IRGRP | 0 | S_IROTH);
                 }
             }
 
