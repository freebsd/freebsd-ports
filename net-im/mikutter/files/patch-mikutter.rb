--- mikutter.rb.orig	2013-06-12 02:55:23.699616516 +0000
+++ mikutter.rb	2013-06-12 02:58:14.554656063 +0000
@@ -11,7 +11,7 @@
 You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.
 
 =end
-mikutter_directory = File.expand_path(File.dirname(__FILE__))
+mikutter_directory = '%%RUBY_SITELIBDIR%%/mikutter'
 
 begin
   ENV['BUNDLE_GEMFILE'] = File.expand_path(File.join(File.dirname($0), "Gemfile"))
