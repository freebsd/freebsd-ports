--- cmake/python.cmake.orig	2021-10-01 03:13:58 UTC
+++ cmake/python.cmake
@@ -23,7 +23,7 @@ if(UNIX AND NOT APPLE)
 endif()
 
 # Find Python 3
-find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)
+find_package(Python3 ${FREEBSD_PYTHON_VER} REQUIRED EXACT COMPONENTS Interpreter Development.Module)
 list(APPEND CMAKE_SWIG_FLAGS "-py3" "-DPY3")
 
 # Find if python module MODULE_NAME is available,
@@ -214,7 +214,7 @@ if(BUILD_TESTING)
     COMMAND ${VENV_EXECUTABLE} ${VENV_DIR}
     # Must not call it in a folder containing the setup.py otherwise pip call it
     # (i.e. "python setup.py bdist") while we want to consume the wheel package
-    COMMAND ${VENV_Python3_EXECUTABLE} -m pip install --find-links=${CMAKE_CURRENT_BINARY_DIR}/python/dist ${PROJECT_NAME}
+    COMMAND ${VENV_Python3_EXECUTABLE} -m pip install --no-index --find-links=${CMAKE_CURRENT_BINARY_DIR}/python/dist ${PROJECT_NAME}
     COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/test.py.in ${VENV_DIR}/test.py
     BYPRODUCTS ${VENV_DIR}
     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} VERBATIM)
