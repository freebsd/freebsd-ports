--- /dev/null	Sun Sep 25 11:15:00 2005
+++ src/lib/ewl_private.h	Mon Sep  5 22:20:30 2005
@@ -0,0 +1,49 @@
+#ifndef _EWL_PRIVATE_H
+#define _EWL_PRIVATE_H
+
+#include <Ecore_Config.h>
+#include <Ecore_File.h>
+#include <Edje.h>
+
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <limits.h>
+#include <ctype.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <unistd.h>
+#include <math.h>
+#include <assert.h>
+#include <time.h>
+#include <regex.h>
+
+#ifdef HAVE_CONFIG_H
+#include "ewl-config.h"
+#endif
+
+#ifdef HAVE_EVAS_ENGINE_FB_H
+#include <Ecore_Fb.h>
+#include <Evas_Engine_FB.h>
+#endif
+
+#ifdef HAVE_EVAS_ENGINE_GL_X11_H
+#include <Evas_Engine_GL_X11.h>
+#endif
+
+#ifdef HAVE_EVAS_ENGINE_SOFTWARE_X11_H
+#include <Ecore_X.h>
+#include <Evas_Engine_Software_X11.h>
+#endif
+
+#ifndef PATH_MAX
+#define PATH_MAX 4096
+#endif
+
+#if HAVE___ATTRIBUTE__
+#define __UNUSED__ __attribute__((unused))
+#else
+#define __UNUSED__
+#endif
+
+#endif
