--- src/etc/script/orphan_killer.pl	2003/11/28 18:16:39
+++ src/etc/script/orphan_killer.pl	2004/05/04 21:05:38
@@ -24,7 +24,7 @@
 # along with this program; if not, write to the Free Software
 # Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
-use lib '/home/sympa/bin';
+use lib '--LIBDIR--';
 
 use Conf;
 ## Change to your wwsympa.conf location
