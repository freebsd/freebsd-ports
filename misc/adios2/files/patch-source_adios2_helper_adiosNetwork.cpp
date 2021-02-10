- workaround for https://github.com/ornladios/ADIOS2/issues/2615

--- source/adios2/helper/adiosNetwork.cpp.orig	2021-02-10 18:38:17 UTC
+++ source/adios2/helper/adiosNetwork.cpp
@@ -23,6 +23,7 @@
 #include <string.h>    //AvailableIpAddresses() strncp
 #include <sys/ioctl.h> //AvailableIpAddresses() ioctl
 #include <unistd.h>    //AvailableIpAddresses() close
+#include <netinet/in.h>
 
 #include <nlohmann/json.hpp>
 
