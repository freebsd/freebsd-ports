--- libavogadro/src/extensions/symmetry/libmsym/src/orbital.c.orig	2018-10-16 20:56:21 UTC
+++ libavogadro/src/extensions/symmetry/libmsym/src/orbital.c
@@ -67,13 +67,13 @@ msym_error_t orbitalFromQuantumNumbers(i
         }
         case 2 : {
             //o->v = dpolynomial[m+l];
-            char *d = (signbit(m) == 1 ? "-" : "+");
+            char *d = (signbit((double)m) == 1 ? "-" : "+"); // signbit is misused, see https://github.com/cryos/avogadro/issues/916
             snprintf(o->name, sizeof(o->name), "%dd%d%s",n,abs(m),d);
             break;
         }
         default : {
             char t = 'f' - 3 + l;
-            char *d = (signbit(m) == 1 ? "-" : "+");
+            char *d = (signbit((double)m) == 1 ? "-" : "+"); // signbit is misused, see https://github.com/cryos/avogadro/issues/916
             snprintf(o->name, sizeof(o->name), "%d%c%d%s",n,t,abs(m),d);
         }
     }
