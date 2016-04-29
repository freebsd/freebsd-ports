--- src/basic_fun.cpp.orig	2016-04-29 17:03:25 UTC
+++ src/basic_fun.cpp
@@ -6523,7 +6523,7 @@ namespace lib {
 	  {
 	    // check if the data we get is a port this allows us to correctly parse things like a.com:80
 	    p = e + 1;
-	    while (isdigit(*p)) p++;
+	    while (std::isdigit(*p)) p++;
 	    if ((*p == '\0' || *p == '/') && (p - e) < 7) goto parse_port;
 	    urlstru->InitTag("SCHEME", DStringGDL(string(s, (e - s))));
 	    length -= ++e - s;
@@ -6574,7 +6574,7 @@ namespace lib {
       parse_port:
 	p = e + 1;
 	pp = p;
-	while (pp-p < 6 && isdigit(*pp)) pp++;
+	while (pp-p < 6 && std::isdigit(*pp)) pp++;
 	if (pp-p < 6 && (*pp == '/' || *pp == '\0')) 
 	  {
 	    memcpy(port_buf, p, (pp-p));
