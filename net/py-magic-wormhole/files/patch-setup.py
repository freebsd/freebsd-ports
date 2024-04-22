--- setup.py.orig	2024-04-04 12:47:00 UTC
+++ setup.py
@@ -36,7 +36,6 @@ setup(name="magic-wormhole",
                 "wormhole.test",
                 "wormhole.test.dilate",
                 ],
-      data_files=[(".", ["wormhole_complete.bash", "wormhole_complete.zsh", "wormhole_complete.fish"])],
       entry_points={
           "console_scripts":
           [
