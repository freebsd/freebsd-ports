From c24ec771cf991b9a2db8a087222460cbc04d9387 Mon Sep 17 00:00:00 2001
From: Tyler Cipriani <tyler@tylercipriani.com>
Date: Fri, 9 Jan 2015 21:58:57 -0700
Subject: [PATCH] Update inheritagents for GnuPG v.2.1+

$GPG_AGENT_INFO doesn't exist as of GnuPG 2.1.0.

From c1b33e953fabd657e6b323f5b0b307de6b37a4aa Mon Sep 17 00:00:00 2001
From: Daniel Robbins <drobbins@funtoo.org>
Date: Wed, 18 Mar 2015 19:06:49 -0600
Subject: [PATCH] FL-1999: Typo fix for inheritagents GPG patch.

From 4e62e8bb41b6deabe2038ff9688801c6e0be1c91 Mon Sep 17 00:00:00 2001
From: Bryan Drewery <bryan@shatow.net>
Date: Wed, 1 Apr 2015 16:13:58 -0500
Subject: [PATCH] Use findpids() function to fix on non-GNU ps(1).

--- keychain.sh.orig	2010-05-07 17:24:14 UTC
+++ keychain.sh
@@ -369,6 +369,10 @@ inheritagents() {
             if [ -n "$GPG_AGENT_INFO" ]; then
                 inherit_gpg_agent_info="$GPG_AGENT_INFO"
                 inherit_gpg_agent_pid=`echo "$GPG_AGENT_INFO" | cut -f2 -d:`
+            # GnuPG v.2.1+ removes $GPG_AGENT_INFO
+            elif [ -S "${GNUPGHOME:=$HOME/.gnupg}/S.gpg-agent" ]; then
+                inherit_gpg_agent_pid=$(findpids gpg)
+                inherit_gpg_agent_info="$GNUPGHOME/S.gpg-agent:${inherit_gpg_agent_pid}:1"
             fi
         fi
     fi
