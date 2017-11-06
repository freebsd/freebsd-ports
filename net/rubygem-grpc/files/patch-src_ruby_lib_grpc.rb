--- src/ruby/lib/grpc.rb.orig	2017-06-28 17:25:39 UTC
+++ src/ruby/lib/grpc.rb
@@ -27,7 +27,7 @@
 # (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 # OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
-ssl_roots_path = File.expand_path('../../../../etc/roots.pem', __FILE__)
+ssl_roots_path = '/usr/local/etc/ssl/cert.pem'
 
 require_relative 'grpc/errors'
 require_relative 'grpc/grpc'
