--- setup.py.orig	2010-07-24 10:30:33.000000000 +0800
+++ setup.py	2010-08-24 21:11:15.000000000 +0800
@@ -12,10 +12,7 @@
 # See the License for the specific language governing permissions and
 # limitations under the License.
 
-try:
-  from setuptools import setup
-except ImportError:
-  from distutils.core import setup
+from distutils.core import setup
 packages =['googlecl',
            'googlecl.blogger',
            'googlecl.calendar',
