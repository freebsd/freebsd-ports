--- ./Setup.hs.orig	2012-02-07 08:27:09.000000000 +0100
+++ ./Setup.hs	2012-02-15 09:35:23.000000000 +0100
@@ -56,7 +56,7 @@
         wx_cfg_parms = if os == "mingw32"
                        then [ "--unicode", "--libs", "gl,stc", "--cppflags" ]
                        else [ "--libs", "std,gl,stc,xrc,richtext,aui,media", "--cppflags" ]
-    wx  <- fmap parseWxConfig (readProcess "wx-config" wx_cfg_parms "")
+    wx  <- fmap parseWxConfig (readProcess "wxgtk2u-2.8-config" wx_cfg_parms "")
     lbi <- confHook simpleUserHooks (pkg0, pbi) flags
 
     let lpd   = localPkgDescr lbi
