--- include/lbann/comm_nb_request.hpp.orig	2023-11-08 01:08:28 UTC
+++ include/lbann/comm_nb_request.hpp
@@ -27,6 +27,7 @@
 #ifndef LBANN_COMM_NB_REQUEST_HPP_INCLUDED
 #define LBANN_COMM_NB_REQUEST_HPP_INCLUDED
 
+#include <mpi.h>
 #include "lbann_config.hpp"
 
 #ifdef LBANN_HAS_ALUMINUM
