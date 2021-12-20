--- cmake/python.cmake.orig	2021-12-14 20:57:53 UTC
+++ cmake/python.cmake
@@ -23,7 +23,7 @@ if(UNIX AND NOT APPLE)
 endif()
 
 # Find Python 3
-find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)
+find_package(Python3 ${FREEBSD_PYTHON_VER} REQUIRED EXACT COMPONENTS Interpreter Development.Module)
 list(APPEND CMAKE_SWIG_FLAGS "-py3" "-DPY3")
 
 # Find if the python module is available,
@@ -294,9 +294,9 @@ if(BUILD_TESTING)
     #COMMAND ${VENV_EXECUTABLE} ${VENV_DIR}
     # Must NOT call it in a folder containing the setup.py otherwise pip call it
     # (i.e. "python setup.py bdist") while we want to consume the wheel package
-    COMMAND ${VENV_Python3_EXECUTABLE} -m pip install --find-links=${CMAKE_CURRENT_BINARY_DIR}/python/dist ${PYTHON_PROJECT}
+    COMMAND ${VENV_Python3_EXECUTABLE} -m pip install --no-index --find-links=${CMAKE_CURRENT_BINARY_DIR}/python/dist ${PYTHON_PROJECT}
     # install modules only required to run examples
-    COMMAND ${VENV_Python3_EXECUTABLE} -m pip install pandas matplotlib
+    #COMMAND ${VENV_Python3_EXECUTABLE} -m pip install pandas matplotlib
     BYPRODUCTS ${VENV_DIR}
     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
     COMMENT "Create venv and install ${PYTHON_PROJECT}"
