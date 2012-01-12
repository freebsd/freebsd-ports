Index: src/insets/InsetTabular.cpp
===================================================================
--- src/insets/InsetTabular.cpp	(revision 39812)
+++ src/insets/InsetTabular.cpp	(revision 39813)
@@ -188,62 +188,6 @@
 };
 
 
-template <class T>
-string const write_attribute(string const & name, T const & t)
-{
-	string const s = tostr(t);
-	return s.empty() ? s : " " + name + "=\"" + s + "\"";
-}
-
-template <>
-string const write_attribute(string const & name, string const & t)
-{
-	return t.empty() ? t : " " + name + "=\"" + t + "\"";
-}
-
-
-template <>
-string const write_attribute(string const & name, docstring const & t)
-{
-	return t.empty() ? string() : " " + name + "=\"" + to_utf8(t) + "\"";
-}
-
-
-template <>
-string const write_attribute(string const & name, bool const & b)
-{
-	// we write only true attribute values so we remove a bit of the
-	// file format bloat for tabulars.
-	return b ? write_attribute(name, convert<string>(b)) : string();
-}
-
-
-template <>
-string const write_attribute(string const & name, int const & i)
-{
-	// we write only true attribute values so we remove a bit of the
-	// file format bloat for tabulars.
-	return i ? write_attribute(name, convert<string>(i)) : string();
-}
-
-
-template <>
-string const write_attribute(string const & name, Tabular::idx_type const & i)
-{
-	// we write only true attribute values so we remove a bit of the
-	// file format bloat for tabulars.
-	return i ? write_attribute(name, convert<string>(i)) : string();
-}
-
-
-template <>
-string const write_attribute(string const & name, Length const & value)
-{
-	// we write only the value if we really have one same reson as above.
-	return value.zero() ? string() : write_attribute(name, value.asString());
-}
-
-
 string const tostr(LyXAlignment const & num)
 {
 	switch (num) {
@@ -503,6 +447,61 @@
 	}
 }
 
+template <class T>
+string const write_attribute(string const & name, T const & t)
+{
+	string const s = tostr(t);
+	return s.empty() ? s : " " + name + "=\"" + s + "\"";
+}
+
+template <>
+string const write_attribute(string const & name, string const & t)
+{
+	return t.empty() ? t : " " + name + "=\"" + t + "\"";
+}
+
+
+template <>
+string const write_attribute(string const & name, docstring const & t)
+{
+	return t.empty() ? string() : " " + name + "=\"" + to_utf8(t) + "\"";
+}
+
+
+template <>
+string const write_attribute(string const & name, bool const & b)
+{
+	// we write only true attribute values so we remove a bit of the
+	// file format bloat for tabulars.
+	return b ? write_attribute(name, convert<string>(b)) : string();
+}
+
+
+template <>
+string const write_attribute(string const & name, int const & i)
+{
+	// we write only true attribute values so we remove a bit of the
+	// file format bloat for tabulars.
+	return i ? write_attribute(name, convert<string>(i)) : string();
+}
+
+
+template <>
+string const write_attribute(string const & name, Tabular::idx_type const & i)
+{
+	// we write only true attribute values so we remove a bit of the
+	// file format bloat for tabulars.
+	return i ? write_attribute(name, convert<string>(i)) : string();
+}
+
+
+template <>
+string const write_attribute(string const & name, Length const & value)
+{
+	// we write only the value if we really have one same reson as above.
+	return value.zero() ? string() : write_attribute(name, value.asString());
+}
+
 } // namespace
 
 
