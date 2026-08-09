--- modules/core/src/cpp/inlinehelp.cpp.orig	2026-05-19 09:32:07 UTC
+++ modules/core/src/cpp/inlinehelp.cpp
@@ -657,7 +657,7 @@ int generate_inline_links(const std::wstring& lang, co
                     }
                     else
                     {
-                        storedPath = replaceToolboxRoot(normalizedXmlPath, toolboxBase.u8string());
+                        storedPath = replaceToolboxRoot(normalizedXmlPath, toolboxBase.string());
                     }
                     links[id] = storedPath;
                 }
