--- hald/freebsd/hf-usb2.h.orig	2009-02-18 00:22:59.000000000 -0500
+++ hald/freebsd/hf-usb2.h	2009-02-18 00:22:54.000000000 -0500
@@ -0,0 +1,37 @@
+/***************************************************************************
+ * CVSID: $Id$
+ *
+ * hf-usb.h : USB support
+ *
+ * Copyright (C) 2009 Joe Marcus Clarke <marcus@FreeBSD.org>
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
+#ifndef _HF_USB2_H
+#define _HF_USB2_H
+
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
+#include "hf-osspec.h"
+#include "hf-devd.h"
+
+extern HFHandler hf_usb2_handler;
+extern HFDevdHandler hf_usb2_devd_handler;
+
+#endif /* _HF_USB2_H */
