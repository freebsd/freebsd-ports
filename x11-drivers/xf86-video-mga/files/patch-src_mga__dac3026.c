# Fix a style warning
#
--- src/mga_dac3026.c.orig	2017-01-17 22:40:29 UTC
+++ src/mga_dac3026.c
@@ -886,8 +886,8 @@ MGA3026LoadCursorImage(
     outTi3026dreg(TVP3026_WADR_PAL, 0x00); 
 
     while(i--) {
-	while (INREG8(0x1FDA) & 0x01);
-	while (!(INREG8(0x1FDA) & 0x01));
+	while (INREG8(0x1FDA) & 0x01) {}
+	while (!(INREG8(0x1FDA) & 0x01)) {}
         outTi3026dreg(TVP3026_CUR_RAM, *(src++));    
     }
 }
