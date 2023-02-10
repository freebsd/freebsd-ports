--- src/3rdparty/chromium/third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -280,7 +280,7 @@ bool EditingBehavior::ShouldInsertCharacter(const Keyb
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
