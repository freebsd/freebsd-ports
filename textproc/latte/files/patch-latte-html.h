--- latte-html.h.orig	Fri Oct 22 13:02:12 1999
+++ latte-html.h	Fri Mar 19 01:17:52 2004
@@ -46,13 +46,13 @@
 
 class LatteHtml_HtmlVisitor : public Latte_Visitor {
  public:
-  LatteHtml_HtmlVisitor(ostream &out, bool close_par = 0) :
+  LatteHtml_HtmlVisitor(std::ostream &out, bool close_par = 0) :
     m_out(out), m_close_par(close_par) {}
 
   void visit_str(Latte_Str &);
 
  private:
-  ostream &m_out;
+  std::ostream &m_out;
   bool m_close_par;
 };
 
@@ -60,8 +60,8 @@
 latte_html(const char *lang,
            bool strict, bool fragment, bool no_default, bool close_par,
            unsigned long log_flags,
-           const deque<latte_string>::const_iterator &loads_begin,
-           const deque<latte_string>::const_iterator &loads_end,
-           const char *filename, istream &in, ostream &out);
+           const std::deque<latte_string>::const_iterator &loads_begin,
+           const std::deque<latte_string>::const_iterator &loads_end,
+           const char *filename, std::istream &in, std::ostream &out);
 
 #endif // LATTE_HTML_H
