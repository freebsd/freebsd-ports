--- quodlibet/player/gstbe/util.py.orig	2020-10-15 13:54:35 UTC
+++ quodlibet/player/gstbe/util.py
@@ -28,14 +28,9 @@ def pulse_is_running():
         element.set_state(Gst.State.NULL)
         return res != Gst.StateChangeReturn.FAILURE
 
-    # In case we don't have it call the pulseaudio binary
-    try:
-        subprocess.check_call(["pulseaudio", "--check"])
-    except subprocess.CalledProcessError:
-        return False
-    except OSError:
-        return False
-    return True
+    # NOTE: Don't check with 'pulseaudio --check' because it can't guarantee
+    #       Gstreamer works with PA (e.g., when 'pulsesink' not installed).
+    return False
 
 
 def link_many(elements):
