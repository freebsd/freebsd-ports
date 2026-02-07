--- xdrawchem.pro.orig	2024-11-15 16:56:22 UTC
+++ xdrawchem.pro
@@ -3,7 +3,7 @@ isEmpty(PREFIX) {
 
 # set PREFIX if not set (it is set when building RPM)
 isEmpty(PREFIX) {
-PREFIX = /usr/local
+PREFIX = %%LOCALBASE%%
 }
 
 DESTDIR = bin
