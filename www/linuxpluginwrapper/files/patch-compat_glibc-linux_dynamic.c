--- compat_glibc/linux_dynamic.c.orig	Sun Oct 17 12:45:23 2004
+++ compat_glibc/linux_dynamic.c	Sun Jan 28 22:09:17 2007
@@ -1,5 +1,5 @@
 /*-
- * Copyright (c) 2004 Norikatsu Shigemura
+ * Copyright (c) 2006 Sean Farley
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
@@ -23,38 +23,68 @@
  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  * SUCH DAMAGE.
  *
- * $Id: linux_dynamic.c,v 1.1 2004/10/17 03:45:23 nork Exp $
+ * $Id$
  */
 
 #include "pluginwrapper.h"
 #include "linux.h"
-#include <stddef.h>
 #include <dlfcn.h>
-#include <string.h>
+#include <err.h>
+#include <stdlib.h>
+
+static const char LibGtk[] = "libgtk-x11-2.0.so.0";
+
+static void *libGtkHandle;
+
+/*
+ * Initialize handle to libgtk-x11-2.0.
+ */
+static void __attribute__((constructor)) init_lib(void)
+{
+	libGtkHandle = dlopen(LibGtk, RTLD_LAZY | RTLD_LOCAL);
+	if (libGtkHandle == NULL) {
+		errx(EXIT_FAILURE, "dlopen(\"%s\"):  %s", LibGtk, dlerror());
+	}
+
+	return;
+}
 
-extern unsigned int gtk_major_version;
 
 /*
- * dlsym(3)
+ * Deinitialize handle to libgtk-x11-2.0.
  */
-void *_dlsym(void *, const char *);
+static void __attribute__((constructor)) deinit_lib(void)
+{
+	if (libGtkHandle != NULL && dlclose(libGtkHandle) != 0) {
+		errx(EXIT_FAILURE, "dlclose(%p):  %s", libGtkHandle, dlerror());
+	}
+
+	return;
+}
+
 
+/*
+ * dlsym(3) using dlfunc(3) to avoid difficulty of locating original dlsym().
+ */
 void *
 dlsym(void *handle, const char *symbol)
 {
-	void	*ret;
-
-	if(  handle == NULL && strcmp(symbol, "gtk_major_version") == 0  )  {
-		ret = &gtk_major_version;
-		dprintf("gtk_major_version = %d", gtk_major_version);
-	}  else  {
-		ret = _dlsym(handle, symbol);
-	}
+	void *sym;
 
-	dprintf("dlsym(handle='%s', symbol='%s') = %p", handle, symbol, ret);
-	if(  ret == NULL  )  {
-		dprintf("dlerror=%s", dlerror());
+	/* Find desired symbol. */
+	sym = dlfunc(handle, symbol);
+	if (sym == NULL) {
+		dprintf("dlfunc(%p, %s):  %s", handle, symbol, dlerror());
+
+		/* Attempt another search using libgtk-x11-2.0. */
+		if (handle == NULL) {
+			sym = dlfunc(libGtkHandle, symbol);
+			if (sym == NULL)
+				dprintf("dlfunc(%p, %s):  %s", handle, symbol,
+				    dlerror());
+		}
 	}
+	dprintf("dlsym(%p, %s) = %p", handle, symbol, sym);
 
-	return ret;
+	return (sym);
 }
