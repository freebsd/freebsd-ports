--- src/core/k3bdefaultexternalprograms.cpp.orig	Mon Mar 22 18:13:21 2004
+++ src/core/k3bdefaultexternalprograms.cpp	Tue May 11 22:57:03 2004
@@ -30,6 +30,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <stdlib.h>
+#include "k3bprocess.h"
 
 
 
@@ -123,7 +124,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "-version";
@@ -162,7 +163,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   out.setProcess( &fp );
   fp << path << "-help";
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -236,7 +237,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "-version";
@@ -265,7 +266,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   out.setProcess( &fp );
   fp << path << "-help";
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -321,7 +322,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path << "-version";
   K3bProcess::OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -349,7 +350,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   fp << path << "-help";
   out.setProcess( &fp );
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -410,7 +411,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path << "-version";
   K3bProcess::OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -438,7 +439,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   fp << path << "-help";
   out.setProcess( &fp );
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -498,7 +499,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path ;
   K3bProcess::OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -530,7 +531,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   fp << path << "write" << "-h";
   out.setProcess( &fp );
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -599,7 +600,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path ;
   K3bProcess::OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -653,7 +654,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path << "-V";
   K3bProcess::OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -710,7 +711,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "--version";
@@ -769,7 +770,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "-version";
@@ -838,7 +839,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path;
@@ -911,7 +912,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "-h";
