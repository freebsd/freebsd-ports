--- BitTorrent/RawServer_twisted.py.orig	Wed Oct 12 18:24:39 2005
+++ BitTorrent/RawServer_twisted.py	Wed Oct 12 18:24:59 2005
@@ -465,8 +465,6 @@
         s = SocketProxy(0, filename, True, 0, 'tcp')
         s.factory = Factory()
         
-        if s.reuse == False:
-            UnimplementedWarning("You asked for reuse to be off when binding. Sorry, I can't do that.")
 
         listening_port = reactor.listenUNIX(s.bind, s.factory)
         listening_port.listening = 1
@@ -479,8 +477,6 @@
         s = SocketProxy(port, bind, reuse, tos, 'tcp')
         s.factory = Factory()
         
-        if s.reuse == False:
-            UnimplementedWarning("You asked for reuse to be off when binding. Sorry, I can't do that.")
 
         try:        
             listening_port = reactor.listenTCP(s.port, s.factory, interface=s.bind)
@@ -499,8 +495,6 @@
         s.connection = c
         s.protocol.connection = c
 
-        if s.reuse == False:
-            UnimplementedWarning("You asked for reuse to be off when binding. Sorry, I can't do that.")
                          
         try:        
             listening_port = reactor.listenUDP(s.port, s.protocol, interface=s.bind)
@@ -565,7 +559,7 @@
         bindaddr = None
         if do_bind:
             bindaddr = self.config['bind']
-            if bindaddr and len(binadder) >= 0:
+            if bindaddr and len(bindaddr) >= 0:
                 bindaddr = (bindaddr, 0)
             else:
                 bindaddr = None
