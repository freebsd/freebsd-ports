--- chrome/browser/shortcuts/icon_badging.cc.orig	2026-02-15 10:01:45 UTC
+++ chrome/browser/shortcuts/icon_badging.cc
@@ -58,7 +58,7 @@ enum class BadgeSize {
 constexpr ShortcutSize kSizesNeededForShortcutCreation[] = {
     ShortcutSize::k16, ShortcutSize::k32, ShortcutSize::k128,
     ShortcutSize::k256, ShortcutSize::k512};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr ShortcutSize kSizesNeededForShortcutCreation[] = {ShortcutSize::k32,
                                                             ShortcutSize::k128};
 #elif BUILDFLAG(IS_WIN)
