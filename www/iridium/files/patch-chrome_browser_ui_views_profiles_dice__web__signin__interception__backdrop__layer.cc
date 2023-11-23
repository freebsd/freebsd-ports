--- chrome/browser/ui/views/profiles/dice_web_signin_interception_backdrop_layer.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/ui/views/profiles/dice_web_signin_interception_backdrop_layer.cc
@@ -89,7 +89,7 @@ void DiceWebSigninInterceptionBackdropLayer::DrawDarkB
     // The dark layer should be drawn on top of this region, but it's not easily
     // accessible in code, and requires specific implementations.
     // After the 2023 refresh, this drag area no longer exists.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // On linux, the drag area is accessible through the
     // `MirroredFrameBorderInsets()` function, which crashes on non-Linux
     // platforms.
