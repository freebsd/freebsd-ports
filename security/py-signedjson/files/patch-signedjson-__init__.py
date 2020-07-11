Obtained from:  https://github.com/matrix-org/python-signedjson/commit/c40c83f844fee3c1c7b0c5d1508f87052334b4e5

--- signedjson/__init__.py.orig	2020-03-27 19:41:34 UTC
+++ signedjson/__init__.py
@@ -12,7 +12,10 @@
 # See the License for the specific language governing permissions and
 # limitations under the License.
 
-from importlib_metadata import version, PackageNotFoundError
+try:
+    from importlib.metadata import version, PackageNotFoundError
+except ImportError:  # pragma: nocover
+    from importlib_metadata import version, PackageNotFoundError
 
 try:
     __version__ = version(__name__)
