--- cmake/modules/FindBoostPython.cmake.orig	2018-01-06 04:25:23 UTC
+++ cmake/modules/FindBoostPython.cmake
@@ -36,7 +36,8 @@ find_package(Boost QUIET COMPONENTS pyth
 cmake_push_check_state()
 set(CMAKE_REQUIRED_FLAGS     ${CMAKE_REQUIRED_FLAGS}     ${KDE4_ENABLE_EXCEPTIONS})
 set(CMAKE_REQUIRED_INCLUDES  ${CMAKE_REQUIRED_INCLUDES}  ${Boost_INCLUDE_DIRS})
-set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} ${Boost_PYTHON_LIBRARY})
+# Don't mess with check_include_file_cxx
+set(CMAKE_REQUIRED_LIBRARIES "")
 
 check_include_file_cxx(boost/shared_ptr.hpp HAVE_BOOST_SHARED_PTR_HPP)
 
@@ -46,6 +47,9 @@ check_include_file_cxx(boost/shared_ptr.
 # If user wants to shoot himself in the foot, he is allowed to do this, too.
 set(BoostPython_COMPILES)
 
+# Now that the header has been found, set the libraries.
+set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} ${Boost_PYTHON_LIBRARY})
+
 # If shared_ptr.hpp or Python library is not available, then there is
 # no point to do anything.
 if(HAVE_BOOST_SHARED_PTR_HPP AND Boost_PYTHON_FOUND)
