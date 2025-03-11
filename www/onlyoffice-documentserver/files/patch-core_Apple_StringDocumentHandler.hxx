--- core/Apple/StringDocumentHandler.hxx.orig	2025-03-08 17:38:58.104116000 +0100
+++ core/Apple/StringDocumentHandler.hxx	2025-03-08 16:45:03.144938000 +0100
@@ -0,0 +1,51 @@
+/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
+/* writerperfect
+ * Version: MPL 2.0 / LGPLv2.1+
+ *
+ * This Source Code Form is subject to the terms of the Mozilla Public
+ * License, v. 2.0. If a copy of the MPL was not distributed with this
+ * file, You can obtain one at http://mozilla.org/MPL/2.0/.
+ *
+ * Major Contributor(s):
+ * Copyright (C) 2002-2004 William Lachance (wrlach@gmail.com)
+ * Copyright (C) 2004-2006 Fridrich Strba (fridrich.strba@bluewin.ch)
+ *
+ * For minor contributions see the git repository.
+ *
+ * Alternatively, the contents of this file may be used under the terms
+ * of the GNU Lesser General Public License Version 2.1 or later
+ * (LGPLv2.1+), in which case the provisions of the LGPLv2.1+ are
+ * applicable instead of those above.
+ *
+ * For further information visit http://libwpd.sourceforge.net
+ */
+
+#ifndef _STRING_DOCUMENT_HANDLER_H
+#define _STRING_DOCUMENT_HANDLER_H
+
+#include <libodfgen/libodfgen.hxx>
+
+class StringDocumentHandler final : public OdfDocumentHandler
+{
+public:
+	StringDocumentHandler();
+
+	char const *cstr() const
+	{
+		return m_data.cstr();
+	}
+
+	void startDocument() final {}
+	void endDocument() final;
+	void startElement(const char *psName, const librevenge::RVNGPropertyList &xPropList) final;
+	void endElement(const char *psName) final;
+	void characters(const librevenge::RVNGString &sCharacters) final;
+private:
+private:
+	librevenge::RVNGString m_data;
+	bool m_isTagOpened;
+	librevenge::RVNGString m_openedTagName;
+};
+#endif
+
+/* vim:set shiftwidth=4 softtabstop=4 noexpandtab: */
