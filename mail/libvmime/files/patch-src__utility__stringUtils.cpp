--- ./src/utility/stringUtils.cpp.orig	2008-10-12 02:11:24.000000000 -0700
+++ ./src/utility/stringUtils.cpp	2009-12-08 09:48:30.547226336 -0800
@@ -142,7 +142,7 @@
 	{
 		if (parserHelpers::isAscii(*i))
 		{
-			if (*i != '=' || *(i + 1) != '?') // To avoid bad behaviour...
+			if (*i != '=' || ((i + 1) != end && *(i + 1) != '?')) // To avoid bad behaviour...
 				++count;
 		}
 	}
