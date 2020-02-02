From e1c500dd02b14285e69544ad4384d8ed6e1c5109 Mon Sep 17 00:00:00 2001
From: Ting-Wei Lan <lantw@src.gnome.org>
Date: Wed, 10 Jul 2019 21:01:14 +0800
Subject: [PATCH] Replace \+ with \{1,\}

\+ is a non-standard GNU extension recognized by GNU sed. However, it
doesn't work on FreeBSD, causing the generated hdy_init_public_types
function to be empty.

Fixes https://source.puri.sm/Librem5/libhandy/issues/135
--- src/gen-public-types.sh.orig	2019-06-12 15:30:57 UTC
+++ src/gen-public-types.sh
@@ -16,7 +16,7 @@ void
 hdy_init_public_types (void)
 {'
 
-sed -ne 's/^#define \+\(HDY_TYPE_[A-Z0-9_]\+\) \+.*/  g_type_ensure (\1);/p' "$@" | sort
+sed -ne 's/^#define \{1,\}\(HDY_TYPE_[A-Z0-9_]\{1,\}\) \{1,\}.*/  g_type_ensure (\1);/p' "$@" | sort
 
 echo '}
 '
