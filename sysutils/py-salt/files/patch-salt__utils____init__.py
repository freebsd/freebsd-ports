--- salt/utils/__init__.py.orig
+++ salt/utils/__init__.py
@@ -1532,20 +1532,7 @@ def is_windows():
     '''
     Simple function to return if a host is Windows or not
     '''
-    import __main__ as main
-    # This is a hack.  If a proxy minion is started by other
-    # means, e.g. a custom script that creates the minion objects
-    # then this will fail.
-    is_proxy = False
-    try:
-        if 'salt-proxy' in main.__file__:
-            is_proxy = True
-    except AttributeError:
-        pass
-    if is_proxy:
-        return False
-    else:
-        return sys.platform.startswith('win')
+    return sys.platform.startswith('win')
 
 
 def sanitize_win_path_string(winpath):
@@ -1571,15 +1558,6 @@ def is_proxy():
     TODO: Need to extend this for proxies that might run on
     other Unices
     '''
-    return not (is_linux() or is_sunos() or is_windows())
-
-
-@real_memoize
-def is_linux():
-    '''
-    Simple function to return if a host is Linux or not.
-    Note for a proxy minion, we need to return something else
-    '''
     import __main__ as main
     # This is a hack.  If a proxy minion is started by other
     # means, e.g. a custom script that creates the minion objects
@@ -1590,10 +1568,16 @@ def is_linux():
             is_proxy = True
     except AttributeError:
         pass
-    if is_proxy:
-        return False
-    else:
-        return sys.platform.startswith('linux')
+    return is_proxy
+
+
+@real_memoize
+def is_linux():
+    '''
+    Simple function to return if a host is Linux or not.
+    Note for a proxy minion, we need to return something else
+    '''
+    return sys.platform.startswith('linux')
 
 
 @real_memoize
@@ -1609,20 +1593,7 @@ def is_sunos():
     '''
     Simple function to return if host is SunOS or not
     '''
-    import __main__ as main
-    # This is a hack.  If a proxy minion is started by other
-    # means, e.g. a custom script that creates the minion objects
-    # then this will fail.
-    is_proxy = False
-    try:
-        if 'salt-proxy' in main.__file__:
-            is_proxy = True
-    except AttributeError:
-        pass
-    if is_proxy:
-        return False
-    else:
-        return sys.platform.startswith('sunos')
+    return sys.platform.startswith('sunos')
 
 
 @real_memoize
