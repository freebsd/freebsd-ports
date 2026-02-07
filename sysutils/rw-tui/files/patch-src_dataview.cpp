--- src/dataview.cpp.orig	2023-07-30 15:32:56 UTC
+++ src/dataview.cpp
@@ -5,6 +5,9 @@
 #include "global.hpp"
 #include "utils/hex_string.hpp"
 
+#include <unistd.h>
+
+
 DataView::DataView(uint64_t address) {
   mContainer = Container::Vertical({});
   mAddress = address;
@@ -25,7 +28,7 @@ void DataView::refresh() {
 void DataView::refresh() {
   void *mapBase, *virtAddress;
   mContainer->DetachAllChildren();
-  mapBase = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,
+  mapBase = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED,
                  *gFileDescriptor, mAddress & ~MAP_MASK);
   if (mapBase == (void *)-1)
     FATAL;
