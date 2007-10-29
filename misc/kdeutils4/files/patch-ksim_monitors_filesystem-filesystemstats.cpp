--- ksim/monitors/filesystem/filesystemstats.cpp.orig	2007-10-08 11:49:45.000000000 +0200
+++ ksim/monitors/filesystem/filesystemstats.cpp	2007-10-26 19:32:09.000000000 +0200
@@ -30,7 +30,7 @@
 #include <sys/types.h>
 #include <sys/param.h>
 
-#if defined(HAVE_SYS_STATVFS_H) && !defined(__DragonFly__)
+#ifdef HAVE_SYS_STATVFS_H
 #include <sys/statvfs.h>
 #elif defined( HAVE_SYS_STATFS_H )
 #include <sys/statfs.h>
@@ -59,12 +59,10 @@
 #include <stdio.h>
 #include <unistd.h>
 
-#if defined(HAVE_STATVFS) && !defined(__DragonFly__)
+#ifdef HAVE_STATVFS
 typedef struct statvfs ksim_statfs;
-#define ksim_getfsstat getvfsstat
 #elif defined( HAVE_STATFS ) || defined( Q_OS_FREEBSD )
 typedef struct statfs ksim_statfs;
-#define ksim_getfsstat getfsstat
 #else
 typedef struct // fall back for (possibly) non-supported systems
 {
@@ -75,7 +73,7 @@
 
 int fsystemStats( const char * file, ksim_statfs & stats )
 {
-#if defined(HAVE_STATVFS) && !defined(__DragonFly__)
+#ifdef HAVE_STATVFS
   return statvfs( file, &stats );
 #elif defined( HAVE_STATFS ) || defined( Q_OS_FREEBSD )
   return statfs( file, &stats );
@@ -164,9 +162,9 @@
 #endif
 
 #ifdef USE_FSSTAT
-  ksim_statfs sfs[32];
+  struct statfs sfs[32];
   int fs_count;
-  if ( ( fs_count = ksim_getfsstat( sfs, sizeof( sfs ), 0 ) ) != -1 )
+  if ( ( fs_count = getfsstat( sfs, sizeof( sfs ), 0 ) ) != -1 )
   {
     for ( int i = 0; i < fs_count; i++ )
     {
