--- src/vde_switch/fstp.c.orig  2021-02-23 10:19:12 UTC
+++ src/vde_switch/fstp.c
@@ -30,6 +30,7 @@ static int numports;
 #ifdef FSTP
 #include <fstp.h>
 /*********************** sending macro used by FSTP & Core ******************/
+static
 void inline ltonstring(unsigned long l,unsigned char *s) {
        s[3]=l; l>>=8;
        s[2]=l; l>>=8;
@@ -37,6 +38,7 @@ void inline ltonstring(unsigned long l,unsigned char *
        s[0]=l;
 }

+static
 unsigned long inline nstringtol(unsigned char *s) {
        return (s[0]<<24)+(s[1]<<16)+(s[2]<<8)+s[3];
 }
