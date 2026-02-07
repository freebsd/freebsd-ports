--- lib/wnhelp.c	Fri May  6 13:17:39 2005
+++ lib/wnhelp.c	Wed Dec 21 17:25:27 2005
@@ -7,4 +7,5 @@
 /* $Id: wnhelp.c,v 1.14 2005/02/01 17:03:46 wn Rel $ */
 
+#define DEFINE_LICENSE
 #include "wn.h"
 
@@ -239,5 +240,5 @@
 ";
 
-static char *nounhelps[] = {
+static const char *nounhelps[] = {
 hyper_help,
 relatives_help,
@@ -259,5 +260,5 @@
 };
 
-static char *verbhelps[] = { 
+static const char *verbhelps[] = { 
 hyper_help,
 relatives_help,
@@ -276,5 +277,5 @@
  };
 
-static char *adjhelps[] = { 
+static const char *adjhelps[] = { 
 /* SIMPTR */
 "Display synonyms and synsets related to synsets containing \n\
@@ -351,5 +352,5 @@
 };
 
-static char *advhelps[] = {
+static const char *advhelps[] = {
 /* SIMPTR */
 "Display synonyms and synsets related to synsets containing \n\
@@ -370,5 +371,5 @@
 };
 
-char **helptext[NUMPARTS + 1] = {
+const char * const *helptext[NUMPARTS + 1] = {
     NULL,  nounhelps, verbhelps, adjhelps, advhelps 
 };
