--- cmake/python.cmake.orig	2020-12-09 16:30:21 UTC
+++ cmake/python.cmake
@@ -23,7 +23,7 @@ if(UNIX AND NOT APPLE)
 endif()
 
 # Find Python
-find_package(Python REQUIRED COMPONENTS Interpreter Development)
+find_package(Python ${FREEBSD_PYTHON_VER} EXACT REQUIRED COMPONENTS Interpreter Development)
 
 if(Python_VERSION VERSION_GREATER_EQUAL 3)
   list(APPEND CMAKE_SWIG_FLAGS "-py3" "-DPY3")
@@ -206,7 +206,7 @@ if(BUILD_TESTING)
     COMMAND ${VENV_EXECUTABLE} ${VENV_DIR}
     # Must not call it in a folder containing the setup.py otherwise pip call it
     # (i.e. "python setup.py bdist") while we want to consume the wheel package
-    COMMAND ${VENV_Python_EXECUTABLE} -m pip install --find-links=${CMAKE_CURRENT_BINARY_DIR}/python/dist ${PROJECT_NAME}
+    COMMAND ${VENV_Python_EXECUTABLE} -m pip install --no-index --find-links=${CMAKE_CURRENT_BINARY_DIR}/python/dist ${PROJECT_NAME}
     COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/test.py.in ${VENV_DIR}/test.py
     BYPRODUCTS ${VENV_DIR}
     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} VERBATIM)
