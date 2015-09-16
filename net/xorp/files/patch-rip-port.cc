--- rip/port.cc.orig	2012-01-11 17:56:10 UTC
+++ rip/port.cc
@@ -44,16 +44,6 @@
 #include "output_updates.hh"
 
 // ----------------------------------------------------------------------------
-// Utilities
-
-inline static uint32_t
-range_random(uint32_t lo, uint32_t hi)
-{
-    if (hi < lo) swap(hi, lo);
-    return lo + ( xorp_random() % (hi - lo) );
-}
-
-// ----------------------------------------------------------------------------
 // Address Family specific Port methods
 
 #ifdef INSTANTIATE_IPV4
