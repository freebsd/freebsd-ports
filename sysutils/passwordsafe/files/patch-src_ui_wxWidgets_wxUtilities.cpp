From b5c12954802f733cbef5a83b1b2d07b8fde8a6b0 Mon Sep 17 00:00:00 2001
From: Bernard Spil <Sp1l@users.noreply.github.com>
Date: Sun, 19 Nov 2017 20:53:11 +0100
Subject: [PATCH] Unbreak build on FreeBSD

The function wxLinuxDistributionInfo is only available on Linux. Add check for LINUX symbol as per [documentation](http://docs.wxwidgets.org/3.0/group__group__funcmacro__networkuseros.html#ga06f6fb212c396bd20865ee4e2f69aa1f)
`This function is Linux-specific and is only available when the LINUX symbol is defined. `
--- src/ui/wxWidgets/wxUtilities.cpp.orig	2020-10-28 19:48:24 UTC
+++ src/ui/wxWidgets/wxUtilities.cpp
@@ -203,7 +203,7 @@ int pless(int* first, int* second) { return *first - *
 // on Fedora or Ubuntu
 bool IsTaskBarIconAvailable()
 {
-#if defined(__WXGTK__)
+#if defined(__WXGTK__) && defined(LINUX)
   const wxVersionInfo verInfo = wxGetLibraryVersionInfo();
   int major = verInfo.GetMajor();
   int minor = verInfo.GetMinor();
