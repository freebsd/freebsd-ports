--- libdev/mp.c.orig	Wed Oct  8 18:48:49 2003
+++ libdev/mp.c	Wed Oct  8 18:49:55 2003
@@ -217,7 +217,7 @@
  switch(cp[ka_num]->type) {
  case T_DATECS:
     printf(devmsg(31, "установите ключ в положение \"ВИКЛ\"\
-и нажмите клавишу 9.\n
+и нажмите клавишу 9.\n\
 На индикаторе должно высветиться OFF-ln\n"));
     break;
  case T_ERA:
