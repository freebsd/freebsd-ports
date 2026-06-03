--
-- workaround for https://public.gitlab.polimi.it/DAER/mbdyn/-/issues/431
-- ... 1.7.3 is very old and it fails to compile: error: templates must have C++ linkage: Please make a release
--

--- libraries/libmbwrap/umfpackwrap.h.orig	2025-11-18 16:35:30 UTC
+++ libraries/libmbwrap/umfpackwrap.h
@@ -72,9 +72,9 @@
 #include <iostream>
 #include <vector>
 
-extern "C" {
+//extern "C" {
 #include <umfpack.h>
-}
+//}
 
 #include "myassert.h"
 #include "mynewmem.h"
