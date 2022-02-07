--- src/core/kernel/qcoreapplication.cpp.orig	2022-02-17 22:23:09 UTC
+++ src/core/kernel/qcoreapplication.cpp
@@ -1653,6 +1653,8 @@ QStringList QCoreApplication::libraryPaths()
                app_libpaths->append(canonicalPath);
             }
          }
+      } else { // Bung in the #defined default, which comes from CMake
+          QString canonicalPath = QDir(CS_DEFAULT_PLUGINPATH).canonicalPath();  if (! canonicalPath.isEmpty() && !app_libpaths->contains(canonicalPath)) app_libpaths->append(CS_DEFAULT_PLUGINPATH);
       }
    }
 
