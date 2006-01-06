--- pesstream.h.orig	Fri Jan  6 20:44:26 2006
+++ pesstream.h	Fri Jan  6 20:49:04 2006
@@ -25,7 +25,7 @@
 	private:
 		static int		m_st_nr;
 		int			m_nr;
-		enum S_TYPE		m_stype;
+		S_TYPE			m_stype;
 		class CBuffer *		mp_cbuf;
 		class xlist *		mp_list;
 
