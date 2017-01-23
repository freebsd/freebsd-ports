From 9f67408e4f078e907fbf4feb45cfdcfd0cdebcca Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Wed, 9 Jan 2013 22:03:29 -0500
Subject: Remove #include "mibstore.h"

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/apm.h b/src/apm.h
index a3c06f8..365e5e2 100644
--- src/apm.h	2012-07-17 04:52:01 UTC
+++ src/apm.h
@@ -33,9 +33,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 /* I2C support */
 #include "xf86i2c.h"
 
-- 
cgit v0.10.2

