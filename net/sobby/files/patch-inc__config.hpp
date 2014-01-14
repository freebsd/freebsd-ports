--- inc/config.hpp.orig
+++ inc/config.hpp
@@ -30,6 +30,30 @@
 #include <libxml++/nodes/element.h>
 #include <libxml++/nodes/textnode.h>
 
+namespace serialise
+{
+
+template<>
+class default_context_to<Glib::ustring>: public context_base_to<Glib::ustring>
+{
+public:
+	typedef Glib::ustring data_type;
+
+	virtual std::string to_string(const data_type& from) const;
+};
+
+template<>
+class default_context_from<Glib::ustring>:
+	public context_base_from<Glib::ustring>
+{
+public:
+	typedef Glib::ustring data_type;
+
+	virtual data_type from_string(const std::string& from) const;
+};
+
+} // namespace serialise
+
 namespace Sobby
 {
 
@@ -434,28 +458,4 @@
 
 } // namespace Sobby
 
-namespace serialise
-{
-
-template<>
-class default_context_to<Glib::ustring>: public context_base_to<Glib::ustring>
-{
-public:
-	typedef Glib::ustring data_type;
-
-	virtual std::string to_string(const data_type& from) const;
-};
-
-template<>
-class default_context_from<Glib::ustring>:
-	public context_base_from<Glib::ustring>
-{
-public:
-	typedef Glib::ustring data_type;
-
-	virtual data_type from_string(const std::string& from) const;
-};
-
-} // namespace serialise
-
 #endif // _SOBBY_CONFIG_HPP_
