--- src/3rdparty/chromium/third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -284,7 +284,7 @@ bool EditingBehavior::ShouldInsertCharacter(const Keyb
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
