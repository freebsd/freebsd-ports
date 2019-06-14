--- cmake/cppgen.cmake.orig	2018-05-18 10:32:48 UTC
+++ cmake/cppgen.cmake
@@ -1,4 +1,4 @@
-set(VENV_DIR "${CMAKE_CURRENT_BINARY_DIR}/msgpack-venv")
+set(VENV_DIR "${CMAKE_CURRENT_BINARY_DIR}/msgpack")
 set(REQUIREMENTS "${CMAKE_SOURCE_DIR}/python/requirements.txt")
 
 if(WIN32)
@@ -6,20 +6,20 @@ if(WIN32)
   set(PYEXE "${VENV_DIR}/Scripts/python.exe")
   set(SIX_LOC "${VENV_DIR}/Lib/site-packages/six.py")
 else()
-  set(BASEPYEXE python3)
-  set(PYEXE "${VENV_DIR}/bin/python3")
-  set(SIX_LOC "${VENV_DIR}/lib/site-packages/six.py")
+  set(BASEPYEXE ${FREEBSD_PYTHON_EXENAME})
+  set(PYEXE "${FREEBSD_PYTHON_CMD}")
+  set(SIX_LOC "${FREEBSD_PYTHON_SITELIBDIR}/six.py")
 endif()
 
-add_custom_command(
-    OUTPUT ${PYEXE}
-    COMMAND ${BASEPYEXE} -m venv ${VENV_DIR}
-)
+#add_custom_command(
+#    OUTPUT ${PYEXE}
+#    COMMAND ${BASEPYEXE} -m venv ${VENV_DIR}
+#)
 
-add_custom_command(
-    OUTPUT ${SIX_LOC}
-    COMMAND ${PYEXE} -m pip install -r ${REQUIREMENTS}
-    DEPENDS ${PYEXE}
-)
+#add_custom_command(
+#    OUTPUT ${SIX_LOC}
+#    COMMAND ${PYEXE} -m pip install -r ${REQUIREMENTS}
+#    DEPENDS ${PYEXE}
+#)
 
 add_custom_target(cpp_python_gen DEPENDS ${SIX_LOC})
