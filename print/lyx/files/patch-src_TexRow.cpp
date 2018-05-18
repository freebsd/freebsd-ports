Fixes the build on 10.4 with clang 3.4.1.

    TexRow.cpp:271:6: error: return type 'const TexRow::TextEntry' must match previous return type 'TexRow::TextEntry' when lambda expression has unspecified explicit return type
                                            return text_none;
                                            ^
    TexRow.cpp:273:3: error: return type 'const TexRow::TextEntry' must match previous return type 'TexRow::TextEntry' when lambda expression has unspecified explicit return type
                    return text_none;
                    ^
    TexRow.cpp:288:6: error: return type 'lyx::TexRow::TextEntry' must match previous return type 'const TexRow::TextEntry' when lambda expression has unspecified explicit return type
                                            return last_pos;
                                            ^
    TexRow.cpp:290:6: error: return type 'struct TextEntry' must match previous return type 'const TexRow::TextEntry' when lambda expression has unspecified explicit return type
                                            return entry.text;
                                            ^
    TexRow.cpp:293:3: error: return type 'lyx::TexRow::TextEntry' must match previous return type 'const TexRow::TextEntry' when lambda expression has unspecified explicit return type
                    return last_pos;
                    ^

Not upstreamable, this seems to be a workaround for a compiler bug.
--- src/TexRow.cpp.orig	2018-02-25 00:11:18 UTC
+++ src/TexRow.cpp
@@ -260,7 +260,7 @@ TexRow::getEntriesFromRow(int const row) const
 		return {text_none, text_none};
 
 	// find the start entry
-	TextEntry const start = [&]() {
+	TextEntry const start = [&]() -> TextEntry const {
 		for (size_t j = i; j > 0; --j) {
 			if (!isNone(rowlist_[j].getTextEntry()))
 				return rowlist_[j].getTextEntry();
@@ -274,7 +274,7 @@ TexRow::getEntriesFromRow(int const row) const
 	} ();
 
 	// find the end entry
-	TextEntry end = [&]() {
+	TextEntry end = [&]() -> TextEntry const {
 		if (isNone(start))
 			return text_none;
 		// select up to the last position of the starting paragraph as a
