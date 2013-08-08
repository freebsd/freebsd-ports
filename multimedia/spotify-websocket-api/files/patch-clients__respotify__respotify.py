--- clients/respotify/respotify.py.orig	2013-08-08 20:18:57.000000000 +0200
+++ clients/respotify/respotify.py	2013-08-09 00:15:15.000000000 +0200
@@ -278,7 +278,7 @@
     if spotify.logged_in():
         os.system("kill `pgrep -f respotify-helper` &> /dev/null")
         uri_resolver = subprocess.Popen([sys.executable, "respotify-helper.py",
-                                        args.username, args.password])
+                                        args.username, args.password], env={"PATH": "%%PREFIX%%/bin"})
         with client:
             client.connect(host="localhost", port="6600")
         Thread(target=heartbeat_handler).start()
