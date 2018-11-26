false no longer implicitly converts via integer. Return empty recipe.

--- src/beerxmlreader.cpp.orig	2018-11-26 11:43:40 UTC
+++ src/beerxmlreader.cpp
@@ -254,7 +254,7 @@ Recipe BeerXmlReader::readSingleRecipe()
     }
     if (hasError()) {
         raiseError("Problem reading recipe");
-        return false;
+        return Recipe(0);
     }
 
     // set grain use according to recipe type
