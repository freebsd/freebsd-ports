--- nifti/cifti/afni_xml.h.orig	2015-11-06 21:25:14 UTC
+++ nifti/cifti/afni_xml.h
@@ -5,6 +5,7 @@
 #define AXML_MAX_ELEN  128   /* maximum element length */
 
 #include <stdio.h>
+#include <inttypes.h>
 
 /* ----------------------------------------------------------------------
    This code is for generic reading of xml into structures.
