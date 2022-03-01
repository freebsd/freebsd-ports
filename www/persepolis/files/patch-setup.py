--- setup.py.orig	2019-09-16 20:45:38 UTC
+++ setup.py
@@ -67,14 +67,6 @@ except:
     print("Warning: python3-psutil is not installed!")
     not_installed = not_installed + 'psutil, '
 
-# youtube_dl
-try:
-    import youtube_dl
-    print('youtube-dl is found')
-except:
-    print('Warning: youtube-dl is not installed!')
-    not_installed = not_installed + 'youtube-dl, '
-
 # aria2
 answer = os.system('aria2c --version 1>/dev/null')
 if answer != 0:
@@ -82,22 +74,6 @@ if answer != 0:
     not_installed = not_installed + 'aria2c, '
 else:
     print('aria2 is found!')
-
-# libnotify-bin
-answer = os.system('notify-send --version 1>/dev/null')
-if answer != 0:
-    print("Error libnotify-bin is not installed!")
-    not_installed = not_installed + 'libnotify-bin, '
-else:
-    print('libnotify-bin is found!')
-
-# paplay
-answer = os.system('paplay --version 1>/dev/null')
-if answer != 0:
-    print("Warning: paplay not installed!You need pulseaudio for sound notifications!")
-    not_installed = not_installed + 'paplay, '
-else:
-    print('paplay is found!')
 
 # sound-theme-freedesktop
 if os_type == 'Linux':
