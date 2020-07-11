--- common.pri.orig	2020-07-11 05:51:06 UTC
+++ common.pri
@@ -209,11 +209,11 @@ defineTest(forceCopyToDestdir) {
 # We use precompiled headers for more fast compilation source code.
 defineReplace(set_PCH){
     no_ccache{
-        CONFIG += precompile_header # Turn on creation precompiled headers (PCH).
+        CONFIG -= precompile_header # Turn on creation precompiled headers (PCH).
         export(CONFIG) # export value to global variable.
 
-        PRECOMPILED_HEADER = stable.h # Header file with all all static headers: libraries, static local headers.
-        export(PRECOMPILED_HEADER) # export value to global variable
+        #PRECOMPILED_HEADER = stable.h # Header file with all all static headers: libraries, static local headers.
+        #export(PRECOMPILED_HEADER) # export value to global variable
 
         *msvc* {
             PRECOMPILED_SOURCE = stable.cpp # MSVC need also cpp file.
@@ -311,7 +311,7 @@ defineReplace(FindLatestTagDistance){
 }
 
 # Default prefix. Use for creation install path.
-DEFAULT_PREFIX = /usr
+DEFAULT_PREFIX = /usr/local
 
 # In debug mode on Unix system we use all usefull for us compilers keys for checking errors.
 # Also trying make all possible for speed up build time.
