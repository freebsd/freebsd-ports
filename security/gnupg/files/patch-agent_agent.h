From b3286af36d452fc801be573a057b0838d53a2edd Mon Sep 17 00:00:00 2001
From: NIIBE Yutaka <gniibe@fsij.org>
Date: Fri, 10 Jul 2015 09:21:32 +0900
Subject: [PATCH] agent: Support non-NLS build.

* agent/agent.h: Use ENABLE_NLS and define L_() macro.

--

GnuPG-bug-id: 2032

This is a fix for e76d4c05b24211f3981ab69cddb3fccc17d21e0e.
---
 agent/agent.h | 4 ++++
 1 file changed, 4 insertions(+)

diff --git agent/agent.h agent/agent.h
index 2948bff..5a09254 100644
--- agent/agent.h
+++ agent/agent.h
@@ -300,6 +300,7 @@ typedef int (*lookup_ttl_t)(const char *hexgrip);
    and uses that to translate a string according to the locale set for
    the connection.  The macro LunderscoreIMPL is used by i18n to
    actually define the inline function when needed.  */
+#ifdef ENABLE_NLS
 #define L_(a) agent_Lunderscore (ctrl, (a))
 #define LunderscorePROTO                                            \
   static inline const char *agent_Lunderscore (ctrl_t ctrl,         \
@@ -312,6 +313,9 @@ typedef int (*lookup_ttl_t)(const char *hexgrip);
     return ctrl? i18n_localegettext (ctrl->lc_messages, string) \
       /*     */: gettext (string);                              \
   }
+#else
+#define L_(a) (a)
+#endif
 
 
 /*-- gpg-agent.c --*/
-- 
2.1.4

