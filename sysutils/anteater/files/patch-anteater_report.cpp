
$FreeBSD$

--- anteater/report.cpp.orig	Thu May 24 19:43:41 2001
+++ anteater/report.cpp	Tue Nov  5 13:20:12 2002
@@ -132,7 +132,7 @@
 }
 
 void Report::addCol( const int colSize, const colTyp_e colTyp, const colAlign_e colAlign,
- const std::string &colTitle, const colStyle_e colStyle, const unsigned long colFlags = 0 )
+ const std::string &colTitle, const colStyle_e colStyle, const unsigned long colFlags)
 {
 	if( Type == TABLE )
 	{
