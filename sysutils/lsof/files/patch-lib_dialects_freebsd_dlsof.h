--- lib/dialects/freebsd/dlsof.h.orig
+++ lib/dialects/freebsd/dlsof.h
@@ -43,14 +43,31 @@
 #    include <signal.h>
 #    include <unistd.h>
 
-#    if FREEBSDV >= 13000
-/* This header is a huge mess.  Please don't support EOL FreeBSD releases. */
-#        define _KERNEL 1
-#        include <sys/_lock.h>
-#        undef _KERNEL
-#    endif /* FREEBSDV>=13000 */
+/*
+ * Pull these in without _KERNEL. Using _KERNEL below is abuse
+ * in the first place, but this mitigates a bunch of new issues in
+ * FreeBSD 16. This relies on the fact that the system includes use
+ * header guards, so once they are included without _KERNEL the
+ * later (implicit/indirect) ones with _KERNEL are no-ops.
+ *
+ * Add dummy declarations for _KERNEL items that we don't actually
+ * need but get pulled in anyway.
+ */
+#    include <sys/types.h>
+#    include <sys/systm.h>
+#    include <sys/malloc.h>
+
+#    define LOCK_FILE NULL
+#    define LOCK_LINE 0
+#    define MALLOC_DECLARE(type) extern struct malloc_type type
+#    define TRUE 1
+#    define FALSE 0
+typedef struct vm_page *vm_page_t;
+
 #    define _KERNEL 1
 
+#    include <sys/event.h>
+
 #    if defined(HAS_VM_MEMATTR_T)
 /*
  * The d_mmap2_t function typedef in <sys/conf.h> may need the definition
@@ -147,6 +164,7 @@ int getmntinfo(struct statfs **, int);
 #    include <netinet/ip.h>
 #    include <net/route.h>
 #    define _WANT_INPCB /* for FreeBSD 12 and above */
+#    include <sys/ck.h>
 #    include <netinet/in_pcb.h>
 #    include <netinet/ip_var.h>
 #    include <netinet/tcp.h>
