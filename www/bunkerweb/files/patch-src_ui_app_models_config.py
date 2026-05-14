--- src/ui/app/models/config.py.orig	2026-05-10 11:25:04 UTC
+++ src/ui/app/models/config.py
@@ -13,7 +13,7 @@ class Config:
 
 class Config:
     def __init__(self, db, data) -> None:
-        self.__settings = json_loads(Path(sep, "usr", "share", "bunkerweb", "settings.json").read_text(encoding="utf-8"))
+        self.__settings = json_loads(Path(sep, "usr", "local", "share", "bunkerweb", "common", "settings.json").read_text(encoding="utf-8"))
         self.__db = db
         self.__data = data
         self.__ignore_regex_check = getenv("IGNORE_REGEX_CHECK", "no").lower() == "yes"
