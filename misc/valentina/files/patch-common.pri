--- common.pri.orig	2018-08-11 23:09:01 UTC
+++ common.pri
@@ -164,11 +164,11 @@ defineTest(forceCopyToDestdir) {
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
