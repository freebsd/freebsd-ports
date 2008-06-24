--- modules/visualization/galaktos/PCM.c.orig	2008-06-24 00:46:12.000000000 +0200
+++ modules/visualization/galaktos/PCM.c	2008-06-24 00:46:31.000000000 +0200
@@ -32,6 +32,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+#include <inttypes>
 
 double **PCMd;    //data structure to store PCM data  PCM[channels][maxsamples]
 int maxsamples;   //size of PCM buffer
