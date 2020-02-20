--- fetchmailconf.py.orig	2020-01-31 20:22:54 UTC
+++ fetchmailconf.py
@@ -2132,10 +2132,6 @@ def copy_instance(toclass, fromdict):
 
 if __name__ == '__main__':
 
-    if "DISPLAY" not in os.environ:
-        print("fetchmailconf must be run under X")
-        sys.exit(1)
-
     fetchmail_icon = """
 R0lGODdhPAAoAPcAAP///wgICBAQEISEhIyMjJSUlKWlpa2trbW1tcbGxs7Ozufn5+/v7//39yEY
 GNa9tUoxKZyEe1o5KTEQAN7OxpyMhIRjUvfn3pxSKYQ5EO/Wxv/WvWtSQrVzSmtCKWspAMatnP/e
@@ -2202,6 +2198,10 @@ fetchmailconf comes with ABSOLUTELY NO WARRANTY.  This
 welcome to redistribute it under certain conditions.  Please see the file
 COPYING in the source or documentation directory for details.""")
             sys.exit(0)
+
+    if "DISPLAY" not in os.environ:
+        print("fetchmailconf must be run under X")
+        sys.exit(1)
 
     # Get client host's FQDN
     hostname = socket.gethostname()
