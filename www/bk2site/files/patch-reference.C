--- reference.C~	Tue Sep  3 01:02:48 2002
+++ reference.C	Tue Sep  3 01:04:14 2002
@@ -1189,7 +1189,7 @@
 
     The hard work is done by FolderCommentParser
 */
-void referenceTree::fixCommentCommands(const string parentFolderHTML = ""){
+void referenceTree::fixCommentCommands(const string parentFolderHTML){
   for (vector<reference>::iterator i = contents.begin(); i != contents.end(); ++i){
     reference& r = *i;
     replaceAll(r.comment,"&lt;","<");
@@ -1398,7 +1398,7 @@
     returns the number of elements added.
     Only adds URLS that are not Private and not Aliasof another one and
     are not under avoidFolder. */
-void referenceTree::makeVector(vector<reference> & vr, const string & avoidFolder = "")
+void referenceTree::makeVector(vector<reference> & vr, const string & avoidFolder)
 {
   for (vector<reference>::iterator i = contents.begin(); i != contents.end(); ++i){
     reference & r = *i;
@@ -1466,10 +1466,10 @@
 void referenceTree::createSiteH(const string varValues[], vector<reference> & allReferences,
                                 channelContainer & channels,
                                 fileView & baseView, fileView & otherView,
-                                vector<reference> & newsItems, int depth = 0, 
-                                string navigateBar = "", string searchNavBar = "",
-                                string parentTitle = "", string folderTitle="",
-                                string filePath = "") {
+                                vector<reference> & newsItems, int depth, 
+                                string navigateBar, string searchNavBar,
+                                string parentTitle, string folderTitle,
+                                string filePath ) {
   string ofileName;
   fileView & fv = baseView;
   string fileContents;
