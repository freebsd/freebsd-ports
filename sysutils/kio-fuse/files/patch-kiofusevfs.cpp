--- kiofusevfs.cpp.orig	2020-02-04 12:37:00 UTC
+++ kiofusevfs.cpp
@@ -43,6 +43,8 @@
 #include "debug.h"
 #include "kiofusevfs.h"
 
+#include <boost/cerrno.hpp>
+
 // Flags that don't exist on FreeBSD; since these are used as
 // bit(masks), setting them to 0 effectively means they're always unset.
 #ifndef O_NOATIME
