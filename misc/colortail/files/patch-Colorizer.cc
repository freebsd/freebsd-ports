
$FreeBSD$

--- Colorizer.cc.orig	Wed Aug  4 04:41:17 1999
+++ Colorizer.cc	Thu Feb  5 19:49:47 2004
@@ -23,7 +23,7 @@
 
 #include <assert.h>
 #include <stdio.h>
-#include <strstream.h>
+#include <strstream>
 
 
 Colorizer::Colorizer()
@@ -111,7 +111,7 @@
    ListIterator<SearchData*> itr(*m_items_list);
 
    // will contain the new string
-   ostrstream newstr;
+   std::ostrstream newstr;
    
    SearchData *current;
    int i = 0;
@@ -172,7 +172,7 @@
 	    }
 
 	    // write ansi reset str and a newline
-	    newstr << ANSI_RESET_STR << endl << ends;
+	    newstr << ANSI_RESET_STR << std::endl << std::ends;
 	    // return the new string
 	    return newstr.str();
 	 }
@@ -187,12 +187,12 @@
       // check if str ends in '\n'
       if (str[strlen(str)] == '\n')
       {
-	 newstr << str << ends;
+	 newstr << str << std::ends;
       }
       else
       {
 	 // doesn't end in '\n'
-	 newstr << str << endl << ends;
+	 newstr << str << std::endl << std::ends;
       }
 
       // return the new string
@@ -240,7 +240,7 @@
       
       // write newline and null
       //newstr << endl << ends;
-      newstr << ends;
+      newstr << std::ends;
       
       
       // return the new string
