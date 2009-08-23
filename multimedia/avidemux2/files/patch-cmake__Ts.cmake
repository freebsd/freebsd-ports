--- ./cmake/Ts.cmake.orig	2007-10-14 13:58:28.000000000 +0200
+++ ./cmake/Ts.cmake	2008-07-10 17:16:26.000000000 +0200
@@ -14,7 +14,7 @@
 
 MACRO(FIND_LRELEASE)
     IF(NOT LRELEASE_EXECUTABLE AND NOT LRELEASE_NOT_FOUND)
-		FIND_PROGRAM(LRELEASE_EXECUTABLE lrelease PATHS
+		FIND_PROGRAM(LRELEASE_EXECUTABLE lrelease-qt4 PATHS
 			"[HKEY_CURRENT_USER\\Software\\Trolltech\\Qt3Versions\\4.0.0;InstallDir]/bin"
 			"[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\4.0.0;InstallDir]/bin"
 			$ENV{QTDIR}/bin)
@@ -63,7 +63,7 @@
                 
             SET(qm_files ${qm_files} ${_outXml} ${_out})
 
-			INSTALL(FILES ${_out} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/i18n")
+			INSTALL(FILES ${_out} DESTINATION "${CMAKE_INSTALL_PREFIX}/share/avidemux2")
         ENDFOREACH(ts_input ${ts_files})
 
         SET(${_sources} ${${_sources}} ${qm_files})
@@ -94,7 +94,7 @@
                 
             SET(qm_files ${qm_files} ${_out})
 
-			INSTALL(FILES ${_out} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/i18n")
+			INSTALL(FILES ${_out} DESTINATION "${CMAKE_INSTALL_PREFIX}/share/avidemux2")
         ENDFOREACH(ts_input ${ts_files})
 
         SET(${_sources} ${${_sources}} ${qm_files})
