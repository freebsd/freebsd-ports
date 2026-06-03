--- src/numsa/version.f90.orig	2025-03-12 09:02:29 UTC
+++ src/numsa/version.f90
@@ -24,10 +24,10 @@ module numsa_version
 
 
    !> String representation of the numsa version
-   character(len=*), parameter :: numsa_version_string = "0.1.0"
+   character(len=*), parameter :: numsa_version_string = "0.2.0"
 
    !> Numeric representation of the numsa version
-   integer, parameter :: numsa_version_compact(3) = [0, 1, 0]
+   integer, parameter :: numsa_version_compact(3) = [0, 2, 0]
 
 
 contains
