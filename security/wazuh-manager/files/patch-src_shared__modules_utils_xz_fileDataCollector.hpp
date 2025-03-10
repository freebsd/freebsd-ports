--- src/shared_modules/utils/xz/fileDataCollector.hpp.orig	2024-10-21 21:27:17.811078000 -0700
+++ src/shared_modules/utils/xz/fileDataCollector.hpp	2024-10-21 21:27:30.311015000 -0700
@@ -59,7 +59,7 @@
         /*! @copydoc IDataCollector::finish() */
         void finish() override
         {
-            m_file.close();
+            (m_file.close)();
         }
 
         /*! @copydoc IDataCollector::setBuffer() */
