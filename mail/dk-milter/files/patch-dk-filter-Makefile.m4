--- dk-filter/Makefile.m4.bak	Fri Apr  8 21:50:08 2005
+++ dk-filter/Makefile.m4	Sun May 22 13:07:23 2005
@@ -10,7 +10,7 @@
 dnl APPENDDEF(`confLIBDIRS', `-L/usr/local/ssl/lib ')
 
 dnl To use the asynchronous resolver library provided, enable this line:
-dnl bldPUSH_SMLIB(`ar')
+bldPUSH_SMLIB(`ar')
 
 bldPUSH_SMLIB(`dk')
 APPENDDEF(`confINCDIRS', `-I../libdk/ ')
