--- src/ssh_audit/dheat.py.orig	2024-08-16 09:16:28 UTC
+++ src/ssh_audit/dheat.py
@@ -21,6 +21,7 @@
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
 """
+import errno
 import multiprocessing
 import os
 import queue
@@ -432,10 +433,10 @@ class DHEat:
                 # out.d("Creating socket (%u of %u already exist)..." % (len(socket_dict), concurrent_sockets), write_now=True)
                 ret = s.connect_ex((aconf.host, aconf.port))
                 num_attempted_connections += 1
-                if ret in [0, 115]:  # Check if connection is successful or EINPROGRESS.
+                if ret in [0, errno.EINPROGRESS]:
                     socket_dict[s] = now
                 else:
-                    out.d("connect_ex() returned: %d" % ret, write_now=True)
+                    out.d("connect_ex() returned: %s (%d)" % (os.strerror(ret), ret), write_now=True)
 
             # out.d("Calling select() on %u sockets..." % len(socket_dict), write_now=True)
             socket_list: List[socket.socket] = [*socket_dict]  # Get a list of sockets from the dictionary.
