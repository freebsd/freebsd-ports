--- ./verify.sh.orig	2010-05-18 19:15:11.000000000 +0200
+++ ./verify.sh	2010-08-10 21:50:20.000000000 +0200
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 #
 # dradis Framework dependencies verification script
 #
@@ -121,7 +121,7 @@
 
 # verify SQLite3 libraries
 echo -n "Looking for SQLite3 libraries... "
-ruby -rmkmf -e "if (have_header( 'sqlite3.h' ) && have_library( 'sqlite3', 'sqlite3_open' )) then exit 0 else exit 1 end" > /dev/null
+ruby -C /usr/local/include -rmkmf -e "if (have_header( 'sqlite3.h' ) && have_library( 'sqlite3', 'sqlite3_open' )) then exit 0 else exit 1 end" > /dev/null
 if [ $? -eq 0 ]; then
   echo "found."
 else
