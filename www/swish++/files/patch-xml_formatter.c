--- xml_formatter.c.orig
+++ xml_formatter.c
@@ -144,7 +144,7 @@
 //
 // SYNOPSIS
 //
-	void xml_formatter::result( int rank, file_info const &fi ) const
+	void xml_formatter::result( int my_rank, file_info const &fi ) const
 //
 // DESCRIPTION
 //
@@ -153,14 +153,14 @@
 //
 // PARAMETERS
 //
-//	rank	The rank (1-100) of the result.
+//	my_rank	The rank (1-100) of the result.
 //
 //	fi	The search result's file information.
 //
 //*****************************************************************************
 {
 	out_ <<	"    <File>\n"
-		"      <Rank>" << rank << "</Rank>\n"
+		"      <Rank>" << my_rank << "</Rank>\n"
 		"      <Path>"
 	     <<	directories[ fi.dir_index() ] << '/' << fi.file_name()
 	     <<			"</Path>\n"
