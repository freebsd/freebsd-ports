CMake 2.8.12 fix.

http://cmake.org/gitweb?p=cmake.git;a=commitdiff;h=9ce60ff509c4ff27fe861fc5b2080f50897a68c4
changed the arguments of the internal macros QT4_EXTRACT_OPTIONS and
QT4_CREATE_MOC_COMMAND which the port uses directly, so we have to adapt.
--- cmake/jreenMacros.cmake.orig	2013-01-06 17:49:31.000000000 +0200
+++ cmake/jreenMacros.cmake	2013-11-03 19:42:41.000000000 +0200
@@ -19,7 +19,7 @@
 MACRO (JREEN_WRAP_CPP outfiles )
         # get include dirs
         QT4_GET_MOC_FLAGS(moc_flags)
-        QT4_EXTRACT_OPTIONS(moc_files moc_options ${ARGN})
+        QT4_EXTRACT_OPTIONS(moc_files moc_options moc_target ${ARGN})
 
         FOREACH (it ${moc_files})
                 GET_FILENAME_COMPONENT(_abs_FILE ${it} ABSOLUTE)
@@ -39,7 +39,7 @@
                                 FOREACH (_current_MOC_INC ${_match})
                                         STRING(REGEX MATCH "moc_[^ <\"]+\\.cpp" _current_MOC "${_current_MOC_INC}")
                                         SET(_moc    ${CMAKE_CURRENT_BINARY_DIR}/${_current_MOC})
-                                        QT4_CREATE_MOC_COMMAND(${_abs_FILE} ${_moc} "${_moc_INCS}" "")
+                                        QT4_CREATE_MOC_COMMAND(${_abs_FILE} ${_moc} "${_moc_INCS}" "" "${moc_target}")
                                         MACRO_ADD_FILE_DEPENDENCIES(${_abs_FILE} ${_moc})
                                 ENDFOREACH (_current_MOC_INC)
                         ENDIF()
@@ -47,7 +47,7 @@
                                 FOREACH (_current_MOC_INC ${_match2})
                                         STRING(REGEX MATCH "[^ <\"]+\\.moc" _current_MOC "${_current_MOC_INC}")
                                         SET(_moc    ${CMAKE_CURRENT_BINARY_DIR}/${_current_MOC})
-                                        QT4_CREATE_MOC_COMMAND(${_header} ${_moc} "${_moc_INCS}" "")
+                                        QT4_CREATE_MOC_COMMAND(${_header} ${_moc} "${_moc_INCS}" "" "${moc_target}")
                                         MACRO_ADD_FILE_DEPENDENCIES(${_header} ${_moc})
                                 ENDFOREACH (_current_MOC_INC)
                         ENDIF()
@@ -57,7 +57,7 @@
                         STRING(REGEX MATCHALL "Q_OBJECT|Q_GADGET" _match2 "${_contents}")
                         IF(_match2)
                                 QT4_MAKE_OUTPUT_FILE(${_abs_FILE} moc_ cpp outfile)
-                                QT4_CREATE_MOC_COMMAND(${_abs_FILE} ${outfile} "${moc_flags}" "${moc_options}")
+                                QT4_CREATE_MOC_COMMAND(${_abs_FILE} ${outfile} "${moc_flags}" "${moc_options}" "${moc_target}")
                                 SET(${outfiles} ${${outfiles}} ${outfile})
                         ENDIF()
                 ENDIF()
