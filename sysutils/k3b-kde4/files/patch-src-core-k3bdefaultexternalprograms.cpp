--- src/core/k3bdefaultexternalprograms.cpp.orig	Fri Sep 26 14:04:36 2003
+++ src/core/k3bdefaultexternalprograms.cpp	Fri Nov  7 12:35:44 2003
@@ -28,7 +28,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <stdlib.h>
-
+#include "k3bprocess.h"
 
 
 void K3b::addDefaultPrograms( K3bExternalBinManager* m )
@@ -89,7 +89,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   OutputCollector out( &vp );
 
   vp << path << "-version";
@@ -128,7 +128,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   out.setProcess( &fp );
   fp << path << "-help";
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -200,7 +200,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   OutputCollector out( &vp );
 
   vp << path << "-version";
@@ -229,7 +229,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   out.setProcess( &fp );
   fp << path << "-help";
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -285,7 +285,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path << "-version";
   OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -313,7 +313,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   fp << path << "-help";
   out.setProcess( &fp );
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -374,7 +374,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path << "-version";
   OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -402,7 +402,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   fp << path << "-help";
   out.setProcess( &fp );
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -462,7 +462,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path ;
   OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -490,7 +490,7 @@
 
 
   // probe features
-  KProcess fp;
+  MyKProcess fp;
   fp << path << "write" << "-h";
   out.setProcess( &fp );
   if( fp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -554,7 +554,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path ;
   OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -604,7 +604,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path;
   OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -631,7 +631,7 @@
     return false;
   }
 
-  KProcess cp;
+  MyKProcess cp;
   cp << path;
   out.setProcess( &cp );
   if( cp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -694,7 +694,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   vp << path << "-V";
   OutputCollector out( &vp );
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
@@ -751,7 +751,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   OutputCollector out( &vp );
 
   vp << path << "--version";
@@ -810,7 +810,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   OutputCollector out( &vp );
 
   vp << path << "-version";
@@ -879,7 +879,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   OutputCollector out( &vp );
 
   vp << path;
@@ -952,7 +952,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   OutputCollector out( &vp );
 
   vp << path << "-h";
