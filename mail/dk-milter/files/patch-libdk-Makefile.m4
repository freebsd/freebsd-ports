--- libdk/Makefile.m4.bak	Sat Sep  4 00:39:01 2004
+++ libdk/Makefile.m4	Sun May 22 13:10:14 2005
@@ -4,9 +4,9 @@
 define(`confREQUIRE_LIBSM', `true')
 
 dnl Enable these lines to make use of the provided asynchronous resolver:
-dnl bldPUSH_SMLIB(`ar')
-dnl APPENDDEF(`confENVDEF', `-DUSE_ARLIB ')
-dnl APPENDDEF(`confINCDIRS', `-I../libar/ ')
+bldPUSH_SMLIB(`ar')
+APPENDDEF(`confENVDEF', `-DUSE_ARLIB ')
+APPENDDEF(`confINCDIRS', `-I../libar/ ')
 
 dnl Enable and edit this as appropriate for your system:
 dnl APPENDDEF(`confINCDIRS', `-I/usr/local/ssl/include ')
