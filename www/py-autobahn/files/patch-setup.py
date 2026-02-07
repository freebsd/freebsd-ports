--- setup.py.orig	2022-03-10 14:28:18 UTC
+++ setup.py
@@ -312,23 +312,3 @@ setup(
                  "Topic :: Software Development :: Object Brokering"],
     keywords='autobahn crossbar websocket realtime rfc6455 wamp rpc pubsub twisted asyncio xbr data-markets blockchain ethereum'
 )
-
-
-# regenerate Twisted plugin cache
-try:
-    from twisted.internet import reactor
-    print("Twisted found (default reactor is {0})".format(reactor.__class__))
-except ImportError:
-    # the user doesn't have Twisted, so skip
-    pass
-else:
-    # Make Twisted regenerate the dropin.cache, if possible. This is necessary
-    # because in a site-wide install, dropin.cache cannot be rewritten by
-    # normal users.
-    try:
-        from twisted.plugin import IPlugin, getPlugins
-        list(getPlugins(IPlugin))
-    except Exception as e:
-        print("Failed to update Twisted plugin cache: {0}".format(e))
-    else:
-        print("Twisted dropin.cache regenerated.")
