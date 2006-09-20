--- cherokee/handler_cgi_base.c.orig	Wed Sep 20 21:17:09 2006
+++ cherokee/handler_cgi_base.c	Wed Sep 20 21:17:09 2006
@@ -21,6 +21,8 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  * USA
  */
+#include <stdlib.h>
+#include <limits.h>
 
 #include "common-internal.h"
 #include "handler_cgi_base.h"
@@ -578,7 +580,7 @@
 			cherokee_buffer_t tmp = CHEROKEE_BUF_INIT;
 
 			cherokee_buffer_add (&tmp, begin+16, end - (begin+16));
-			cgi->content_length = atoll (tmp.buf);
+			cgi->content_length = fr_atoll (tmp.buf);
 			cherokee_buffer_mrproper (&tmp);
 
 			cherokee_buffer_remove_chunk (buffer, begin - buffer->buf, end2 - begin);
