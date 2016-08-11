--- libbitdht/src/bitdht/bencode.c.orig	2016-02-05 19:04:46 UTC
+++ libbitdht/src/bitdht/bencode.c
@@ -20,7 +20,6 @@
  */
 
 #include <stdio.h>
-#include <iostream>
 #include <stdlib.h> /* malloc() realloc() free() strtoll() */
 #include <string.h> /* memset() */
 #include "util/bdstring.h"
@@ -115,7 +114,7 @@ static char *_be_decode_str(const char *
         
     	if(_ret == NULL)
         {
-            std::cerr << "(EE) " << __PRETTY_FUNCTION__ << ": ERROR. cannot allocate memory for " << len+1+sizeof(sllen) << " bytes." << std::endl;
+            //std::cerr << "(EE) " << __PRETTY_FUNCTION__ << ": ERROR. cannot allocate memory for " << len+1+sizeof(sllen) << " bytes." << std::endl;
             return NULL;
         }
                          
@@ -511,7 +510,7 @@ be_node *be_create_str(const char *str)
     
     	if(_ret == NULL)
         {
-            std::cerr << "(EE) " << __PRETTY_FUNCTION__ << ": ERROR. cannot allocate memory for " << len+1+sizeof(sllen) << " bytes." << std::endl;
+            //std::cerr << "(EE) " << __PRETTY_FUNCTION__ << ": ERROR. cannot allocate memory for " << len+1+sizeof(sllen) << " bytes." << std::endl;
             return NULL;
         }
 	char *ret = NULL;
@@ -536,7 +535,7 @@ be_node *be_create_str_wlen(const char *
     
     	if(_ret == NULL)
         {
-            std::cerr << "(EE) " << __PRETTY_FUNCTION__ << ": ERROR. cannot allocate memory for " << len+1+sizeof(sllen) << " bytes." << std::endl;
+            //std::cerr << "(EE) " << __PRETTY_FUNCTION__ << ": ERROR. cannot allocate memory for " << len+1+sizeof(sllen) << " bytes." << std::endl;
             return NULL;
         }
 	char *ret = NULL;
@@ -584,7 +583,7 @@ int be_add_keypair(be_node *dict, const 
     
     	if(_ret == NULL)
         {
-            std::cerr << "(EE) " << __PRETTY_FUNCTION__ << ": ERROR. cannot allocate memory for " << len+1+sizeof(sllen) << " bytes." << std::endl;
+            //std::cerr << "(EE) " << __PRETTY_FUNCTION__ << ": ERROR. cannot allocate memory for " << len+1+sizeof(sllen) << " bytes." << std::endl;
             return 0;
         }
 	char *ret = NULL;
