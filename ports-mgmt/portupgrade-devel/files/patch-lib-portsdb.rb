Index: lib/portsdb.rb
===================================================================
RCS file: /cvsroot/portupgrade/pkgtools/lib/portsdb.rb,v
retrieving revision 1.9.2.2
retrieving revision 1.9.2.3
diff -u -r1.9.2.2 -r1.9.2.3
--- lib/portsdb.rb	24 Feb 2007 12:32:11 -0000	1.9.2.2
+++ lib/portsdb.rb	26 Feb 2007 12:12:27 -0000	1.9.2.3
@@ -25,7 +25,7 @@
 # OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 # SUCH DAMAGE.
 #
-# $Id: portsdb.rb,v 1.9.2.2 2007/02/24 12:32:11 sem_prg Exp $
+# $Id: portsdb.rb,v 1.9.2.3 2007/02/26 12:12:27 sem_prg Exp $
 
 require 'singleton'
 require 'tempfile'
@@ -43,15 +43,15 @@
   DB_VERSION = [:FreeBSD, 3]
 
   LANGUAGE_SPECIFIC_CATEGORIES = {
+    "arabic"		=> "ar-",
     "chinese"		=> "zh-",
     "french"		=> "fr-",
     "german"		=> "de-",
     "hebrew"		=> "iw-",
     "hungarian"		=> "hu-",
     "japanese"		=> "ja-",
-    "polish"		=> "pl-",
-    "portuguese"	=> "pt-",
     "korean"		=> "ko-",
+    "polish"		=> "pl-",
     "portuguese"	=> "pt-",
     "russian"		=> "ru-",
     "ukrainian"		=> "uk-",
