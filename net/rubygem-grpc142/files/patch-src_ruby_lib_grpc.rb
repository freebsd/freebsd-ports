--- src/ruby/lib/grpc.rb.orig	2020-09-23 17:48:57 UTC
+++ src/ruby/lib/grpc.rb
@@ -12,7 +12,7 @@
 # See the License for the specific language governing permissions and
 # limitations under the License.
 
-ssl_roots_path = File.expand_path('../../../../etc/roots.pem', __FILE__)
+ssl_roots_path = '%%LOCALBASE%%/etc/ssl/cert.pem'
 
 require_relative 'grpc/errors'
 require_relative 'grpc/structs'
