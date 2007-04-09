--- gcu/formula.cc.orig	Thu Feb  9 13:24:54 2006
+++ gcu/formula.cc	Mon Mar 20 18:17:25 2006
@@ -31,6 +31,19 @@
 #include <glib/gi18n.h>
 #include <sstream>
 
+/* XXX Implement strndup for FreeBSD. */
+static char *
+strndup(const char *str, size_t len) {
+    char *ret;
+
+    if ((str == NULL || len < 0)) return(NULL);
+    ret = (char *)malloc(len + 1);
+    if (ret == NULL) return(NULL);
+    strncpy(ret, str, len);
+    ret[len] = '\0';
+    return(ret);
+}
+
 using namespace gcu;
 
 parse_error::parse_error(const string& __arg, int start, int length)
@@ -448,7 +461,7 @@
 			atom_weight = Element::GetElement ((*i).first)->GetWeight (atom_prec);
 			if (atom_prec == 0)
 				m_Artificial = true;
-			delta += pow10 (-atom_prec) * (*i).second;
+			delta += pow (10.0, -atom_prec) * (*i).second;
 			m_Weight += atom_weight * (*i).second;
 		}
 		m_WeightPrec = (int) ceil (-log10 (delta) - 1e-5);
