--- cmake/python.cmake.orig	2022-11-25 09:21:54 UTC
+++ cmake/python.cmake
@@ -40,7 +40,7 @@ if(UNIX AND NOT APPLE)
 endif()
 
 # Find Python 3
-find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)
+find_package(Python3 ${FREEBSD_PYTHON_VER} REQUIRED EXACT COMPONENTS Interpreter Development.Module)
 list(APPEND CMAKE_SWIG_FLAGS "-py3" "-DPY3")
 
 # Find if the python module is available,
@@ -367,9 +367,9 @@ if(BUILD_VENV)
     # Must NOT call it in a folder containing the setup.py otherwise pip call it
     # (i.e. "python setup.py bdist") while we want to consume the wheel package
     COMMAND ${VENV_Python3_EXECUTABLE} -m pip install
-      --find-links=${CMAKE_CURRENT_BINARY_DIR}/python/dist ${PYTHON_PROJECT}==${PROJECT_VERSION}
+      --no-index --find-links=${CMAKE_CURRENT_BINARY_DIR}/python/dist ${PYTHON_PROJECT}==${PROJECT_VERSION}
     # install modules only required to run examples
-    COMMAND ${VENV_Python3_EXECUTABLE} -m pip install pandas matplotlib pytest
+    #COMMAND ${VENV_Python3_EXECUTABLE} -m pip install pandas matplotlib pytest
     BYPRODUCTS ${VENV_DIR}
     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
     COMMENT "Create venv and install ${PYTHON_PROJECT}"
