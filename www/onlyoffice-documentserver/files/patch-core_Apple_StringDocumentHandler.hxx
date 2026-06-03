--- core/Apple/StringDocumentHandler.hxx.orig	2025-08-08 19:00:43 UTC
+++ core/Apple/StringDocumentHandler.hxx
@@ -0,0 +1,154 @@
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
+#include <string.h>
+
+
+StringDocumentHandler::StringDocumentHandler() : m_data(""), m_isTagOpened(false), m_openedTagName("")
+{
+	m_data.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
+}
+
+void StringDocumentHandler::endDocument()
+{
+	if (!m_isTagOpened) return;
+	m_data.append(">");
+	m_isTagOpened = false;
+}
+
+void StringDocumentHandler::startElement(const char *psName, const librevenge::RVNGPropertyList &xPropList)
+{
+	if (m_isTagOpened)
+	{
+		m_data.append(">");
+		m_isTagOpened = false;
+	}
+	m_data.append("<");
+	m_data.append(psName);
+	librevenge::RVNGPropertyList::Iter i(xPropList);
+	for (i.rewind(); i.next();)
+	{
+		// filter out librevenge elements
+		if (!strncmp(i.key(), "librevenge:", 11)) continue;
+
+		m_data.append(" ");
+		m_data.append(i.key());
+		m_data.append("=\"");
+		if (i()->getStr().len()>0)
+			m_data.append(i()->getStr().cstr());
+		m_data.append("\"");
+	}
+	m_isTagOpened = true;
+	m_openedTagName.sprintf("%s", psName);
+}
+void StringDocumentHandler::endElement(const char *psName)
+{
+	if (m_isTagOpened)
+	{
+		if (m_openedTagName == psName)
+		{
+			m_data.append("/>");
+			m_isTagOpened = false;
+		}
+		else // should not happen, but handle it
+		{
+			m_data.append(">");
+			m_data.append("</");
+			m_data.append(psName);
+			m_data.append(">");
+			m_isTagOpened = false;
+		}
+	}
+	else
+	{
+		m_data.append("</");
+		m_data.append(psName);
+		m_data.append(">");
+		m_isTagOpened = false;
+	}
+}
+
+void StringDocumentHandler::characters(const librevenge::RVNGString &sCharacters)
+{
+	if (m_isTagOpened)
+	{
+		m_data.append(">");
+		m_isTagOpened = false;
+	}
+	librevenge::RVNGString sEscapedCharacters;
+	sEscapedCharacters.appendEscapedXML(sCharacters);
+	if (sEscapedCharacters.len() > 0)
+		m_data.append(sEscapedCharacters.cstr());
+}
+
+/* vim:set shiftwidth=4 softtabstop=4 noexpandtab: */
