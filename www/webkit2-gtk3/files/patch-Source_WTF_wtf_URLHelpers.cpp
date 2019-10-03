Regressed by https://github.com/unicode-org/icu/commit/480bec3ea652

Source/WTF/wtf/URLHelpers.cpp:301:39: error: expected ';' after do/while statement
        U16_NEXT(buffer, i, length, c)
                                      ^
                                      ;
Source/WTF/wtf/URLHelpers.cpp:303:52: error: use of undeclared identifier 'error'
        UScriptCode script = uscript_getScript(c, &error);
                                                   ^
Source/WTF/wtf/URLHelpers.cpp:304:13: error: use of undeclared identifier 'error'
        if (error != U_ZERO_ERROR) {
            ^

--- Source/WTF/wtf/URLHelpers.cpp.orig	2019-08-26 14:55:44 UTC
+++ Source/WTF/wtf/URLHelpers.cpp
@@ -298,7 +298,7 @@ static bool allCharactersInIDNScriptWhiteList(const UC
     Optional<UChar32> previousCodePoint;
     while (i < length) {
         UChar32 c;
-        U16_NEXT(buffer, i, length, c)
+        U16_NEXT(buffer, i, length, c);
         UErrorCode error = U_ZERO_ERROR;
         UScriptCode script = uscript_getScript(c, &error);
         if (error != U_ZERO_ERROR) {
