From 01fbf99748f536519605087d5937761790fc6ded Mon Sep 17 00:00:00 2001
From: Micah Cowan <micah@cowan.name>
Date: Thu, 07 Aug 2008 08:27:12 +0000
Subject: Set termios' VERASE to DEL, for vte's autodetect feature.

---
diff --git a/src/tty.sh b/src/tty.sh
index b16ff03..374bb97 100644
--- tty.sh
+++ tty.sh
@@ -562,7 +562,9 @@ XIF{VDISCARD}	np->tio.c_cc[VDISCARD] = VDISABLE;
 XIF{VLNEXT}	np->tio.c_cc[VLNEXT] = VDISABLE;
 XIF{VSTATUS}	np->tio.c_cc[VSTATUS] = VDISABLE;
 XIF{VSUSP}	np->tio.c_cc[VSUSP] = VDISABLE;
-XIF{VERASE}	np->tio.c_cc[VERASE] = VDISABLE;
+ /* Set VERASE to DEL, rather than VDISABLE, to avoid libvte
+    "autodetect" issues. */
+XIF{VERASE}	np->tio.c_cc[VERASE] = 0x7f;
 XIF{VKILL}	np->tio.c_cc[VKILL] = VDISABLE;
 # ifdef HPUX_LTCHARS_HACK
   np->m_ltchars.t_suspc  = VDISABLE;
--
cgit v0.8.2
