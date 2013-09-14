--- ./clients/respotify/respotify.py.orig	2013-08-08 08:45:21.000000000 +0200
+++ ./clients/respotify/respotify.py	2013-09-14 22:32:17.000000000 +0200
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
@@ -115,10 +117,14 @@
 
 
 def command_album(*args):
-    if args[0][0] == "" or current_playlist is None:
+    if len(*args) == 0 or args[0][0] == "" or current_playlist is None:
+        return
+
+    try:
+        index = int(args[0][0])-1
+    except:
         return
 
-    index = int(args[0][0])-1
     if current_playlist.getNumTracks() < index:
         return
 
@@ -127,10 +133,14 @@
 
 
 def command_artist(*args):
-    if args[0][0] == "" or current_playlist is None:
+    if len(*args) == 0 or args[0][0] == "" or current_playlist is None:
+        return
+
+    try:
+        index = int(args[0][0])-1
+    except:
         return
 
-    index = int(args[0][0])-1
     if current_playlist.getNumTracks() < index:
         return
 
@@ -278,7 +288,7 @@
     if spotify.logged_in():
         os.system("kill `pgrep -f respotify-helper` &> /dev/null")
         uri_resolver = subprocess.Popen([sys.executable, "respotify-helper.py",
-                                        args.username, args.password])
+                                        args.username, args.password], env={"PATH": "%%PREFIX%%/bin"})
         with client:
             client.connect(host="localhost", port="6600")
         Thread(target=heartbeat_handler).start()
