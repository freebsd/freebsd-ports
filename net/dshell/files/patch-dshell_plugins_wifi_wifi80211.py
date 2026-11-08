Description: Use pypacker 6's FTYPE_MGMT/FTYPE_CTRL/FTYPE_DATA frame type
  names in the 802.11 plugin.
Issue ID: https://github.com/USArmyResearchLab/Dshell/pull/154
Changeset: none
TODO: Submit upstream; drop once a release includes the fix.

--- dshell/plugins/wifi/wifi80211.py.orig	2024-05-01 16:29:33 UTC
+++ dshell/plugins/wifi/wifi80211.py
@@ -9,20 +9,20 @@ TYPE_KEYS = {
 
 # Create a dictionary of string representations of frame types
 TYPE_KEYS = {
-    ieee80211.MGMT_TYPE: "MGMT",
-    ieee80211.CTL_TYPE: "CTRL",
-    ieee80211.DATA_TYPE: "DATA"
+    ieee80211.FTYPE_MGMT: "MGMT",
+    ieee80211.FTYPE_CTRL: "CTRL",
+    ieee80211.FTYPE_DATA: "DATA"
 }
 
 # Create a dictionary of subtype keys from constants defined in ieee80211
 # Its keys will be tuple pairs of (TYPE, SUBTYPE)
 SUBTYPE_KEYS = dict()
 # Management frame subtypes
-SUBTYPE_KEYS.update(dict(((ieee80211.MGMT_TYPE, v), k[2:]) for k, v in ieee80211.__dict__.items() if type(v) == int and k.startswith("M_")))
+SUBTYPE_KEYS.update(dict(((ieee80211.FTYPE_MGMT, v), k[2:]) for k, v in ieee80211.__dict__.items() if type(v) == int and k.startswith("M_")))
 # Control frame subtypes
-SUBTYPE_KEYS.update(dict(((ieee80211.CTL_TYPE, v), k[2:]) for k, v in ieee80211.__dict__.items() if type(v) == int and k.startswith("C_")))
+SUBTYPE_KEYS.update(dict(((ieee80211.FTYPE_CTRL, v), k[2:]) for k, v in ieee80211.__dict__.items() if type(v) == int and k.startswith("C_")))
 # Data frame subtypes
-SUBTYPE_KEYS.update(dict(((ieee80211.DATA_TYPE, v), k[2:]) for k, v in ieee80211.__dict__.items() if type(v) == int and k.startswith("D_")))
+SUBTYPE_KEYS.update(dict(((ieee80211.FTYPE_DATA, v), k[2:]) for k, v in ieee80211.__dict__.items() if type(v) == int and k.startswith("D_")))
 
 class DshellPlugin(dshell.core.PacketPlugin):
 
