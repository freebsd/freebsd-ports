--- src/audio_out/audio_arts_out.c	2003/12/20 19:51:48	1.24
+++ src/audio_out/audio_arts_out.c	2004/02/15 19:29:47	1.25
@@ -17,7 +17,7 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
  *
- * $Id: audio_arts_out.c,v 1.24 2003/12/20 19:51:48 manfredtremmel Exp $
+ * $Id: audio_arts_out.c,v 1.25 2004/02/15 19:29:47 mroi Exp $
  */
 
 #ifndef __sun			/* _XOPEN_SOURCE causes build prob's on sunos */
@@ -227,7 +227,10 @@
   arts_driver_t *this = (arts_driver_t *) this_gen;
   
   ao_arts_close(this_gen);
+  /* FIXME: arts_free() freezes on BSD, so don't use it there */
+#if !defined(__OpenBSD__) && !defined (__FreeBSD__) && !defined(__NetBSD__)
   arts_free();
+#endif
 
   free (this);
 }
