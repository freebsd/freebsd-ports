--- doc/doc.pri.orig	2024-03-31 17:32:44 UTC
+++ doc/doc.pri
@@ -59,7 +59,7 @@ include( ../common-installs-config.pri )
 #-----------------------------------------------------------------------------
 # Installation target setup for documentation
 #-----------------------------------------------------------------------------
-documentation.path = $${INSTALL_PREFIX}/share/doc/$${PROJECT_NAME}
+documentation.path = $${INSTALL_PREFIX}/share/doc/$${PROJECT_NAME}$${QT_MAJOR_VERSION}
 for( folder, DOC_FOLDERS ) {
     documentation.files += $${TOP_BUILD_DIR}/$${folder}
 }
