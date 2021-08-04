From 96ea7dc0507679203b07e673ebd21a0ea8d474e9 Mon Sep 17 00:00:00 2001
From: Matt McCormick <matt.mccormick@kitware.com>
Date: Wed, 4 Aug 2021 15:05:19 -0400
Subject: [PATCH] Consistent get_cpu_count for FreeBSD

---
 freebsd/cpu.cc | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/freebsd/cpu.cc b/freebsd/cpu.cc
index b85d402..4c7dddb 100644
--- freebsd/cpu.cc.orig
+++ freebsd/cpu.cc
@@ -26,12 +26,12 @@
 #include "getsysctl.h"
 #include "cpu.h"
 
-uint8_t get_cpu_count()
+uint32_t get_cpu_count()
 {
   int32_t cpu_count = 0;
   GETSYSCTL( "hw.ncpu", cpu_count );
 
-  return static_cast<uint8_t>( cpu_count );
+  return static_cast<uint32_t>( cpu_count );
 }
 
 float cpu_percentage( unsigned int cpu_usage_delay )
