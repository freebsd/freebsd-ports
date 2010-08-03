--- autogen.sh.orig	2010-06-22 21:46:11.000000000 +0200
+++ autogen.sh	2010-07-01 12:58:23.000000000 +0200
@@ -1,11 +1,11 @@
-#!/bin/bash
+#!/bin/sh
 
-function error () {
+error () {
 	echo "Error: $1" 1>&2
 	exit 1
 }
 
-function check_autotool_version () {
+check_autotool_version () {
 	which $1 &>/dev/null || {
 		error "$1 is not installed, and is required to configure $PACKAGE"
 	}
@@ -20,9 +20,9 @@
 
 	if [ $major -lt $major_check ]; then
 		do_bail=yes
-	elif [[ $minor -lt $minor_check && $major = $major_check ]]; then
+	elif [ $minor -lt $minor_check ] && [ $major = $major_check ]; then
 		do_bail=yes
-	elif [[ $rev -lt $rev_check && $minor = $minor_check && $major = $major_check ]]; then
+	elif [ $rev -lt $rev_check ] && [ $minor = $minor_check ] && [ $major = $major_check ]; then
 		do_bail=yes
 	fi
 
@@ -31,7 +31,7 @@
 	fi
 }
 
-function run () {
+run () {
 	echo "$@ ..."
 	$@ 2>.autogen.log || {
 		cat .autogen.log 1>&2
