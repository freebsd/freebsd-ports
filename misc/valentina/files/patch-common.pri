--- common.pri.orig	2020-10-24 09:23:35 UTC
+++ common.pri
@@ -21,7 +21,7 @@ unix{
     }
 
     # Default prefix. Use for creation install path.
-    DEFAULT_PREFIX = /usr
+    DEFAULT_PREFIX = /usr/local
 
     # Prefix for binary file.
     isEmpty(PREFIX){
@@ -222,11 +222,11 @@ defineTest(forceCopyToDestdir) {
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
