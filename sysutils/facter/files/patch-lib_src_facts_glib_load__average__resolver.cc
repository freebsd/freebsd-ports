https://bugs.gentoo.org/840116
--- lib/src/facts/glib/load_average_resolver.cc.orig	2022-07-18 15:00:22 UTC
+++ lib/src/facts/glib/load_average_resolver.cc
@@ -1,5 +1,6 @@
 #include <internal/facts/glib/load_average_resolver.hpp>
 #include <leatherman/logging/logging.hpp>
+#include <array>
 #include <cstdlib>
 
 #ifdef __sun
