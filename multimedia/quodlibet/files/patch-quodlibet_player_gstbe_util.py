--- quodlibet/player/gstbe/util.py.orig	2025-05-31 14:50:33 UTC
+++ quodlibet/player/gstbe/util.py
@@ -55,14 +55,9 @@ def pulse_is_running():
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
 
 
 def jack_is_running() -> bool:
