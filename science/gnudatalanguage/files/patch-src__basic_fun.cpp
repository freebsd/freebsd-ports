--- ./src/basic_fun.cpp.orig	2014-04-08 16:53:53.916118121 +0200
+++ ./src/basic_fun.cpp	2014-04-08 16:53:54.109117445 +0200
@@ -6412,7 +6412,7 @@
       while (p < e) 
       {
         // scheme = 1*[ lowalpha | digit | "+" | "-" | "." ]
-        if (!isalpha(*p) && !isdigit(*p) && *p != '+' && *p != '.' && *p != '-') 
+        if (!std::isalpha(*p) && !std::isdigit(*p) && *p != '+' && *p != '.' && *p != '-') 
         {
           if (e + 1 < ue) goto parse_port;
           else goto just_path;
