--- src/core/k3bdefaultexternalprograms.cpp.orig	Wed Jan 21 11:20:10 2004
+++ src/core/k3bdefaultexternalprograms.cpp	Fri Feb 13 21:03:38 2004
@@ -28,6 +28,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <stdlib.h>
+#include "k3bprocess.h"
 
 
 
@@ -89,7 +90,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "-version";
@@ -128,7 +129,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   out.setProcess( &fp );
   fp << path << "-help";
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -200,7 +201,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "-version";
@@ -229,7 +230,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   out.setProcess( &fp );
   fp << path << "-help";
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -285,7 +286,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path << "-version";
   K3bProcess::OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -313,7 +314,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   fp << path << "-help";
   out.setProcess( &fp );
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -374,7 +375,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path << "-version";
   K3bProcess::OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -402,7 +403,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   fp << path << "-help";
   out.setProcess( &fp );
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -462,7 +463,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path ;
   K3bProcess::OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -490,7 +491,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   fp << path << "write" << "-h";
   out.setProcess( &fp );
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -556,7 +557,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path ;
   K3bProcess::OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -610,7 +611,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path << "-V";
   K3bProcess::OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -667,7 +668,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "--version";
@@ -726,7 +727,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "-version";
@@ -795,7 +796,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path;
@@ -868,7 +869,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "-h";
