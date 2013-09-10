--- ./clients/respotify/respotify.py.orig	2013-09-10 22:10:39.000000000 +0200
+++ ./clients/respotify/respotify.py	2013-09-10 22:11:58.000000000 +0200
@@ -88,8 +88,10 @@
         print "Playlists\n"
         index = 1
         for playlist in rootlist:
-            print " ["+str(index)+"] "+playlist.getName()
-            index += 1
+            name = playlist.getName()
+            if name != None:
+                print " ["+str(index)+"] "+name
+                index += 1
     else:
         try:
             if len(rootlist) >= int(args[0][0]):
@@ -115,7 +117,7 @@
 
 
 def command_album(*args):
-    if args[0][0] == "" or current_playlist is None:
+    if len(*args) == 0 or args[0][0] == "" or current_playlist is None:
         return
 
     index = int(args[0][0])-1
@@ -127,7 +129,7 @@
 
 
 def command_artist(*args):
-    if args[0][0] == "" or current_playlist is None:
+    if len(*args) == 0 or args[0][0] == "" or current_playlist is None:
         return
 
     index = int(args[0][0])-1
@@ -278,7 +280,7 @@
     if spotify.logged_in():
         os.system("kill `pgrep -f respotify-helper` &> /dev/null")
         uri_resolver = subprocess.Popen([sys.executable, "respotify-helper.py",
-                                        args.username, args.password])
+                                        args.username, args.password], env={"PATH": "%%PREFIX%%/bin"})
         with client:
             client.connect(host="localhost", port="6600")
         Thread(target=heartbeat_handler).start()
