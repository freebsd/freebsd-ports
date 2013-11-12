--- ./hald/freebsd/hf-memcard.h.orig	2013-10-22 01:49:12.608421644 +0200
+++ ./hald/freebsd/hf-memcard.h	2013-10-22 01:41:55.228962237 +0200
@@ -0,0 +1,36 @@
+/***************************************************************************
+ * CVSID: $Id$
+ *
+ * hf-memcard.h : memory card support
+ *
+ * Copyright (C) 2013 Alberto Villa <avilla@FreeBSD.org>
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; either version 2 of the License, or
+ * (at your option) any later version.
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License
+ * along with this program; if not, write to the Free Software
+ * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
+ *
+ **************************************************************************/
+
+#ifndef _HF_MEMCARD_H
+#define _HF_MEMCARD_H
+
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
+#include "../device.h"
+
+void hf_mmc_host_set_properties (HalDevice *device);
+void hf_mmc_set_properties (HalDevice *device);
+
+#endif /* _HF_MEMCARD_H */
