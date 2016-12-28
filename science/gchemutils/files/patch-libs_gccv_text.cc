--- libs/gccv/text.cc	2016/03/26 17:11:08	2017
+++ libs/gccv/text.cc	2016/10/31 07:44:34	2055
@@ -1213,7 +1213,10 @@
 	case GDK_KEY_Delete:
 	case GDK_KEY_KP_Delete: {
 		if (m_CurPos != m_StartSel) {
-			ReplaceText (empty_st, MIN (m_CurPos, m_StartSel), abs (m_CurPos - m_StartSel));
+			if (m_CurPos > m_StartSel)
+				ReplaceText (empty_st, m_StartSel, m_CurPos - m_StartSel);
+			else 
+				ReplaceText (empty_st, m_CurPos, m_StartSel - m_CurPos);
 			if (client)
 				client->TextChanged (m_CurPos);
 			break;
@@ -1233,7 +1236,10 @@
 		break;
 	case GDK_KEY_BackSpace: {
 		if (m_CurPos != m_StartSel) {
-			ReplaceText (empty_st, MIN (m_CurPos, m_StartSel), abs (m_CurPos - m_StartSel));
+			if (m_CurPos > m_StartSel)
+				ReplaceText (empty_st, m_StartSel, m_CurPos - m_StartSel);
+			else 
+				ReplaceText (empty_st, m_CurPos, m_StartSel - m_CurPos);
 			if (client)
 				client->TextChanged (m_CurPos);
 			break;
