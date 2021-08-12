From 9f1d1f4fbd0804695a976beb191f2c49a2739834 Mon Sep 17 00:00:00 2001
From: "Sergey G. Brester" <serg.brester@sebres.de>
Date: Mon, 8 Feb 2021 17:35:59 +0100
Subject: [PATCH] amend for `Mapping` (jails)

---
 fail2ban/server/jails.py | 5 ++++-
 1 file changed, 4 insertions(+), 1 deletion(-)

diff --git fail2ban/server/jails.py fail2ban/server/jails.py
index 972a8c4b..27e12ddf 100644
--- fail2ban/server/jails.py
+++ fail2ban/server/jails.py
@@ -22,7 +22,10 @@ __copyright__ = "Copyright (c) 2004 Cyril Jaquier, 2013- Yaroslav Halchenko"
 __license__ = "GPL"
 
 from threading import Lock
-from collections import Mapping
+try:
+	from collections.abc import Mapping
+except ImportError:
+	from collections import Mapping
 
 from ..exceptions import DuplicateJailException, UnknownJailException
 from .jail import Jail
-- 
2.32.0

