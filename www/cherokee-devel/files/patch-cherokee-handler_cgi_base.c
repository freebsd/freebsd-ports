--- cherokee/handler_cgi_base.c.orig	Fri Aug 18 15:21:03 2006
+++ cherokee/handler_cgi_base.c	Thu Nov 16 00:42:03 2006
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
+			cgi->content_length = strtoll(tmp.buf, (char **)NULL, 10);
 			cherokee_buffer_mrproper (&tmp);
 
 			cherokee_buffer_remove_chunk (buffer, begin - buffer->buf, end2 - begin);
