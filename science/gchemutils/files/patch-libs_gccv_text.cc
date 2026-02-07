--- libs/gccv/text.cc.orig	2017-02-12 09:10:09 UTC
+++ libs/gccv/text.cc
@@ -1126,7 +1126,7 @@ bool Text::OnKeyPressed (GdkEventKey *event)
 		if (event->state & GDK_CONTROL_MASK) {
 			/* move to end of word */
 			char const* s = m_Text.c_str ();
-			char *p = g_utf8_next_char (s + m_CurPos);
+			char const* p = g_utf8_next_char (s + m_CurPos);
 			while (*p && (!g_unichar_isgraph (g_utf8_get_char(p)) || g_unichar_ispunct (g_utf8_get_char(p))))
 				p = g_utf8_next_char (p);
 			while (g_unichar_isgraph (g_utf8_get_char(p)) && !g_unichar_ispunct (g_utf8_get_char(p)))
@@ -1137,7 +1137,7 @@ bool Text::OnKeyPressed (GdkEventKey *event)
 			Invalidate ();
 		} else {
 			char const* s = m_Text.c_str ();
-			char *p = g_utf8_next_char (s + m_CurPos);
+			char const* p = g_utf8_next_char (s + m_CurPos);
 			if (!p)
 				break;
 			m_CurPos = p - s;
@@ -1224,7 +1224,7 @@ bool Text::OnKeyPressed (GdkEventKey *event)
 		if (m_CurPos == m_Text.length ())
 			break;
 		char const* s = m_Text.c_str ();
-		char *p = g_utf8_next_char (s + m_CurPos);
+		char const* p = g_utf8_next_char (s + m_CurPos);
 		int new_pos = p - s;
 		ReplaceText (empty_st, m_CurPos, new_pos - m_CurPos);
 		if (client)
