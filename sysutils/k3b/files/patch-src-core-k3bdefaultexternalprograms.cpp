--- src/core/k3bdefaultexternalprograms.cpp.orig	Fri May 21 19:03:21 2004
+++ src/core/k3bdefaultexternalprograms.cpp	Sat Jul 31 09:49:57 2004
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
@@ -838,14 +839,14 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path;
   if( vp.start( KProcess::Block, KProcess::AllOutput ) ) {
     // different locales make searching for the +- char difficult
     // so we simply ignore it.
-    int pos = out.output().find( QRegExp("DVD.*RW format utility") );
+    int pos = out.output().find( QRegExp("DVD.*RW.* format utility") );
     if( pos < 0 )
       return false;
 
@@ -913,7 +914,7 @@
   K3bExternalBin* bin = 0;
 
   // probe version
-  KProcess vp;
+  MyKProcess vp;
   K3bProcess::OutputCollector out( &vp );
 
   vp << path << "-h";
