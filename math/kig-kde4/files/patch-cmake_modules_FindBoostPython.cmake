Requiring Boost::Python in the libraries means that the test for the header
file links to that library -- which in turn needs Python libraryes. Those
have not been searched for, yet, so the header search fails with linker
errors. The Python libraries are searched for later in this module.

--- cmake/modules/FindBoostPython.cmake.orig	2018-03-11 22:44:22 UTC
+++ cmake/modules/FindBoostPython.cmake
@@ -36,10 +36,12 @@ find_package(Boost QUIET COMPONENTS pyth
 cmake_push_check_state()
 set(CMAKE_REQUIRED_FLAGS     ${CMAKE_REQUIRED_FLAGS}     ${KDE4_ENABLE_EXCEPTIONS})
 set(CMAKE_REQUIRED_INCLUDES  ${CMAKE_REQUIRED_INCLUDES}  ${Boost_INCLUDE_DIRS})
-set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} ${Boost_PYTHON_LIBRARY})
 
 check_include_file_cxx(boost/shared_ptr.hpp HAVE_BOOST_SHARED_PTR_HPP)
 
+# Don't want to try linking with Python libraries while checking the existence of shared_ptr.hpp
+set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} ${Boost_PYTHON_LIBRARY})
+
 # This variable is not checked/used when user provide both
 # BoostPython_INCLUDE_DIRS and BoostPython_LIBRARIES, by design.
 # If user wants to speed up configure stage, he's allowed to do this.
