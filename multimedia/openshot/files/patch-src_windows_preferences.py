--- src/windows/preferences.py.orig	2020-06-15 23:50:00 UTC
+++ src/windows/preferences.py
@@ -293,7 +293,7 @@ class Preferences(QDialog):
                                 value_list.remove(value_item)
                             elif os_platform == "Windows" and v not in ("0", "3", "4", "7"):
                                 value_list.remove(value_item)
-                            elif os_platform == "Linux" and v not in ("0", "1", "2", "6", "7"):
+                            elif (os_platform == "FreeBSD" or os_platform == "Linux") and v not in ("0", "1", "2", "6", "7"):
                                 value_list.remove(value_item)
 
                         # Remove hardware mode items which cannot decode the example video
@@ -305,6 +305,7 @@ class Preferences(QDialog):
 
                     # Replace %s dropdown values for hardware acceleration
                     if param["setting"] in ("graca_number_en", "graca_number_de"):
+                        value_list = []
                         for card_index in range(0,3):
                             # Test each graphics card, and only include valid ones
                             if card_index in self.hardware_tests_cards and self.hardware_tests_cards.get(card_index):
