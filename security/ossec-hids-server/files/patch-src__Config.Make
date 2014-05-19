--- ./src/Config.Make.orig	2013-10-29 12:13:44.000000000 -0600
+++ ./src/Config.Make	2014-04-21 19:52:35.000000000 -0600
@@ -7,7 +7,7 @@
 include ${PT}LOCATION
 include ${PT}Config.OS
 
-
+CC?=cc
 CFLAGS = -g -Wall -I${PT} -I${PT}headers ${CPATH} ${CEXTRA} ${DEXTRA} ${EEXTRA} ${FEXTRA} ${GEXTRA} ${HEXTRA} ${CGEOIP} -DARGV0=\"${NAME}\" -DXML_VAR=\"var\" -DOSSECHIDS
 
 SOURCES = *.c
