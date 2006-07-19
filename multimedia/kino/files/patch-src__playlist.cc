--- src/playlist.cc.orig	Mon Apr 24 07:14:21 2006
+++ src/playlist.cc	Wed Jul 19 15:25:22 2006
@@ -301,7 +301,7 @@
 	return output;
 }
 
-typedef bool ( *callback ) ( xmlNodePtr node, void *p );
+typedef bool ( *callback ) ( xmlNodePtr node, void *p, bool *freed );
 
 typedef struct
 {
@@ -340,7 +340,7 @@
     \param p pointer to MovieInfo struct
     \result true if file has been found and xml tree walk is done */
 
-static bool findFile( xmlNodePtr node, void *p )
+static bool findFile( xmlNodePtr node, void *p, bool *freed )
 {
 	MovieInfo * data = ( MovieInfo* ) p;
 
@@ -412,7 +412,7 @@
     \param p pointer to a string containing the project directory
     \result true if file has been found and xml tree walk is done */
 
-static bool fillMap( xmlNodePtr node, void *p )
+static bool fillMap( xmlNodePtr node, void *p, bool *freed )
 {
 	if ( xmlStrcmp( node->name, ( const xmlChar* ) "video" ) == 0 )
 	{
@@ -468,6 +468,7 @@
 					<< " - removing from list" << endl;
 					xmlUnlinkNode( node );
 					xmlFreeNode( node );
+					*freed = true;
 				}
 			}
 		}
@@ -489,7 +490,7 @@
     If the scene has been found in the playlist, the file name 
     and first frame number are returned in the private data. */
 
-static bool findSceneStart( xmlNodePtr node, void *p )
+static bool findSceneStart( xmlNodePtr node, void *p, bool *freed )
 {
 	int fileCount = 0;
 	MovieInfo *data = ( MovieInfo* ) p;
@@ -562,7 +563,7 @@
 }
 
 
-static bool findSceneEnd( xmlNodePtr node, void *p )
+static bool findSceneEnd( xmlNodePtr node, void *p, bool *freed )
 {
 	bool found = false;
 	xmlChar *src = NULL;
@@ -640,7 +641,7 @@
  
     \note This code requires a <video> node format that is not defined in smil. */
 
-static bool countFrames( xmlNodePtr node, void *p )
+static bool countFrames( xmlNodePtr node, void *p, bool *freed )
 {
 	if ( xmlStrcmp( node->name, ( const xmlChar* ) "video" ) == 0 )
 	{
@@ -686,7 +687,7 @@
     <video src="file.avi" clipBegin="200" clipEnd="800" \>
  
     \note This code requires a <video> node format that is not defined in smil. */
-static bool convertEli( xmlNodePtr node, void *p )
+static bool convertEli( xmlNodePtr node, void *p, bool *freed )
 {
 	if ( xmlStrcmp( node->name, ( const xmlChar* ) "video" ) == 0 )
 	{
@@ -741,10 +742,13 @@
 
 	while ( node != NULL && done == false )
 	{
-		done = ( *func ) ( node, p );
-		if ( done == false && node->xmlChildrenNode != NULL )
+		bool freed = false;
+		xmlNodePtr next = node->next;
+		done = ( *func ) ( node, p, &freed );
+		if ( done == false && freed == false
+			&& node->xmlChildrenNode != NULL )
 			done = parse( node->xmlChildrenNode, func, p );
-		node = node->next;
+		node = next;
 	}
 	return done;
 }
@@ -1724,7 +1728,7 @@
 	return true;
 }
 
-static bool relativeMap( xmlNodePtr node, void *p )
+static bool relativeMap( xmlNodePtr node, void *p, bool *freed )
 {
 	if ( xmlStrcmp( node->name, ( const xmlChar* ) "video" ) == 0 )
 	{
@@ -1922,7 +1926,7 @@
     \result true if file has been found and xml tree walk is done 
 */
 
-static bool checkIfFileUsed( xmlNodePtr node, void *p )
+static bool checkIfFileUsed( xmlNodePtr node, void *p, bool *freed )
 {
 	if ( xmlStrcmp( node->name, ( const xmlChar* ) "video" ) == 0 )
 	{
