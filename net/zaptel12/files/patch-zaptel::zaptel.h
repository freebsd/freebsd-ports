
$FreeBSD$

--- zaptel/zaptel.h.orig
+++ zaptel/zaptel.h
@@ -34,9 +34,9 @@
 #if !defined(_ZAPTEL_H)
 #define _ZAPTEL_H
 
+#ifdef _KERNEL
 #include "os.h"
 
-#ifdef _KERNEL
 #include <sys/select.h>
 #include <sys/param.h>
 
