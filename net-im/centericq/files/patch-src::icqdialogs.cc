--- src/icqdialogs.cc.orig	Tue Mar 16 05:59:43 2004
+++ src/icqdialogs.cc	Sat Mar 27 13:13:51 2004
@@ -33,6 +33,7 @@
 #include "ljhook.h"
 
 #include <libicq2000/userinfoconstants.h>
+#include <libicq2000/constants.h>
 
 const char *stragerange(ICQ2000::AgeRange r) {
     switch(r) {
