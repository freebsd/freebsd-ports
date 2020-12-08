--- cmake/FindSIP.cmake.orig	2020-10-11 05:01:30 UTC
+++ cmake/FindSIP.cmake
@@ -68,16 +68,26 @@ endif()
 
 get_filename_component(_python_binary_path ${Python3_EXECUTABLE} DIRECTORY)
 
-find_program(SIP_EXECUTABLE sip
+find_program(SIP_EXECUTABLE sip5
     HINTS ${CMAKE_PREFIX_PATH}/bin ${CMAKE_INSTALL_PATH}/bin ${_python_binary_path} ${Python3_SITELIB}/PyQt5
 )
 
+execute_process(                                            
+  COMMAND sip-module --sip-h --target-dir ${CMAKE_BINARY_DIR} PyQt5.sip
+  RESULT_VARIABLE _process_status                                    
+  OUTPUT_VARIABLE _process_output                             
+  OUTPUT_STRIP_TRAILING_WHITESPACE                                      
+  )                                                                   
+if(NOT ${_process_status} EQUAL 0)                                        
+  message(FATAL_ERROR "Failed to get sip.h. Error: ${_process_output}")           
+endif()                                                                                       
+
 find_path(SIP_INCLUDE_DIRS sip.h
-    HINTS ${CMAKE_PREFIX_PATH}/include ${CMAKE_INSTALL_PATH}/include ${Python3_INCLUDE_DIRS} ${Python3_SITELIB}/PyQt5
+    HINTS ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH}/include ${CMAKE_INSTALL_PATH}/include ${Python3_INCLUDE_DIRS} ${Python3_SITELIB}/PyQt5
 )
 
 execute_process(
-    COMMAND ${Python3_EXECUTABLE} -c "import sip; print(sip.SIP_VERSION_STR)"
+    COMMAND ${Python3_EXECUTABLE} -c "import PyQt5.sip; print(PyQt5.sip.SIP_VERSION_STR)"
     RESULT_VARIABLE _process_status
     OUTPUT_VARIABLE _process_output
     OUTPUT_STRIP_TRAILING_WHITESPACE
