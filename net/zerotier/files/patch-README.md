--- README.md.orig	2023-09-14 19:09:26 UTC
+++ README.md
@@ -169,3 +169,23 @@ If there are other metrics you'd like to see tracked, 
 | zt_peer_packet_errors | node_id | Counter | number of incoming packet errors from a peer |
 
 If there are other metrics you'd like to see tracked, ask us in an Issue or send us a Pull Request!
+
+### HTTP / App server
+
+There is a static http file server suitable for hosting Single Page Apps at http://localhost:9993/app/<app-path>
+
+Use `zerotier-cli info -j` to find your zerotier-one service's homeDir
+
+``` sh
+cd $ZT_HOME
+sudo mkdir -p app/app1
+sudo mkdir -p app/appB
+echo '<html><meta charset=utf-8><title>appA</title><body><h1>hello world A' | sudo tee app/appA/index.html 
+echo '<html><meta charset=utf-8><title>app2</title><body><h1>hello world 2' | sudo tee app/app2/index.html 
+curl -sL http://localhost:9993/app/appA http://localhost:9993/app/app2 
+```
+
+Then visit [http://localhost:9993/app/app1/](http://localhost:9993/app/app1/) and [http://localhost:9993/app/appB/](http://localhost:9993/app/appB/)
+
+Requests to paths don't exist return the app root index.html, as is customary for SPAs. 
+If you want, you can write some javascript that talks to the service or controller [api](https://docs.zerotier.com/service/v1).
